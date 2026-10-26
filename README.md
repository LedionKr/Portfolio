# Ledion Krasniqi - Portfolio

**Wirtschaftsinformatik - Student**

Dieses Repository gibt Einblick in meine bisherigen Arbeiten mit Quellcode und nachvollziehbarer Dokumentation.

## Navigation

- [Projektübersicht](#projektübersicht)
- [Repository-Struktur](#repository-struktur)
- [Lokal ansehen](#lokal-ansehen)
- [GitHub-Profil](https://github.com/LedionKr)

## Projektübersicht

| Arbeit | Inhalt und Einordnung | Technik |
| --- | --- | --- |
| **Aura Cleaning** | Fertige Website für Fahrzeugaufbereitung mit Leistungspaketen, FAQ und Kontaktwegen – als Projekt zum Vorstellen und Besichtigen. | HTML, CSS |
| **Schachprojekt** | C++-Konsolenanwendung mit Standard- und Atomschach, Zugprüfung, Brettimport und Rücknahme von Zügen. Mit Google-Test-Tests und Testdaten. | C++17, STL, Make, CMake, Google Test |
| **Google-Layout-Nachbau** | Einfacher Nachbau als Übung. Keine angebundene Suchfunktion. | HTML, CSS |

## Repository-Struktur

Projekte liegen unter `projects/<projektname>/`

Die [Vorlage](projects/_vorlage/README.md) ist ausdrücklich kein umgesetztes Projekt.

Die HTML-Ansicht auf GitHub zeigt Quellcode. Sie ist keine Website-Demo.

## Lokal ansehen

### Schachprojekt starten

Mit einem C++17-fähigen Compiler und Make im Repository-Stamm:

```sh
cd projects/schachprojekt
make
./projectChess
```

Beim Start `Default` oder `Atomchess` wählen. Bedienbeispiele, eine Build-Alternative und Hinweise zu den Tests stehen im [Projektüberblick](projects/schachprojekt/PORTFOLIO.md).
