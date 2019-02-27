# Nachbau serielle Schnittstelle mit 8251

Etwas minimalisierte Schaltung.

An den 8x Pins liegen von untern an: GND; Tx; Rx; ...)

Aufgebaut und getestet lt. Aufbautest:

```
F800  3E 2A       PRUEF:  MVI A,2A    ; '*'
F802  CD 2108             CALL 0821   ; CASO - CASS OUT
F805  CD EF07             CALL 07EF   ; CASI - CASS IN
F808  CD 5200             CALL 0052   ; WCHR - Write char
F80B  C3 00F8             JMP PRUEF
                          END

```
Aufgebaute Karte:

![ser-karte](https://github.com/petersieg/MFA/blob/master/ser-if/rs232-karte.JPG)

Test:
![ser-test](https://github.com/petersieg/MFA/blob/master/ser-if/rs232-test.JPG)




