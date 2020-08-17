/*MFA PS/2 Keyboard interface
  (c) 2018 Peter Sieg - released under GNU GPL V2
  
  PS2Keyboard requries both pins specified for begin()

  keyboard.begin(data_pin, irq_pin);
  
  Valid irq pins:
     Arduino:      2, 3
     Arduino Mega: 2, 3, 18, 19, 20, 21
     Teensy 1.0:   0, 1, 2, 3, 4, 6, 7, 16
     Teensy 2.0:   5, 6, 7, 8
     Teensy++ 1.0: 0, 1, 2, 3, 18, 19, 36, 37
     Teensy++ 2.0: 0, 1, 2, 3, 18, 19, 36, 37
     Sanguino:     2, 10, 11
  
  for more information you can read the original wiki in arduino.cc
  at http://www.arduino.cc/playground/Main/PS2Keyboard
  or http://www.pjrc.com/teensy/td_libs_PS2Keyboard.html
 
Attention: Do NOT use the +5V supply from MFA at ASCII plug!
           This seems to not work and might kill your arduino!

*/
   
#include <PS2Keyboard.h>

const int DataPin = 11;
const int IRQpin =  3;
#define STROBE 2
#define D1 4
#define D2 5
#define D3 6
#define D4 7
#define D5 8
#define D6 9
#define D7 10

PS2Keyboard keyboard;

void setup() {

  // set output pins
  pinMode(D1, OUTPUT);
  digitalWrite(D1, LOW);
  pinMode(D2, OUTPUT);
  digitalWrite(D2, LOW);
  pinMode(D3, OUTPUT);
  digitalWrite(D3, LOW);
  pinMode(D4, OUTPUT);
  digitalWrite(D4, LOW);
  pinMode(D5, OUTPUT);
  digitalWrite(D5, LOW);
  pinMode(D6, OUTPUT);
  digitalWrite(D6, LOW);
  pinMode(D7, OUTPUT);
  digitalWrite(D7, LOW);
  pinMode(STROBE, OUTPUT);
  digitalWrite(STROBE, LOW);
 
  keyboard.begin(DataPin, IRQpin);
  delay(1000);
  
  Serial.begin(9600);
  Serial.println("Keyboard Output:");
}

void loop() {
  if (keyboard.available()) {
    
    // read the next key
    char c = keyboard.read();
    
    // check for some of the special keys
    /*if (c == PS2_ENTER) {
      Serial.println();
    } else if (c == PS2_TAB) {
      Serial.print("[Tab]");
    } else if (c == PS2_ESC) {
      Serial.print("[ESC]");
    } else if (c == PS2_PAGEDOWN) {
      Serial.print("[PgDn]");
    } else if (c == PS2_PAGEUP) {
      Serial.print("[PgUp]");
    } else if (c == PS2_LEFTARROW) {
      Serial.print("[Left]");
    } else if (c == PS2_RIGHTARROW) {
      Serial.print("[Right]");
    } else if (c == PS2_UPARROW) {
      Serial.print("[Up]");
    } else if (c == PS2_DOWNARROW) {
      Serial.print("[Down]");
    } else if (c == PS2_DELETE) {
      Serial.print("[Del]");
    } else {
    */  
    // otherwise, just print all characters
      
    Serial.print(c); Serial.print(" = ");

    if (c & 64)  Serial.print('1'); else Serial.print('0');
    if (c & 32)  Serial.print('1'); else Serial.print('0');
    if (c & 16)  Serial.print('1'); else Serial.print('0');
    if (c & 8)   Serial.print('1'); else Serial.print('0');
    if (c & 4)   Serial.print('1'); else Serial.print('0');
    if (c & 2)   Serial.print('1'); else Serial.print('0');
    if (c & 1)   Serial.print('1'); else Serial.print('0');
    Serial.println();
    
    // output to parallel port
    if (c & 64)  digitalWrite(D7, HIGH); else digitalWrite(D7, LOW);
    if (c & 32)  digitalWrite(D6, HIGH); else digitalWrite(D6, LOW);
    if (c & 16)  digitalWrite(D5, HIGH); else digitalWrite(D5, LOW);
    if (c & 8)   digitalWrite(D4, HIGH); else digitalWrite(D4, LOW);
    if (c & 4)   digitalWrite(D3, HIGH); else digitalWrite(D3, LOW);
    if (c & 2)   digitalWrite(D2, HIGH); else digitalWrite(D2, LOW);
    if (c & 1)   digitalWrite(D1, HIGH); else digitalWrite(D1, LOW);

    // Strobe
    delay(30);
    digitalWrite(STROBE, HIGH);
    delay(20);
    digitalWrite(STROBE, LOW);
    delay(50);
    
    //}
  }
}
