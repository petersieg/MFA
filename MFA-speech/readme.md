# How to make a speech card out of a universal parallel card with 8255 interface chip

Irgendwie haben die mich immer fasziniert.. früher wurde da ein spezieller Sprachchip (SC-01/SP256?) eingesetzt - der heute wohl schwer zu bekommen sein dürfte.


Über ebay gibt es Arduino Speech Module, die aber sehr teuer sind (40-50€).

Daher habe ich mal etwas evtl. passendes für Arduino gesucht (google: arduino speech tts):



1. Talkie

Link: https://github.com/going-digital/Talkie

Speech Probe: https://youtu.be/iWTzGObO9WI



Klingt ziemlich gut! Und hat einen Homecomputer Hintergrund ;-)



2. TTS (TextToSpeech)

Link: http://forum.arduino.cc/index.….msg354746.html#msg354746

https://circuits4you.com/2016/…ext-to-speech-on-arduino/

Speech Probe: https://youtu.be/7X0umBbWd_g



Klingt ziemlich scheiße! - aber irgendwie auch sehr interessant/schlecht.

Ich habe von Pin 10 einen 100nf Kondensator nach Masse geschaltet und Audio von Pin 10 über einen 10k Ohm Widerstand entnommen.



Weitere Links:

https://github.com/jscrane/TTS

---

Ich habe mich dann für Talkie entschieden.

´´´
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
´´´

