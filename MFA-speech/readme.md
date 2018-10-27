# How to make a speech card out of a universal parallel card with 8255 interface chip

Erläuterungen zur Sprachausgabe:

Verwendet wurde die universelle, parallele Schnittstelle mit 8255.
Mode 1 für Port A.
Steuerwort= 160d
Adresse auf 5x.
= Steuerwortadresse: 53h = 83d
= Port A: 50h = 80d

Verbindungen:
Bedeut.- Ard.- 8255
-------------------
STROBE - 2   - PC7
ACK    - 1   - PC6
D0-D3  - 4-7 - A0-A3
D4-D7  - 8-11- A4-A7

Im Basic dann erst:
OUT 83,160 : REM Steuerwort
dann..
OUT 80,xxx

