# Hur arbetade du för att tolka och skriva kravspecifikationen?
Jag tänkte mig att man vill ha en lagom high level beskrivning. man vill ju inte skriva koden, och inte heller ha för lite detalj så det finns för många sätt att implementera speccen på. 

# Hur hjälpte Scrum-tänket dig att strukturera utvecklingen?
Vet ej. Men verkar i teorin tvinga en att jobba väldigt iterativt. Var ganska kul att försöka tänka ut vem som skulel göra vad och vad som är ett smart upplägg på så få personer. 

# Vad lärde du dig av att använda GIT och Makefile i projektet?
Använde min standard projekt mall för github med makefile, debugging, code formating etc inställt och klart. Smidigast tycker jag det är när man kopplar (som jag gjort) F5 i vscode till att bygga och runna / debugga projektet.  

# Hur fungerar TCP-anslutningen och vad skiljer den från HTTP?
Sockets API:et i linux skapar tcp anslutningar. (följer POSIX standarden) HTTP är textprotokollet man sänder över socketen. Om man har kontroll över både server och klient kan man skicka vad man vill över. MEn o mdet ska funka med alla datorer måste man så klart följa någon standard. Så som HTTP 1.1 

# Hur använde du pekare, pek-pekare och funktionspekare i din kod, och varför?
Jag är inte klar med det riktiga projektet jag borde jobba på just nu. Så använde inga alls. KÖttade bara klart detta så fort jag kunde då jag nu redan ligger efter.
De kommer behövas sen när man har en state machine och man ska lägga in en task i den. Men är kvar på stadiet att bygga mitt egna http / tcp libs och förstå state machines och callback patternet så inte kommit så långt än. 

# Vilka risker eller förbättringsmöjligheter ser du i din implementation?
Den är helt kass och ska absolut inte användas. I en riktig betaversion skulle jag vilja använda mina egna tcp, http parsing libs tillsammans med en icke-callback state machines för att sköta conneciton lifetimes och parsing.

# Länk till GIT-repot som hör till projektet.
https://github.com/jimmyjordanSWE/smart_sensor_node