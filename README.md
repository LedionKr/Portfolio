# Ledion Krasniqi · Portfolio

**Wirtschaftsinformatik-Student · Bewerbung um ein Praxissemester**

Dieses Repository gibt Einblick in meine bisherigen Arbeiten und meinen Lernstand. Es verbindet Quellcode mit nachvollziehbarer Dokumentation: Was soll eine Anwendung leisten, wie ist sie aufgebaut und welche Fragen sind noch offen?

Der aktuelle Schwerpunkt liegt auf statischen Websites und Übungen zu Web-Grundlagen. Die Projektbeschreibungen beziehen sich auf den vorhandenen Code. Angaben zu Auftraggebern, Teamrollen oder messbaren Ergebnissen ergänze ich erst, wenn sie belegt sind.

## Navigation

- [Projektübersicht](#projektübersicht)
- [Techstack und Nachweise](#techstack-und-nachweise)
- [Repository-Struktur](#repository-struktur)
- [Lokal ansehen](#lokal-ansehen)
- [Dokumentation und Pflege](#dokumentation-und-pflege)
- [GitHub-Profil](https://github.com/LedionKr)

## Projektübersicht

| Arbeit | Inhalt und Einordnung | Technik | Einstieg |
| --- | --- | --- | --- |
| **Aura Cleaning** | Fertige Website für Fahrzeugaufbereitung mit Leistungspaketen, FAQ und Kontaktwegen – als Projekt zum Vorstellen und Besichtigen. | HTML, CSS | [Projektbeschreibung](projects/AuraCleaning/README.md) · [Quellcode](projects/AuraCleaning/index.html) · [Technische Dokumentation](projects/AuraCleaning/docs/README.md) |
| **Google-Layoutübung** | Nachbau einer Suchmaschinen-Oberfläche als Lernübung. Keine angebundene Suchfunktion. | HTML, CSS | [Projektbeschreibung](Html/Google/README.md) · [Quellcode](Html/Google/index.html) |
| **Web-Grundlagen** | Lernsammlung zu HTML-Elementen, Formularen, CSS-Boxmodell und einem kleinen JavaScript-Beispiel. | HTML, CSS-Grundlagen, einzelnes JavaScript-Beispiel | [Übersicht](Html/README.md) · [HTML-Übung](Html/indexLernen.html) · [Boxmodell](Html/cssLernen.html) |

Für einen schnellen Einblick empfiehlt sich **Aura Cleaning**: Die Dokumentation verbindet die sichtbaren Seitenbereiche mit dem technischen Aufbau und benennt die Grenzen des aktuellen Standes. Die Lernübungen zeigen ergänzend einzelne Grundlagen.

## Techstack und Nachweise

### Im Quellcode sichtbar

| Bereich | Konkreter Nachweis | Einordnung |
| --- | --- | --- |
| HTML | [projects/AuraCleaning/index.html](projects/AuraCleaning/index.html): Navigation, Inhaltsbereiche, Links und FAQ mit `details`/`summary` | Statischer Seitenaufbau |
| CSS | [projects/AuraCleaning/styles.css](projects/AuraCleaning/styles.css): Custom Properties, Flexbox, Grid und Media Queries | Gestaltung mit vorgesehenen Anpassungen an Bildschirmbreiten; kein Nachweis umfassender Gerätetests |
| HTML/CSS-Lernübungen | [Html/Google](Html/Google/README.md) und [Html](Html/README.md) | Layout, Formulare und Boxmodell |
| JavaScript | [Html/indexLernen.html](Html/indexLernen.html): `doSomething()` verändert einen Text per DOM-Zugriff | Einzelnes Grundlagenbeispiel |

### Technischer Rahmen

Die vorhandenen Websites benötigen keinen Build-Schritt und keinen Paketmanager. Aura Cleaning und die Google-Layoutübung laden Schriftarten über Google Fonts. Eine Backend-Implementierung, Datenbank, API-Anbindung oder automatisierte Testsuite ist im aktuellen Bestand nicht enthalten. Diese Übersicht beschreibt eingesetzte Technik und ersetzt keine allgemeine Selbsteinschätzung von Kenntnissen.

## Repository-Struktur

```text
.
├── README.md                 Einstieg und Projektübersicht
├── Html/                     Bestehende Lernsammlung
│   ├── README.md
│   ├── Google/               Layoutübung mit eigener README
│   ├── indexLernen.html
│   └── cssLernen.html
├── projects/                 Fertige Website und weitere Projekte
│   ├── AuraCleaning/         Fertiges Website-Projekt
│   │   ├── docs/             Aufbau und Weiterentwicklung
│   │   ├── images/           Vorhandene Bilddateien
│   │   ├── index.html
│   │   └── ...               CSS und weitere HTML-Seiten
│   └── _vorlage/             Kopierbare README und Dokumentationsvorlagen
└── docs/                     Repository-Dokumentation und Pflege
```

Eigenständige Projekte liegen unter `projects/<projektname>/`, beginnend mit der fertigen Website Aura Cleaning. HTML-Lernübungen bleiben separat unter `Html/`. Die [Vorlage](projects/_vorlage/README.md) ist ausdrücklich kein umgesetztes Projekt.

## Lokal ansehen

1. Repository mit einem GitHub-Konto klonen, das Zugriff auf das private Repository hat:

   ```sh
   git clone https://github.com/LedionKr/Portfolio.git
   cd Portfolio
   ```

2. `projects/AuraCleaning/index.html` oder `Html/Google/index.html` im Browser öffnen. Für die Grundlagen `Html/indexLernen.html` bzw. `Html/cssLernen.html` öffnen.
3. Optional mit installiertem Python 3 einen lokalen Webserver im Repository-Stamm starten:

   ```sh
   python3 -m http.server 8000 --bind 127.0.0.1
   ```

   Anschließend [Aura Cleaning](http://localhost:8000/projects/AuraCleaning/) oder die [Layoutübung](http://localhost:8000/Html/Google/) öffnen. Mit `Ctrl+C` beenden.

Die HTML-Ansicht auf GitHub zeigt Quellcode; sie ist keine Website-Demo. Ein geprüftes Live-Deployment ist hier nicht dokumentiert. Kontaktlinks in Aura Cleaning führen zu den im Code hinterlegten externen Diensten bzw. Telefonnummern.

## Dokumentation und Pflege

- [Dokumentationsübersicht](docs/README.md): Orientierung für Leserinnen und Leser.
- [Bestandsaufnahme](docs/bestandsaufnahme.md): Was vorhanden ist und was noch zu klären ist.
- [Pflegeleitfaden](docs/pflege.md): Neue Projekte aufnehmen, prüfen und aktuell halten.
- [Projektvorlage](projects/_vorlage/README.md): Ziel, Eigenanteil, Technik, Startanleitung, Grenzen und Reflexion festhalten.

Projektstatus und Techstack werden zusammen mit dem Code aktualisiert. Geplante Arbeit bleibt als solche gekennzeichnet; Prüfergebnisse werden erst nach tatsächlicher Durchführung eingetragen. Vor dem Teilen für Bewerbungen sind Zugriff, persönliche Angaben und Nutzungsrechte der enthaltenen Medien zu prüfen. Das Repository ist derzeit privat.
