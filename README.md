# Smart Sensor Node
Heldagsuppgift – Torsdag v44 2025

## Bakgrund
Du är systemutvecklare på Nordic Systems AB, som utvecklar inbyggda övervakningssystem för industriella miljöer.

En ny kund vill ha en Smart Sensor Node som kan:
- Mäta temperatur
- Lagra mätvärden lokalt
- Skicka data till en molnserver via TCP/HTTP

Kunden vill ha ett första tekniskt koncept och en enkelt fungerande prototyp i C som demonstrerar grundidén.
Du ska därför arbeta självständigt under dagen och leverera både kod och en teknisk rapport.

## Del 1 – Kravspecifikation och lösningsförslag
### Kravspecifikation (½ A4)
Beskriv:
- Vilka funktioner noden ska ha
- Hur den ska kommunicera (t.ex. TCP och HTTP)
- Vilka risker och begränsningar som finns

### Lösningsförslag / Offert (½ A4)
Riktad till kunden och ska innehålla:
- Hur du tänker lösa uppdraget
- En ungefärlig tidsplan
- Tekniska val (t.ex. C, socketprogrammering, GIT, Makefile)

## Del 2 – Scrum-planering
Beskriv i punktform hur ett litet team på tre personer kan arbeta enligt Scrum:

- Definiera roller:
  - Product Owner
  - Scrum Master
  - Developer

- Skapa ett exempel på Product Backlog med minst 5 stories, t.ex.  
  "Som användare vill jag kunna ansluta till servern via TCP..."

- Gör en Sprintplan för 2 veckor som beskriver:
  - Vad som ska byggas först
  - Varför prioriteringen ser ut som den gör

## Del 3 – Koduppgift: Enkel TCP/HTTP-klient
Implementera i C ett program som:

1. Använder TCP-socketar för att ansluta till en server (t.ex. example.com port 80)
2. Skickar en enkel HTTP POST-förfrågan:

   ```http
   POST / HTTP/1.1
   Host: example.com
   Content-Type: application/json

   {
       "device": "UUID",
       "time": "<time>",
       "temperature": "<temperature>°C"
   }
   ```

3. Tar emot svaret från servern och skriver ut det till terminalen  
   Testserver: https://httpbin.org/#/HTTP_Methods/post_post
4. Använder minst en funktionspekare (t.ex. för att välja olika hanteringsfunktioner för inkommande data)
5. Innehåller minst ett exempel på pekare till pekare (t.ex. char **argv eller dynamiskt tilldelad lista)
6. Kompileras via Makefile med separata .c och .h-filer
7. Versioneras med GIT (minst 3 commits med tydliga meddelanden)

## Del 4 – Reflektion och analys (~1 A4)
Skriv en reflektionsrapport där du analyserar arbetet och dina tekniska val.

Besvara följande frågor:

- Hur arbetade du för att tolka och skriva kravspecifikationen?
- Hur hjälpte Scrum-tänket dig att strukturera utvecklingen?
- Vad lärde du dig av att använda GIT och Makefile i projektet?
- Hur fungerar TCP-anslutningen och vad skiljer den från HTTP?
- Hur använde du pekare, pek-pekare och funktionspekare i din kod, och varför?
- Vilka risker eller förbättringsmöjligheter ser du i din implementation?

Avsluta med en länk till GIT-repot som hör till projektet.

Rapporten ska vara tekniskt reflekterande – inte bara beskrivande.  
Målet är att visa förståelse för hur systemutveckling i C fungerar från krav till kod.

## Inlämning
Lämna in en ZIP-fil som innehåller följande:

1. kravspecifikation.pdf
2. lösningsförslag.pdf
3. scrumplanering.pdf
4. kod/ – alla .c och .h-filer
5. reflektionsrapport.pdf

ZIP-filen laddas upp i Canvas under uppgiften.
