# Schachspiel mit zusätzlicher Schachvariante (Atomschach)

## [Video](https://cloud.uni-konstanz.de/index.php/s/yrsFdxcCYb4cSFP)

## Informationen zum Projekt
* Das Schachbrett wird durch eine 2D-Vektorvariable repräsentiert und dargestellt. Dadurch wird
 ein Feld mit 64 Elementen ermöglicht (8x8).
* Der Spielverlauf wird ebenfalls mit Hilfe einer Vektorariable gespeichert. Jeder Move wird
 als eigenes Schachbrett auf einem Stapel gelegt.
* Zu Beginn wählt man zwischen zwei Schachvarianten aus. Diese sind das Standardschach und die
  Schachvariante "Atomschach".
* Möglich ist `move`, `capture` und `promotion`

## Board
Eine Implementierung des Schachbretts erfolgt über die `Board`-Klasse. Um das Schachbrett zu
initialisieren baue ich einen Konstruktor `Board()` und nutze ihn direkt, damit ich das Anfangslayout
in der `ChessBoard`- Variable speicher.
In der Klasse sind ich mehrere öffentliche Methoden verantwortlich für Aufgaben, die das Schachbrett
benötigen.
### Wichtige Funktionen innerhalb der Klasse:

### Check-Funktionalität
| `isKingCheck` | |
|--------|------------------------------------------------------------------------------------------------------------|
| was?   | Sucht die Positionen der beiden Könige und speichert diese ab. Anschließend sucht man das Brett nach allen Figuren. Gehört die Figur nicht dem Spieler und ist ein möglicher Zug der Figur bedrohlich für den König, so wird ein `true`-Wert zurückgegeben |
| wofür? | Es wird geschaut, ob der König im Schach steht nachdem ein Move ausgeführt oder ein Board eingelesen wurde |

### Einlesen eines Boards
| `readBoard` | |
|--------|------------------------------------------------------------------------------------------------------------|
| was?   | Liest das Schachbrett basierend auf eine FEN-Zeile ein. |
| wofür? | Es kann jede beliebige Spielsituation in das Schachbrett eingesetzt werden und es ermöglicht und vereinfacht das testen von verschiedenen Funktionalitäten |

### Legale Moves
| `arePossibleMoves` | |
|--------|------------------------------------------------------------------------------------------------------------|
| was?   | Es wird überprüft, ob für eine bestimmte Figur an einer bestimmten Position gültige Züge ausführen kann, oohne den eigenen König zu gefährden.  |
| wofür? | Testet gültige Züge, die den eigenen König nicht in Gefahr bringen. Es wird auf legale Moves getestet. |

### Zug einer Figur
| `makeMove` | |
|--------|------------------------------------------------------------------------------------------------------------|
| was?   | Führt einen Zug einer Figur von einer Position zur anderen. Der Zug wird erst nach merheren Überprüfungen ausgeführt. Es wird geprüft, wo das Board endet, ob eine Figur auf dem Zielort liegt und ob diese Figur eine eigene ist. Unteranderem wird auch getestet ob capturen möglich ist sowie die Pawnpromotion. |
| wofür? | Stellt sicher, dass der Zug legal ist. |

### Zug einer Figur (Atomschach)
| `makeAtomicMove` | |
|--------|------------------------------------------------------------------------------------------------------------|
| was?   | Im Prinzip ähnelt es der `makeMove`-Funktion. Es werden zusätzlich die Sonderregeln beachtet, wie zB die Explosion oder, dass ein König nicht capturen kann, da er sonst sich selbst ausschaltet. (Siehe `explodeSurroundings`& `kingCounter`) |
| wofür? | Stellt sicher, dass der Zug legal ist. |

### Sonderregel - Explosion
| `explodeSurroundings` | |
|--------|------------------------------------------------------------------------------------------------------------|
| was?   | Die Felder um die Figur und die Figur selber explodieren beim capturen. Ausgenommen sind Bauern, die auf den rumliegenden Feldern sich befinden |
| wofür? | Einzigartigkeit der Schachvariante. |

### Sonderregel - Eigener König darf nicht sterben
| `kingCounter` | |
|--------|------------------------------------------------------------------------------------------------------------|
| was?   | Prüft, ob im Explosionsradius sich zwei Könige befinden. |
| wofür? | Ansonsten würden beide Könige zur gleichen Zeit verlieren und man würde den eigenen König dabei schlagen. Mit dieser Funktion wird in `makeAtomicMove`jeder Zug, der dieses Szenario verursacht illegal. |



