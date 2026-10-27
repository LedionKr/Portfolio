# Aura Cleaning

**Fertiges Website-Projekt - Fahrzeugaufbereitung**

[Portfolio](../../README.md) · [Projektübersicht](../README.md) · [Technische Dokumentation](docs/README.md) · [Startseite als Quellcode](index.html)

## Kurzüberblick

Die Website stellt Fahrzeugaufbereitung mit drei Leistungspaketen dar und führt über FAQ und Kontaktlinks zu einer Kontaktaufnahme. Sie verbindet einen konkreten Dienstleistungsauftritt mit einer Umsetzung in HTML und CSS.

**Status: Fertige Website.** Aura Cleaning ist eine eigene Website und dient im Portfolio als Projekt zum Zeigen und Vorstellen. Der umgesetzte Umfang umfasst die Präsentation der Leistungen, FAQ und Kontaktmöglichkeiten. Hinweise zur Weiterentwicklung stehen in der technischen Dokumentation.

Ein Live-Link ist derzeit nicht dokumentiert. Die Website lässt sich mit der folgenden Anleitung lokal ansehen. Zeitraum, genauer Eigenanteil und gegebenenfalls verwendete Hilfsmittel können ergänzend dokumentiert werden.

## Vorhandener Umfang

- Startbereich mit Navigation zu Leistungen, FAQ und Kontakt.
- Drei Leistungspakete mit Preisangaben im vorhandenen Seiteninhalt.
- Aufklappbare FAQ mit HTML-Elementen `details` und `summary`.
- Links für Telefon, WhatsApp und Instagram sowie weitere Social-Media-Verweise im Footer.
- CSS mit Grid, Flexbox, Custom Properties und Media Queries.
- Separate Seiten für Impressum und Datenschutz; sie enthalten noch Platzhalter und offene Punkte.

Die Termin-Schaltflächen führen zum Kontaktbereich. Eine Online-Buchung, ein Backend oder eine Datenspeicherung durch eigenen Anwendungscode ist nicht implementiert. Aussagen zu Preisen und Leistungen sind Seiteninhalte, keine vom Portfolio bestätigten Geschäftsdaten.

## Techstack

| Bestandteil | Verwendung | Datei |
| --- | --- | --- |
| HTML | Seitenstruktur, Navigation, FAQ und Kontaktlinks | [index.html](index.html) |
| CSS | Gestaltung, Layout und vorgesehene Anpassung an Bildschirmbreiten | [styles.css](styles.css) |
| Google Fonts | Extern geladene Schriftarten „Bebas Neue“ und „DM Sans“ | Einbindung im HTML-Kopf |

Kein Paketmanager oder Build-Schritt erforderlich. Externe Schriftarten benötigen eine Netzwerkverbindung; lokale Ersatzschriften sind im CSS angegeben.

## Lokal ansehen

`index.html` in diesem Ordner im Browser öffnen.

## Aufbau

| Pfad | Aufgabe |
| --- | --- |
| `index.html` | Startseite mit Leistungen, FAQ und Kontakt |
| `styles.css` | Gemeinsame Gestaltung |
| `impressum.html`, `datenschutz.html` | Vorhandene Inhaltsseiten mit noch offenen Angaben |
| `rechtlich.css` | Vorhandene, leere Datei |
| `images/` | Vorhandenes Logo und bestehende Ressourcen |
