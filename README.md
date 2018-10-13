# MFA

some files for MFA (Mikrocomputer Für Ausbildung) Computer.

You don't need a video+keyboard card. You can connect a rs232 terminal/pc, even without changing bridges on CPU board.
Just connect Pin32a+c=GND=db9-5, Pin30c=Rx=db9-2 and Pin29c=Tx=db9-3 to a DB9 sub-d female header.

DE:

Ich habe heute einen Linux PC mit dem guten, alten minicom angeschlossen - ohne Brücken auf der CPU Platine - quasi ANSTATT der Video/Keyboard Karte (die sollte nicht parallel drin sein!). Das ging sowohl mit 4800 Baud als auch mit 1200 Baud (was wohl die Videokarte braucht!!). Weitere Einstellung musste 7E1 sein!

8N1 gab nur Schmutzzeichen. Dazu ist nur eine DB9 Buchse mit 3 Kabelverbindungen nötig. Pin5 mit Masse (32a+c). Pin2 mit 30c und Pin3 mit 29c.

(Die parallele IF Karte ist hier ohne elektrische Bedeutung - nur mechanischer Träger)

Das kann durchaus aus Vorteile haben, einen PC als Aus-/Eingabe zu nutzen. Es können leicht Programme/Daten ausgetauscht werden. Programmlisting einfach als Datei senden als wenn man sie eintippen würde. Genauso kann man ein Listing mitschreiben lassen.

![minicom](https://github.com/petersieg/MFA/blob/master/MFA-minicom.JPG)

![rs232](https://github.com/petersieg/MFA/blob/master/MFA-RS232.JPG)

