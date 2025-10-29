# Tekniskt koncept
En ny kund vill ha en "smart sensor node" som ska kunna mäta, lagra och skicka temperatur via HTTP. 

Kunden har ej kommit med mer krav än ovanstående; så jag föreslår att vi bygger en så flexibel sensor som möjligt. Vi vill inte stå och säga "nä det kan den inte göra" på första kund-demon.

Den ska både gå att använda som temperatursensor privat i till exempel en krypgrund eller som del av ett större system för övervakning av temperaturkänsliga industiella låglatens processer.

Framtida iterationer bör certifieras för användning av läkemedels och mathanterings industrin m.m.

## Mäta
Mätintervall är ställbart men default sätts till 5 sekunder. Då kan vi reagera snabbt nog om tex värmekänsliga maskiner behövs stängas av eller kylsystem startas etc.
Detta beror så klart även på hårdvaran och hurvida vi drivs via batteri eller ej.

## Lagra
Vi skriver temperaturen till disk vid varje mätvärde. Vi vill inte förlora någon data.

## Rapportera till server
Vi laddar upp via HTTP en gång var femte minut per default. Detta går att ställa in. 

Oerhört viktigt för sensorns användbarhet att man kan ställa in "triggers" för när data ska skickas och att vi skickar med meddelande i varje uppladdning.

På så sätt kan sensorn larma vid för hög, låg eller för snabb förändring av temperatur.

Tex: temperaturen i långtidslagrets frysrum har stigit från -32c till -29c på x minuter. Skicka larm då EU-lagen kräver minimum -25c. (påhittade värden)

Man kan alltså bara skicka upp vid larm, eller låta sensorn ticka på efter förinställd kadens.

Man bör även kunna låta sensorn "pinga" tillbaks till huvudsystemet så att systemet vet att sensorn finns och fungerar. Men detta är för senare versioner.
