# Z80 CPU für MFA Computer

Work in progress!!

In der 2ten Hälfte 2018 bekam der VzEkC die Möglichkeit einige MFA Computer zu bekommen. 
Das regte die Arbeit mit dem System als solchen, die Sammlung von Dokumentationen und die 
Gedanken zur Erweiterung/Vervollständigung des Systems an.

Eine Idee dazu war es eine alternative CPU zur Verfügung zu stellen.

Dazu wurde ein vorhandenes Design eines Einplatinencomputers (EPC) von Dr. Bernd Uhlmann verwendet:

http://www.vaxman.de/projects/Z80_mini/index.html

http://www.vaxman.de/projects/tiny_z80/


Der zu verwendende EPC musste seriell kommunizieren und das Monitorprogramm im Source verfügbar sein.
Dies erfüllte obiges Projekt und als Zugabe hatte das Monitorprogramm noch einen Disassembler und einen 
Forth Interpreter.

Die Idee: EPC einfach mit Strom versorgen und seriell Rx+Tx mit dem Bus verbinden, um den Baugruppenträger 
inkl. Stromversorgung und die Videokarte/Tastatur als Aus-/Eingabe zu nutzen in einem ersten Schritt.

In einem zweiten Schritt dann ggf. die vorhandenen I/O Baugruppen nutzbar zu machen.

Wir wir schnell heraus fanden benötigt die Videokarte noch einen 2MHz Takt an Pin 2a! Daher entschlossen wir uns die CPU
mit eben diesen 2MHz anstatt der 4MHz die vorgesehen waren zu versorgen, um dann den Takt an Pin 2a zur Verfügung stellen
zu können.

Danke der Arbeiten von Georg Schäfer am Monitor ist Schritt 1 inzwischen funktionsfähig. Stand Nov. 2018.

Georg hatte Kontakt mit Dr. Bernd Uhlmann und wir dürfen sein Design und das Monitorprogramm hier und im Forum des VzEkC für 
Hobbyzwecke verwenden.

Link auf VzEkC Forums Seite:

https://forum.classic-computing.de/forum/index.php?thread/14731-mfa-gedanken-f%C3%BCr-eine-z80-cpu-karte/

```
;  Small monitor for the Z80 single board computer consisting of 32 kB ROM 
; ($0000 to $ffff), 32 kB RAM ($8000 to $ffff) and a 16c550 UART.
;
; B. Ulmann, 28-SEP-2011, 29-SEP-2011, 01-OCT-2011, 02-OCT-2011, 30-OCT-2011,
;            01-NOV-2011, 02-NOV-2011, 03-NOV-2011, 06/07/08-JAN-2012
; I. Kloeckl, 06/07/08-JAN-2012 (FAT implementation for reading files)
; B. Ulmann, 14-JAN-2011 
;
; 07-MAR-2012: Fabio Zanicotti spotted an error in the ide_get_id-routine - 
;              the value $0a should have been written to ide_lba3 but was
;              instead written into ide_status_cmd (I am quite puzzled why
;              the routine worked nevertheless). This has been corrected. :-)
;
; B. Ulmann, 20-MAY-2012 port to N8VEM - no IDE support at the moment 
;            27-MAY-2012 PPIDE support for N8VEM
;            29-MAY-2012 New system call uart_status introduced (used by the
;                        4th interpreter)
;            01-JUN-2012 CTRL-Y introduced
;            03-JUN-2012 F/R command added, UART initialization changed
;            06-JUN-2012 CAMEL-Forth added
;            07-JUN-2012 Minor bug fixes (load routine), added rom2ram
;            16-JUN-2012 stroup added, CAMEL Forth modified to use gets etc.
;            12-MAY-2013 Added support for the old homebrew Z80 computer.
;            20-MAY-2013 Added BASIC-subsystem.
;            05-JUN-2013 Added John Kerr's Z80 disassembler.
;            28-JUN-2013 Removed BASIC-support for the Z80mini
;
; G. Schäfer, 25-OCT-2018 Fixes to use the monitor on the MFA Video Card -
;                         this includes optimization of the output for 64x16 
;                         characters and a serial connection with 1200 7E2.
;                         To be able to use more I/O-ports the 16550 chip select 
;                         is connected with A7, so the UART is adressed at 80
;                         Routine gets changed to ignore LF instead of CR
```

![z80-mfa](https://github.com/petersieg/MFA/blob/master/z80-cpu/MFA-Z80.JPG)

![z80-mon](https://github.com/petersieg/MFA/blob/master/z80-cpu/Z80-Monitor.JPG)





