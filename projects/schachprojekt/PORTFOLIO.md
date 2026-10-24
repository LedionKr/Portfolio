# Schachprojekt · Standard- und Atomschach

[Portfolio](../../README.md) · [Projektübersicht](../README.md) · [Originaldokumentation](README.md)

Eine C++-Konsolenanwendung, die Schachstellungen verwaltet und Züge für zwei Spielmodi verarbeitet. Das Projekt zeigt einen objektorientierten Aufbau, Arbeit mit STL-Datenstrukturen und die Trennung von Brettzustand, Bewegungsprüfung und Benutzereingaben.

## Funktionsumfang

- Auswahl zwischen `Default` und `Atomchess` beim Start.
- Darstellung des Bretts als 8×8-Feld in der Konsole.
- Verarbeitung von Zügen, Schlagen und Bauernumwandlung.
- Atomschach mit einer Explosionslogik für Schlagzüge.
- Einlesen von Brettstellungen über FEN-Eingaben sowie Anzeige möglicher Züge.
- Rücknahme von Zügen mit `undo` und Speicherung der Bretthistorie.
- Zwei Google-Test-Tests mit getrennten Datensätzen für beide Spielmodi.

Dies beschreibt die vorhandene Implementierung. Der dokumentierte Prüfstand unten belegt einen Build und kurze Bedienabläufe; er bestätigt keine vollständige Abdeckung aller Schachregeln.

## Aufbau und Techstack

| Bestandteil | Aufgabe |
| --- | --- |
| [main.cpp](main.cpp) | Moduswahl, Konsoleneingaben und Befehlsverarbeitung |
| [board.h](board.h) / [board.cpp](board.cpp) | Klasse `Board`, Brettzustand, Historie, Zugausführung und Schachprüfungen |
| [Movement/movement.h](Movement/movement.h) / [movement.cpp](Movement/movement.cpp) | Figurbewegungen, Wegprüfung und Bauernumwandlung |
| [Test/tests.cpp](Test/tests.cpp) | Datengetriebene Tests `AtomicLegalMove.Move` und `LegalMove.Move` |
| [Test/TestData/](Test/TestData/) | Datensätze für Atom- und Standardschach |
| [Makefile](Makefile) / [CMakeLists.txt](CMakeLists.txt) | Build mit C++17; CMake bindet Google Test ein |
| [Dockerfile](Dockerfile) / [formal.sh](formal.sh) | Übernommene Entwicklungsumgebung und Formatierungs-/Lint-Skript |

Verwendet werden unter anderem `std::vector`, Zeichenketten und Streams. Das Brett und seine Historie liegen in der Klasse `Board`; die Bewegungsprüfung ist in eigene Dateien ausgelagert.

## Lokal bauen und starten

### Mit Make

Voraussetzungen: Make und ein als `g++` erreichbarer C++17-Compiler. Vom Portfolio-Stamm aus:

```sh
cd projects/schachprojekt
make
./projectChess
```

### Direkt mit einem C++17-Compiler

Alternativ im Projektordner, beispielsweise mit Clang:

```sh
clang++ -std=c++17 -Wall -Wextra -Wpedantic main.cpp board.cpp Movement/movement.cpp -o projectChess
./projectChess
```

Für diese Anwendung ist Google Test nicht erforderlich. Beim Start genau `Default` oder `Atomchess` eingeben. Anschließend können beispielsweise diese Befehle verwendet werden:

```text
MPa2a4
undo
```

Der erste Befehl bewegt den weißen Bauern von a2 nach a4; `undo` nimmt diesen Zug zurück. Mit `Ctrl+D` unter macOS/Linux die Eingabe beenden, alternativ mit `Ctrl+C` abbrechen.

Weitere Befehle sind `FNb1` zur Anzeige möglicher Springerzüge und der Brettimport mit `B` direkt vor der Stellung, beispielsweise:

```text
Brnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w - - 0 1
```

Die Originaldokumentation enthält an einer Stelle `F[FEN]`; maßgeblich ist hier die Implementierung in `main.cpp`, die für den Brettimport `B` verwendet.

## Tests und Prüfstand

Am **25. Oktober 2026** in der Übernahme-Arbeitskopie auf macOS/arm64 mit Apple Clang 21.0.0 geprüft:

| Prüfung | Ergebnis |
| --- | --- |
| Direkter Build mit dem oben angegebenen Clang-Befehl | Erfolgreich, keine Compilerdiagnosen mit den angegebenen Warnoptionen |
| `Default`: Startstellung → `MPa2a4` → `undo` → Eingabeende | Erfolgreich; Brett nach Zug und wiederhergestellte Startstellung geprüft, Exitcode 0 |
| `Atomchess`: gleicher Ablauf | Erfolgreich; Brett nach Zug und wiederhergestellte Startstellung geprüft, Exitcode 0 |
| Vollständige Google-Test-Suite | Nicht ausgeführt |
| Make-, CMake-, Docker- und Formatierungsabläufe | Bei der Übernahme nicht ausgeführt |

Die beiden übernommenen Google-Test-Tests verwenden absolute Pfade zur ursprünglichen Entwicklungsumgebung. Für eine lokale Ausführung müssen diese Pfade in `Test/tests.cpp` auf die mitgelieferten Dateien unter `Test/TestData/` angepasst werden. Der kopierte Testcode bleibt im Originalzustand.

Die vorhandene CMake-Konfiguration erfordert mindestens CMake 3.27 und lädt Google Test aus einer festgelegten Revision. Nach Anpassung der Testdatenpfade ist folgender Ablauf vorgesehen, wurde hier aber nicht ausgeführt:

```sh
cmake -S . -B build
cmake --build build
ctest --test-dir build --output-on-failure
```

CMake ist in der Übernahme-Prüfumgebung nicht installiert. Der Dockerfile und seine Abhängigkeiten sind ebenfalls ungeprüft. Ungültige oder unvollständige Konsoleneingaben werden im Quellstand nicht durchgehend abgesichert; für eine Vorführung die dokumentierten Befehlsformate verwenden.

## Herkunft und Umfang der Kopie

- Quelle: [LedionKr/schachprojekt](https://github.com/LedionKr/schachprojekt), Branch `main`.
- Übernommener Stand: [927b507c23fbd06a10219920ce5d41df3005ffc2](https://github.com/LedionKr/schachprojekt/commit/927b507c23fbd06a10219920ce5d41df3005ffc2).
- Übernommen: alle 14 Quell-, Dokumentations-, Build- und Testdateien außerhalb des erzeugten Build-Ordners und der Systemdatei; einschließlich der unveränderten Original-README und Testdaten.
- Ausgelassen: `cmake-build-debug/` mit erzeugten Caches, Binärdateien und heruntergeladenen Abhängigkeiten sowie `.DS_Store`.
- Ergänzt für das Portfolio: dieser Überblick und eine projektbezogene `.gitignore`.

Die Kopie ist ein festgehaltener Stand und wird nicht automatisch mit dem Quellrepository synchronisiert. Bei einer Aktualisierung Quelle und Prüfstand mitpflegen. Die Originaldokumentation bleibt erhalten; zusätzliche Angaben zu Teambeiträgen, Hilfsmitteln oder Ergebnissen werden nur anhand bestätigter Informationen ergänzt.
