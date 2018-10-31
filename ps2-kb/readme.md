# Howto connect a PS/2 keyboard with the help of arduino

Just upload this simple sketch (UNO is enough) and connect a PS/2 adapter und wire the D1-D7+STB/STROBE and GND to the sub-d 15 connector.
Do NOT use the +5V from the MFA at this connector from Pin 9 - it measured +12V in my system!! It hasn't worked for me, but now I know, why it killed one Uno! Use external power through USB port (5V).

As always, use at your own risc. Carefully check connections before power it on.

![ps2-kb](https://github.com/petersieg/MFA/blob/master/ps2-kb/ps-kb-2.JPG)

Verbindungen nach hier: Steckeranschlussstift:

![pins](https://github.com/petersieg/MFA/blob/master/ps2-kb/Pin%20Belegung.png)