## Movement
Ich habe das Movement der Figuren seperat aufgelistet in `movement.h`. In der Datei werden die Züge der verschiedenen Figuren validiert. Beim Pawn gibt es zum Beispiel die Regelung, dass er nicht nach hinten capturen, geschweige denn laufen kann. Zu den Bewegungsmuster der Figuren wird natürlich auch geprüft, ob sich die Figur überhaupt bewegen kann. Das Pferd kann über Figuren springen, während der Turm einen freien Weg braucht, um sich von seiner Position zu bewegen. Außerdem schaue ich hier nach, ob eine Promotion möglich ist, wenn isch ein Pawn bis zum Ende des Spielfeldes bewegt.
### Wichtigste Funktion des Segments
| `ValidMovement` | |
|--------|------------------------------------------------------------------------------------------------------------|
| was?   | Verteilt die "chars" auf die Bewegungsmuster der verschieden Figuren (p -> schwarzer Pawn -> `PawnMovement`) |
| wofür? | Die chars, die auf dem Board angezeigt werden, bekommen eine Figur und eine Funtion zugeteilt. |


## Main
Die `main.cpp`ist das Herzstück in dem alle Befehlseingaben des Spielers stattfinden. Die Benutzerinteraktion fängt damit an, dass man sein gamemode auswählt. Dafür wird die Variable `atomChess` erstellt und mithilfe des Inputs ensprechen auf `true` oder `false` gesetzt.
Anschließend wird das Board gedruckt und man begibt sich in die `while`-Schleife. Nun wird auf die Eingabe des Nutzers gewartet.

Nun gibt es mehrere Benutzerinteraktionen/Anweisungen:
* `[M]` wird verwendet um einen `Move` anzugeben, der ausgeführt werden soll. Der Move hängt vom ausgewählten Modus ab. Unter der Anweisung fallen auch das capturen `x`und die promotion `=`
    * Beispiele:
    * `MPa2a4` for a move
    * `Mqb5xc4` for a capture
    * `MPa7a8=Q` for a promotion
 
* `[B]` ist das Zeichen, um das `Board` zu beeinflussen. Hier wird mit einem Fen-Code ein Schachbrett eingelesen.
* `[F]` zeigt die validen Züge der Figur auf dem aktuellen Board und capturen (falls vorhanden).
* `undo` setzt den letzten Zug zurück. Der Befehl ist beliebig oft wiederholbar, da nach jedem Move der Zustand des Schachbretts auf einem Stapel gelegt wird. Undo ist möglich, bis dieser Stapel leer ist.

Der Input für den Move oder die FEN-Code ist wie folgt:
* Move: `[ANWEISUNG][Piece][Square][Capture (wenn nötig)][MoveSquare]`
    * Bsp. `MNb1c3`
* FEN: `F[FEN]`
    * Bsp. `rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w - - 0 1` (Standard-Aufstellung)

Außerhalb der `main`-Methode befindet sich die `handleGameEnd`-Funktion, die das Spielende bahandelt. Sie überprüft, ob der König im Schach steht oder im Schachmatt ist. Basierend auf den Zustand des Königs wird das Spiel in der `while`-Schleife beendet.

## Verwendete Programmierkonzepte
### Objektorientierte Programmierung
* Die Klasse für Board
* Schachbrett wird repräsentiert und mehrere Funktionen werden verwaltet
* Kontrolle und Modifikation wurden verbessert

### Kapselung
* Die `Board`-Klasse kapselt interne Datenstrukturen und bietet Schnittstellen für erleichterte Kontolle und bessere Organisation
* Bestimmte Daten wie `ChessBoard` und `BoardHistor` sind private Mietglieder in der `Board`-Klasse und sind nur innerhalb der Klasse zugänglich

### Datenstrukturen
*  Funktionen und Methoden führen spezifische Aufgaben aus
*  Bedingte Anweisungen wie `if`, `if-else` für zB Überprüfung von Spielzügen
*  Interaktion mit dem Benutzer durch `std::cin` und `std::cout`
*  Mit `std::vector` dynamische Array erstellen für Strukturen wie das Schachbrett oder die Historie des Spieles
*  Manipulation von Zeichenketten wie beim FEN-Code oder durch `substr()` und damit parsen ermöglichen

### Asserts
* Verwendug bei tests
* Erkennung bei Nutzung des falschen Pfades
* Prüft die Gültigkeit der Moves in beiden Spielvarianten




## Libraries

Die einzige Bibliothek in diesem Projekt ist die Google Test Bibliothek ([gtest](https://github.com/google/googletest)) für
automatisierte Tests.

> Es werden absolute Pfade verwendet! Pfad muss angepasst werden!!

Die Tests können im /Test Verzeichnis gefunden werden. Neben der `tests.cpp` befinden sich auch die Daten, für die Tests

#### Test: AtomicLegalMove
Der erste Test prüft die Gültigkeit von Moves im Modus `Atomchess`
* Testdateien werden eingelesen und ausgeführt
* Es wird die Methode `makeAtomicMoves` verwendet
* Am Ende prüft man mit `ASSERT_TRUE`, ob alle Züge gultig waren


#### Test: LegalMove
Dieser Test prüft das gleiche für den Modus `Default`
* Testdateien werden eingelesen und ausgeführt
* Es wird die Methode `makeMoves` verwendet
* Am Ende prüft man mit `ASSERT_TRUE`, ob alle Züge gultig waren











