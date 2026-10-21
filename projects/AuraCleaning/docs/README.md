# Aura Cleaning · Technische Dokumentation

[Projekt-README](../README.md) · [Portfolio](../../../README.md)

## Ziel und sichtbarer Ablauf

Die Seite präsentiert Fahrzeugaufbereitung. Besucherinnen und Besucher können Pakete vergleichen, FAQ öffnen und zu einem Kontaktweg wechseln. Die fachliche Abfolge ist im Aufbau der Startseite sichtbar: Einstieg → Leistungen → Fragen → Kontakt.

Es gibt keinen eigenen Buchungsprozess. Die Links im Kontaktbereich verweisen auf Telefon und externe Dienste. Ein wirtschaftlicher Erfolg oder eine gemessene Nutzung ist nicht dokumentiert.

## Technischer Aufbau

- `index.html` enthält die Inhaltsbereiche und Navigation per Fragment-ID.
- Die mobile Navigation ist als Checkbox mit Label und CSS-Selektoren umgesetzt.
- FAQ verwenden native HTML-Elemente `details` und `summary`.
- `styles.css` enthält zentrale Farb- und Schriftvariablen sowie Flexbox, Grid und Media Queries bei 1024, 768 und 480 Pixeln.
- Impressum und Datenschutz liegen als eigene HTML-Dateien vor.
- Die Startseite und das Impressum laden Schriftarten von Google Fonts. Logo-Dateien liegen lokal unter `images/`.

Dies beschreibt den vorhandenen Aufbau. Eine ursprüngliche Entscheidungsbegründung oder eine Evaluation von Alternativen ist nicht dokumentiert.

## Offene Befunde aus der statischen Sichtung

| Befund | Nachweis | Nächster Schritt |
| --- | --- | --- |
| Fehlender Stylesheet-Pfad | `datenschutz.html` lädt `style.css`; die Datei ist im Projekt nicht vorhanden. | Den beabsichtigten Stylesheet-Verweis prüfen und korrigieren. |
| Nicht vorhandenes Sprungziel | Footer in `impressum.html`: `href="#kontaktLinks"` ohne entsprechende ID auf dieser Seite. | Ziel auf `index.html` prüfen. |
| Unvollständige Inhalte | Impressum und Datenschutz enthalten Platzhalter. | Tatsächliche Angaben und Veröffentlichungsstand klären. |
| HTML-Struktur prüfen | Im Impressum steht vor dem Ende der Section ein schließendes `div` ohne zugehöriges öffnendes Element. | Mit einer HTML-Prüfung nachvollziehen und separat korrigieren. |
| Sprachkennzeichnung prüfen | Startseite und Impressum enthalten deutschen Inhalt bei `lang="en"`. | Sprache bei einer Überarbeitung passend kennzeichnen. |
| Ungeprüfte Bedienung | Mobile Navigation, feste Kopfzeile und Animationen sind vorhanden, aber ohne dokumentierte Bedienprüfung. | Tastatur, Fokus, kleine Bildschirme und reduzierte Bewegung prüfen. |

## Vorgesehene manuelle Prüfung

**Status: nicht durchgeführt.** Die folgenden Schritte sind ein Prüfplan, keine bestandenen Tests.

| Prüfschritt | Erwartung |
| --- | --- |
| Startseite lokal öffnen | HTML, CSS und Logo werden geladen. |
| Navigation bei schmaler und breiter Ansicht bedienen | Menü und Inhalte bleiben erreichbar; kein ungewolltes horizontales Scrollen. |
| Leistungen, FAQ und Kontakt per Navigation aufrufen | Das jeweilige Ziel ist sichtbar und wird nicht von der Kopfzeile verdeckt. |
| FAQ per Tastatur öffnen und schließen | Inhalte sind ohne Maus erreichbar; Fokus ist erkennbar. |
| Impressum und Datenschutz öffnen | Inhalte, Verweise und Ressourcen passen zum dokumentierten Stand; bekannte Fehler werden protokolliert. |
| Externe Kontaktziele im Quellcode kontrollieren | Ziele sind korrekt zugeordnet; eine Kontaktaufnahme ist dafür nicht erforderlich. |

Für tatsächliche Ergebnisse die [Prüfvorlage](../../_vorlage/docs/pruefung.md) kopieren und Datum, Browser, Stand und Befunde ergänzen. Es ist keine automatisierte Testsuite im Projekt vorhanden.

## Noch zu dokumentieren

Konkreter Eigenanteil, Entstehungszeitraum, verwendete Quellen und Hilfsmittel, Herkunft des Logos sowie tatsächliche Lernerkenntnisse. Eine Anleitung dazu liefert die [Reflexionsvorlage](../../_vorlage/docs/reflexion.md).
