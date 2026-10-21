# Google-Layoutübung

**Statische HTML/CSS-Lernübung**

[Portfolio](../../README.md) · [Lernsammlung](../README.md) · [Quellcode](index.html)

## Ziel und Stand

Diese Übung bildet eine Suchmaschinen-Oberfläche mit Kopfbereich, Suchfeld, Schaltflächen und Footer nach. Sie dient der Beschäftigung mit HTML und CSS und ist kein offizielles Google-Produkt.

**Stand:** Lernübung mit vorhandener Implementierung. Eine Suchfunktion ist nicht angebunden: Das Formular hat weder ein Suchziel noch eine eigene Suchlogik. Ein vollständiger Funktionsumfang und durchgeführte Tests sind nicht dokumentiert.

## Techstack und Aufbau

| Bestandteil | Verwendung |
| --- | --- |
| [index.html](index.html) | Layout, Suchformular, externe Links und Audio-Element |
| [styles.css](styles.css) | Flexbox, Abstände, feste Größen und Google-Fonts-Import für Roboto |
| [pages/about.html](pages/about.html) | Separate kleine CSS-Übungsseite |
| `images/` | Vorhandene Logos, Icons und Bilder |
| `music/` | Vorhandene MP3-Datei für das Audio-Element |

Kein Build-Schritt und kein Paketmanager erforderlich. Die Schriftart wird extern geladen; eine Netzwerkverbindung ist dafür erforderlich.

## Lokal ansehen

`index.html` in diesem Ordner im Browser öffnen. Alternativ im Repository-Stamm mit installiertem Python 3:

```sh
python3 -m http.server 8000 --bind 127.0.0.1
```

Dann [http://localhost:8000/Html/Google/](http://localhost:8000/Html/Google/) öffnen. Die zusätzliche Übungsseite ist unter [pages/about.html](http://localhost:8000/Html/Google/pages/about.html) erreichbar. Mit `Ctrl+C` beenden.

## Grenzen und Prüfbedarf

- Das Suchfeld liefert keine Suchergebnisse; Sprach- und Bildsymbole haben keine entsprechende Funktion.
- Mehrere Bilder besitzen im vorhandenen HTML keine Alternativtexte.
- Feste Breiten und `min-width: 400px` erfordern eine Prüfung auf schmalen Bildschirmen.
- Browserdarstellung, Tastaturbedienung und Medienwiedergabe sind nicht durch dokumentierte Prüfungen belegt.
- Quellen und Nutzungsrechte der Logos, Bilder und Audio-Datei sind im Bestand nicht dokumentiert und vor externer Weitergabe oder Veröffentlichung zu klären.

## Eigenanteil und Weiterentwicklung

Konkreter Entstehungskontext, eigene Arbeitsschritte, verwendete Tutorials und weitere Hilfsmittel sind noch zu dokumentieren. Nächste mögliche Schritte sind eine nachvollziehbare Medienübersicht, eine Prüfung der Tastaturbedienung und eine Anpassung des Layouts für kleine Ansichten.

Dafür stehen eine [Prüfvorlage](../../projects/_vorlage/docs/pruefung.md) und eine [Reflexionsvorlage](../../projects/_vorlage/docs/reflexion.md) bereit. Vorgesehene Schritte sind noch keine umgesetzten Verbesserungen.
