# Web-Grundlagen · Lernsammlung

[Portfolio](../README.md) · [Google-Layoutübung](Google/README.md)

Dieser Ordner enthält Übungen zu Web-Grundlagen. Die Dateien zeigen einzelne Elemente und Beispiele; sie werden als Lernmaterial eingeordnet. Ein Abschluss, ein festgelegter Lernumfang oder ein produktiver Einsatz ist nicht dokumentiert.

## Inhalte

| Datei / Ordner | Inhalt | Grenzen |
| --- | --- | --- |
| [indexLernen.html](indexLernen.html) | Textauszeichnung, Listen, Tabellen, Formulare, iframe und ein JavaScript-Beispiel mit `doSomething()` und DOM-Zugriff | Einzelne Ressourcenpfade und das Formularziel fehlen im Bestand. |
| [cssLernen.html](cssLernen.html) | Beschreibung des CSS-Boxmodells mit Abbildung | Der Bildpfad verwendet Backslashes; browserübergreifende Funktion ist nicht geprüft. |
| [Google/](Google/README.md) | Statische Layoutübung mit HTML und CSS | Keine angebundene Suche; weitere Grenzen stehen in der Projekt-README. |

## Lokal ansehen

Die jeweilige HTML-Datei im Browser öffnen. Alternativ im Repository-Stamm mit installiertem Python 3:

```sh
python3 -m http.server 8000 --bind 127.0.0.1
```

Die Grundlagen sind dann unter [HTML-Beispiele](http://localhost:8000/Html/indexLernen.html) und [Boxmodell](http://localhost:8000/Html/cssLernen.html) erreichbar. Mit `Ctrl+C` beenden.

Es ist kein PHP-Backend enthalten. Das Formular mit `action="action_page.php"` ist daher kein vollständiger Datenverarbeitungsprozess. Die Seite `indexLernen.html` enthält außerdem eine automatische Aktualisierung nach 90 Sekunden. Für Übungen ausschließlich Beispieldaten verwenden.

## Lernstand nachvollziehbar ergänzen

Für eine bearbeitete Übung die Aufgabe, die eigene Änderung und die beobachtete Wirkung festhalten. Quellen und übernommene Beispiele konkret zuordnen. Persönliche Erkenntnisse werden erst ergänzt, wenn sie tatsächlich beschrieben werden können.

Die [Konzept-](../projects/_vorlage/docs/konzept.md), [Prüf-](../projects/_vorlage/docs/pruefung.md) und [Reflexionsvorlagen](../projects/_vorlage/docs/reflexion.md) können bei umfangreicheren Übungen übernommen werden. Noch offene Ressourcenpfade und weitere Befunde stehen in der [Bestandsaufnahme](../docs/bestandsaufnahme.md).
