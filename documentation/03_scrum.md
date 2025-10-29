## Scrumroller
#### Product Owner (PO)
Ansvarar för produkten.
Systemarkitekt, hårdvara och mjukvara.
Sköter all kontakt med kunden. 
Läser på om certifieringar och klassificeringar relevanta för kundens användningsområde. Kan ta in extern konsult med domänexpertis om vi får kundkontraktet. Kommunicerar dessa till dev teamet.
Levererar systemarkitektur till dev lead.
I detta projekt: Gamle Farmor

#### Developer & Scrum Master (DEV lead & SM)
Sköter allt med scrum.
Bestämmer implementationsdetaljer baserat på systemarkitekturen. Implementerar dessa samt delegerar kodning till dev(s).
Ansvarar för att projektet är körbart och testbart hela vägen igenom och att systemarkitekturen följs.
Testar all kod.
I detta projekt: Skalman

### Developer (DEV)
Implementerar det han blir tilldelad enligt specifikation och företagets kodstandard. 
Skriver tester för all kod.
I detta projekt: Vargen

## Product Backlog

(Prioriterad efter affärsvärde och tekniskt beroende)

Som användare vill jag kunna mäta temperatur lokalt
– så att jag kan följa aktuell temperatur i realtid.

Acceptance criteria: Sensor kan läsa temperatur var 5:e sekund och skriva till logg.

Som användare vill jag kunna lagra mätvärden lokalt på enheten
– så att data inte förloras vid nätverksavbrott.

Acceptance criteria: Data skrivs till fil i formatet TIMESTAMP : TEMPERATURE.

Som användare vill jag kunna skicka mätdata till en server via HTTP
– så att central systemövervakning kan ske.

Acceptance criteria: Sensorn skickar mätdata var 5:e minut med HTTP POST.

Som administratör vill jag kunna ändra mät- och uppladdningsintervall
– så att jag kan anpassa sensorns beteende efter driftmiljö.

Acceptance criteria: Konfigurationsfil eller kommando möjliggör ändring av intervall.

Som användare vill jag kunna definiera triggers för larm
– så att systemet kan reagera vid onormala temperaturförändringar.

Acceptance criteria: Trigger triggas vid definierade temperaturförändringar (t.ex. >3°C/min).

Som systemadministratör vill jag kunna pinga sensorn
– så att jag kan se att den är aktiv utan att den skickar data.

Acceptance criteria: HTTP GET ger statuskod 200 när sensorn är online.

## Sprintplanering (en sprint om 2 veckor)
Sprintmål: Bygga en fungerande prototyp som mäter, lagrar och skickar temperaturdata enligt version v0.1.

## Sprint Backlog (valda stories från Product Backlog)
Prioritet	Story ID	Story	Motivering
1	#1	Mäta temperatur lokalt	Grundfunktion – sensorns kärna.
2	#2	Lagra mätdata lokalt	Krävs för att säkra data innan kommunikation finns.
3	#3	Skicka mätdata via HTTP	Gör att kunden kan se mätdata – första kundvärde.
Sprint Tasks

## Story #1 – Mäta temperatur
Implementera sensorgränssnitt (mock-sensor om nödvändigt).
Skapa timer för mätintervall (standard 5 sekunder).
Logga mätvärde till konsol.

## Story #2 – Lagra mätdata
Skapa textfil för lagring (data.txt).
Skriv mätvärde i formatet TIMESTAMP : TEMPERATURE.
Hantera filrotation om disken blir full.

## Story #3 – Skicka data via HTTP
Implementera enkel HTTP POST-funktion med POSIX sockets.
Skicka uppladdning var 5:e minut.
Bekräfta mottagning med servern.

## Story #4 – Konfigurera intervall och parametrar
Mät- och uppladdningsintervall kan ändras via konfigurationsfil eller kommando; ändringar tillämpas utan omstart.

## Story #5 – Definiera triggers för larm
Systemet kan definiera och utlösa larm vid definierade temperaturhändelser såsom >3°C per minut; larm loggas och markeras för åtgärd.


## Definition of Done (DoD)
Koden kompilerar utan varningar.
Alla stories testade lokalt.
Grundläggande dokumentation finns i README.
Prototypen kan demonstreras för kund (v0.1).

## Dagliga aktiviteter
Daily Scrum 5 min varje morgon.
Vad gjorde jag igår?
Vad ska jag göra idag?
Finns några hinder?

## Sprint Review (Dag 14)
Visa fungerande prototyp för kunden.
Mäta → Lagra → Skicka data till testserver.
Diskutera förbättringar (t.ex. triggers, konfigurering).

## Sprint Retrospective
Vad gick bra (t.ex. tydlig ansvarsfördelning)?
Vad kan förbättras (t.ex. bättre testdata)?
Vilka åtgärder inför nästa sprint (t.ex. implementera triggers)?