# Kravspecifikation
## Mäta
Vi pollar sensorn enligt förinställd frekvens. Om inga triggers träffat sover vi mellan polls.

## Lagra
Mätvärdet skrivs till en textfil på disk, ett mätvärde per rad enligt formatet: "TIMESTAMP : TEMPERATURE". Om nätverket är nere en längre tid och disken blir full så fortsätter vi att lagra temp genom att skriva över de älsta mätvärderna.

Om vi har ett batteri i enheten kan vi lagra mätvärden i RAM för att minska antalet writes till disk. (vi bör även mäta om detta faktiskt sparar energi eller ej).  Vi måste då kolla att vi alltid tömmer RAM innan batteriet tar slut. Men detta är för senare versioner.

## Rapportera till server
Mätvärden skickas upp med POSIX sockets via http 1.1 meddelanden enligt förberstämd intervall eller vid triggers.

Vid framgångsrik uppladdning frigör vi utrymmet i RAM  och på disken. Dvs allt på disk är alltid mätvärden servern ej har sett ännu.