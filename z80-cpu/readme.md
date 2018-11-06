# Z80 CPU für MFA Computer

Work in progress!!

In der 2ten Hälfte 2018 bekam der VzEkC die Möglichkeit einige MFA Computer zu bekommen. 
Das regte die Arbeit mit dem System als solchen, die Sammlung von Dokumentationen und die 
Gedanken zur Erweiterung/Vervollständigung des Systems an.

Eine Idee dazu war es eine alternative CPU zur Verfügung zu stellen.

Dazu wurde ein vorhandenes Design eines Einplatinencomputers (EPC) von Bernd Uhlmann verwendet.
Der zu verwendende EPC musste seriell kommunizieren und das Monitorprogramm im Source verfügbar sein.

Die Idee: EPC einfach mit Strom versorgen und seriell Rx+Tx mit dem Bus verbinden, um den Baugruppenträger 
inkl. Stromversorgung und die Videokarte/Tastatur als Aus-/Eingabe zu nutzen imd einem ersten Schritt.

In einem zweiten Schritt dann ggf. die vorhandenen I/O Baugruppen nutzbar zu machen.

Danke der Arbeiten von Georg Schäfer am Monitor ist Schritt 1 inzwischen funktionsfähig. Stand Nov. 2018.


