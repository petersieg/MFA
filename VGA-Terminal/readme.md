# VGA-Terminal for MFA

Software is complete work off: 

Jan Roesler           jan.roesler@tu-bs.de 

Sebastian Brueckner  se.brueckner@tu-bs.de

Link to mikrocontroller Thread: 
https://www.mikrocontroller.net/topic/143445

// Attention: ONLY atmeg644P will work!

// avrdude -c usbasp -p m644p -U flash:w:dmm_vga.hex:i

// avrdude -c usbasp -p m644p -U lfuse:w:0xE0:m -U hfuse:w:0xD9:m


![MFA-VGA1](https://github.com/petersieg/MFA/blob/master/VGA-Terminal/MFA-VGA-Karte.JPG)

