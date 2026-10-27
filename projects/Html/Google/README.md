# Google-Layoutübung

[Portfolio](../../README.md) · [Lernsammlung](../README.md) · [Quellcode](index.html)

## Ziel und Stand

Diese Übung bildet eine Suchmaschinen-Oberfläche mit Kopfbereich, Suchfeld, Schaltflächen und Footer nach. Sie dient der Beschäftigung mit HTML und CSS und ist kein offizielles Google-Produkt.

**Stand:** Lernübung mit vorhandener Implementierung. Eine Suchfunktion ist nicht angebunden: Das Formular hat weder ein Suchziel noch eine eigene Suchlogik. Ein vollständiger Funktionsumfang und durchgeführte Tests sind nicht dokumentiert.

## Techstack und Aufbau

| Bestandteil | Verwendung |
| --- | --- |
| [index.html](index.html) | Layout, Suchformular, externe Links und Audio-Element |
| [styles.css](styles.css) | Flexbox, Abstände, feste Größen und Google-Fonts-Import für Roboto |
| `images/` | Vorhandene Logos, Icons und Bilder |
| `music/` | Vorhandene MP3-Datei für das Audio-Element |

Kein Build-Schritt und kein Paketmanager erforderlich. Die Schriftart wird extern geladen.

## Lokal ansehen

`index.html` in diesem Ordner im Browser öffnen.

## Grenzen und Prüfbedarf

- Das Suchfeld liefert keine Suchergebnisse; Sprach- und Bildsymbole haben keine entsprechende Funktion.
- Mehrere Bilder besitzen im vorhandenen HTML keine Alternativtexte.
