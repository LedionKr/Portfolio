# Bestandsaufnahme

[Dokumentationsübersicht](README.md) · [Portfolio](../README.md)

Stand der ersten Sichtung: **21. Oktober 2026**, Basis `main` bei Commit `b8802ab5e201d693b36a3712ec2ecc6555973a58`.

## Vorhandene Inhalte

| Pfad | Befund |
| --- | --- |
| `AuraCleaning/` | Drei HTML-Seiten, `styles.css`, eine leere `rechtlich.css` und ein Logo. Die ursprüngliche Stamm-README bezeichnet die Website als eigene Website für Aura Cleaning. |
| `Html/Google/` | Statische Suchmaschinen-Layoutübung mit CSS, Bildern, einer Audio-Datei und einer separaten Übungsseite unter `pages/`. |
| `Html/indexLernen.html` | Sammlung von HTML-Beispielen mit Formularen, Tabellen, iframe und einem kleinen eingebetteten JavaScript-Beispiel. |
| `Html/cssLernen.html` | Text und Abbildung zum CSS-Boxmodell. |

Vor der Aufbereitung bestand die Stamm-README aus einem Titel und einem Stichpunkt. Projektbeschreibungen, Startanleitungen und Prüfnachweise waren nicht enthalten. Im gesichteten Dateibaum waren keine Build-Konfiguration, Backend-Dateien oder automatisierten Tests vorhanden.

## Einordnung und offene Angaben

- Aura Cleaning ist eine vorhandene Implementierung. Ein produktiver Betrieb, ein Auftrag, ein Teamumfang oder Geschäftsergebnisse sind anhand des Repositorys nicht belegt.
- Die Google-Oberfläche ist eine Lernübung. Das Suchformular hat keine angebundene Suchlogik.
- Die übrigen HTML-Dateien sind Lernmaterial mit teilweise unvollständigen Beispielen. Sie werden nicht als abgeschlossene Anwendungen geführt.
- Zeitraum, konkrete Eigenanteile bei übernommenen Bestandteilen sowie genutzte Tutorials oder Hilfsmittel sind noch nicht dokumentiert.
- Hochschule, Semester, gewünschter Praktikumszeitraum und bevorzugter Tätigkeitsbereich sind nicht angegeben. Diese Angaben werden nicht ergänzt, bis sie bestätigt sind.

## Nachvollziehbare offene Punkte

| Bereich | Beobachtung aus dem Quellcode | Weiteres Vorgehen |
| --- | --- | --- |
| Aura Cleaning | `datenschutz.html` verweist auf `style.css`; vorhanden ist `styles.css`. Impressum und Datenschutz enthalten Platzhalter. | Dateiverweis und Inhalte in einer eigenen Änderung bearbeiten; vor Veröffentlichung prüfen. |
| Aura Cleaning | In `impressum.html` verweist der Footer-Link „Termin buchen“ auf `#kontaktLinks`; diese ID ist dort nicht vorhanden. | Ziel auf der Startseite prüfen und gesondert korrigieren. |
| Layoutübung | Bilder haben teilweise keine Alternativtexte; feste Breiten und `min-width: 400px` begrenzen kleine Ansichten. | Tastaturbedienung, Bildbeschreibungen und mobile Darstellung prüfen. |
| Grundlagen | `indexLernen.html` referenziert Bilder unter `Html/images/` und ein Formularziel `action_page.php`; diese Ziele fehlen im Bestand. | Beispiele als unvollständig kennzeichnen und bei Überarbeitung gezielt vervollständigen. |
| Grundlagen | `cssLernen.html` verwendet Backslashes im Bildpfad. | Portablen URL-Pfad bei einer Überarbeitung verwenden. |
| Medien | Google-Markenmaterial, weitere Bilder und eine MP3-Datei sind enthalten; Quellen und Freigaben sind nicht dokumentiert. | Herkunft und Nutzungsrechte vor externer Weitergabe oder Veröffentlichung klären. |
| Qualität | Es liegen keine dokumentierten Browser-, Geräte- oder Barrierefreiheitstests vor. | Prüfungen durchführen und Ergebnisse mit Datum festhalten. |

Diese Punkte stammen aus einer statischen Sichtung. Sie ersetzen keine Laufzeitprüfung und werden durch die Dokumentationsänderung nicht als behoben dargestellt.

## Strukturentscheidung

Die bisherigen Ordner bleiben erhalten, damit relative Ressourcenpfade und bestehende Links stabil bleiben. `projects/` nimmt neue eigenständige Projekte auf; `_vorlage/` enthält ausschließlich Vorlagen. `docs/` bündelt die Pflege des gesamten Portfolios. Es werden keine leeren Kategorien für unbelegte Fähigkeiten oder fiktive Projekte angelegt.
