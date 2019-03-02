# Nachbau der Programmierbaren Parallelschnittstelle mit 8255 Chip.

Orig. Schaltplan siehe Doku zum MFA System.

TESTED now! Works, but some flaws in the pcb:

A0-A3 at 74LS85 are in reversed order.

View from parts placement - VG64 is on the left side:
```
A A A A
7 6 5 4

R R R R
4 3 2 1
```

10x Pinheader on left outer position has the following connections from top to bottom when VG64 is to the right side (It should be PC7-NC-PA7..PA0-NC-PC6):

N.C

PC6 - (ACK)

PA0

PA1

PA2

PA3

PA4

PA5

PA6

PA7

PC7 - (Strobe)

N.C

![sp1](https://github.com/petersieg/MFA/blob/master/par-io/pcb.png)

Debug session closeups:

![dbg1](https://github.com/petersieg/MFA/blob/master/par-io/debug1.jpg)

![dbg2](https://github.com/petersieg/MFA/blob/master/par-io/debug2.jpg)

Ready with Talkie/Speech attached:

![rdy](https://github.com/petersieg/MFA/blob/master/par-io/ready.jpg)

