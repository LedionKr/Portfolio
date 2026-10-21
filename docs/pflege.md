# Portfolio pflegen

[Dokumentationsübersicht](README.md) · [Portfolio](../README.md)

## Ein neues Projekt aufnehmen

1. `projects/_vorlage/` nach `projects/<projektname>/` kopieren. Einen kurzen, verständlichen Ordnernamen verwenden.
2. In der kopierten README alle Platzhalter ersetzen und nicht passende Abschnitte entfernen. Den Hinweis „Vorlage“ erst entfernen, wenn eine echte Projektbeschreibung vorliegt.
3. Vorhandenen Code mit seinen benötigten Ressourcen aufnehmen. `src/`, `tests/` oder `assets/` nur anlegen, wenn das Projekt sie benötigt. Bestehende Framework-Strukturen beibehalten.
4. Problem, Zielgruppe, konkreten Umfang und Eigenanteil beschreiben. Teambeiträge, Tutorials, fremde Bestandteile sowie eingesetzte Hilfsmittel transparent zuordnen.
5. Voraussetzungen und Startanleitung aus einer frischen Arbeitskopie prüfen. Konkrete Ergebnisse, Grenzen und offene Punkte dokumentieren.
6. Einen Eintrag in `projects/README.md` und der Stamm-README ergänzen. Technologien mit konkreten Dateien oder Dokumenten belegen.

## Status verständlich benennen

| Status | Verwendung |
| --- | --- |
| Geplant | Idee oder Konzept; noch keine Umsetzung. Nicht als fertige Referenz aufführen. |
| In Arbeit | Umsetzung begonnen; nutzbare Teile und fehlender Umfang ausdrücklich benennen. |
| Implementierung vorhanden | Code liegt vor; Abschluss und Qualität ergeben sich erst aus dokumentiertem Umfang und Prüfungen. |
| Abgeschlossen im beschriebenen Umfang | Ziele und Abnahmekriterien sind erfüllt und durch Ergebnisse belegt. Bekannte Grenzen bleiben sichtbar. |
| Lernübung | Material zum Erarbeiten einzelner Grundlagen; kein Produktivitäts- oder Projekterfolgsnachweis. |

Die Vorlage ist kein Projektstatus und zählt nicht als Projektreferenz.

## Bei Änderungen aktualisieren

- Funktionen, Startbefehle, Abhängigkeiten und Einschränkungen gemeinsam mit dem Code pflegen.
- Anforderungen und Entscheidungen im jeweiligen Projektordner festhalten; keine Entscheidungen rückwirkend erfinden.
- Tests und manuelle Prüfungen mit Datum, Umgebung, erwartetem und tatsächlichem Ergebnis protokollieren. Nicht durchgeführte Prüfungen bleiben offen.
- Projektübersicht, Techstack-Nachweise und interne Links auf Konsistenz prüfen.
- Screenshots nur aus der tatsächlichen Anwendung ergänzen; Stand, Ansicht und gegebenenfalls anonymisierte Daten benennen.

## Vor einer Bewerbung prüfen

- [ ] Die wichtigsten Arbeiten lassen sich über die Stamm-README schnell erreichen.
- [ ] Projektbeschreibungen nennen meinen tatsächlichen Eigenanteil und den realen Stand.
- [ ] Startanleitungen funktionieren aus einer frischen Arbeitskopie.
- [ ] Interne Links, Bildpfade und gegebenenfalls Demo-Links funktionieren.
- [ ] Relevante Darstellungen, Bedienwege und bekannte Einschränkungen sind geprüft und dokumentiert.
- [ ] Platzhalter in für die Bewerbung relevanten Beschreibungen sind ersetzt; Vorlagen bleiben klar erkennbar.
- [ ] Kontaktdaten, externe Verweise und Medien sind für den beabsichtigten Empfängerkreis geprüft; Quellen sind dokumentiert.
- [ ] Für das private Repository besteht ein geeigneter Zugriffsweg für die vorgesehenen Empfänger.
- [ ] Angaben zum Praxissemester sind aktuell, sofern sie ergänzt wurden.

## Änderungen nachvollziehbar halten

Änderungen möglichst auf einem eigenen Branch vorbereiten, den Unterschied zu `main` prüfen und über einen Pull Request zusammenführen. Eine Dokumentationsänderung beschreibt ihren Umfang und ihre Prüfungen. Codekorrekturen erhalten eine passende eigene Prüfung.

Die `.gitignore` verhindert künftig unter anderem neue `.DS_Store`- und lokale `.env`-Dateien. Bereits versionierte Dateien bleiben dadurch unverändert im Repository. Eine Bereinigung des Bestands erfolgt nur als bewusst geprüfte eigene Änderung.
