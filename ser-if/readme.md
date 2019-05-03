# Nachbau serielle Schnittstelle mit 8251

Etwas minimalisierte Schaltung. Standard: 2400 8N1 bei Teiler 64:1 (bei 16:1 = 9600 8N1).

Aufgebaut und getestet lt. Aufbautest:

```
F800  3E 2A       PRUEF:  MVI A,2A    ; '*'
F802  CD 2108             CALL 0821   ; CASO - CASS OUT
F805  CD EF07             CALL 07EF   ; CASI - CASS IN
F808  CD 5200             CALL 0052   ; WCHR - Write char
F80B  C3 00F8             JMP PRUEF
                          END

```
DIP Adressselektion:
Draufsicht auf Bestückungsseite - VG64 Leiste liegt rechts:
```
A A A A
7 6 5 4

R R R R
4 3 2 1
```

8-pol Leiste von oben nach unten gesehen - VG64 Leiste liegt rechts (*=4k7 Pulldown):
```
+5V
RTS
CTS*
DTR
DSR*
RX
TX
GND
```

Aufgebaute Karte:

![ser-karte](https://github.com/petersieg/MFA/blob/master/ser-if/rs232-karte.JPG)

Test:
![ser-test](https://github.com/petersieg/MFA/blob/master/ser-if/rs232-test.JPG)




