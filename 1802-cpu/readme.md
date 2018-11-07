# Cosmac ELF / CDP1802 CPU Karte

Gleich vorweg: Das werden evtl. nur Gedankenspiele bleiben - ob ich das jemand umsetze..?? Hängt wohl auch davon ab, ob daran überhaupt Interesse besteht (bei mir schon - sonst würde ich daran keinen Gedanken verschwenden).

VÖLLIG UNGETESTET!! KEINERLEI GEWÄHR!!


Die CDP1802 CPU ist 'wierd'! Ich hatte einen Cosmac Elf bereits schon einmal als Einplatinenrechner nachgebaut:

https://github.com/petersieg/cosmac-elf



Das Design stammt von Mike Riley und hat gut/auf Anhieb funktioniert.



Allgemeine Info's zum Cosmac Elf:

https://en.wikipedia.org/wiki/COSMAC_ELF

http://www.cosmacelf.com/



---



Die 1802 hat 4 Inputsignale (EF1-4) zum lesen von Daten. 3x Signale für IO-Module (N0-N2) und spezielle OUT/INP Befehle dazu.

IO wird auch geschrieben ohne MWR aktiv zu setzen..? Und D0-D7 sind wenn ich das richtig verstanden habe niemals Tri-State?! Dann ginge es nicht den Bus-Signalgeber zu nutzen! (Lektüre sollte das Datenblatt zur CPU sein)



---



Nun im MFA Gehäuse sollte man damit - wenn alles so klappt wie angedacht - ein kleines Programm über die Toogle Schalter eingeben und laufen lassen können.

Die Bus-Signalanzeige zeigt dabei Daten+Adressen an. Ein Eingabeport steht dabei ebenfalls über die Schalter zur Verfügung.

Ggf. ließen sich weitere I/O Teile nutzen über D0-D7 und N0+N1. Evtl. sollte ich noch EF1/2/3 auf den Bus legen..? Pin c14+c24 sollte noch unbelegt sein.

(Dazu müssten dann aber die IO Baugruppen lernen daraus/damit zu arbeiten!)



---



Ich habe also mal die Eagle Dateien von Tom genommen und die TIL311 rausgeschmissen.

Die Anzeige der Daten und der Adressen soll hier dann natürlich die Bus-Signalanzeige übernehmen.

JP2 Pinreihe ist ebenfalls raus. Dafür ist die VG64 Busleiste reingekommen. An der liegen A0-A15, D0-D7, MRD, MWR, N0+N1.



Die Toogle Switches habe ich so drin gelassen - sie dienen dazu:

1. Das Ram mit einem Programm zu laden (das sollte ggf. auch mit einen Bus-Signalgeber möglich sein?)

2. Input Port über EF4



An einer Busverlängerung könnte man das so betreiben - ansonsten müssten die Schalter (+ Q-LED) auf die Frontblende.



Ich hänge mal den original Schaltplan (sch-org.png) und das Ergebnis mach obigen Operationen (sch.png) hier an.

Ebendso das Ergebnis des Autorouters mit 0,25mm Leiterbahnbreite.



Nun die gute Nachricht ist: Passt auf 80x100mm und der Autorouter hat fertig zu 100%.

VÖLLIG UNGETESTET!! KEINERLEI GEWÄHR!!
