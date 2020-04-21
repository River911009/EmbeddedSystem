#include "config.h"

int __speed = 100;

int latchPin = 12;
int clockPin = 4;
int dataPin = 8;
void setup() {
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(7,OUTPUT);


  pinMode(3,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  
}
void loop() {     
    byte direct = 0b00101110;     // Qa~h  backward

    __speed = 50;     // set speed to 20%


    digitalWrite(7,LOW);
  for (int led = 0; led < 8; led++) {
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, direct); 
    digitalWrite(latchPin, HIGH);
    delay(40);
  }

  analogWrite(3, map(__speed, 0, 100, 0, 255) );
  analogWrite(5, map(__speed, 0, 100, 0, 255) );
  analogWrite(6, map(__speed, 0, 100, 0, 255) );
  analogWrite(9, map(__speed, 0, 100, 0, 255) );
  analogWrite(10, map(__speed, 0, 100, 0, 255) );
  analogWrite(11, map(__speed, 0, 100, 0, 255) );
  
  delay(2000);
}

