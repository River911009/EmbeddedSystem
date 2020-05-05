#include <SoftwareSerial.h>
#include "config.h"
#define __SPEED__ 60
#define __time__ 1000
void setMove(byte direct, byte __speed){
//    byte direct = Right;     // Qa~h  backward

//    __speed = 80;     // set speed to 80%

  digitalWrite(DIR_EN,LOW);
  for (int led = 0; led < 8; led++) {
    digitalWrite(DIR_LATCH, LOW);
    shiftOut(DIR_SER, DIR_CLK, LSBFIRST, direct); 
    digitalWrite(DIR_LATCH, HIGH);
    delay(40);
  }

  analogWrite(PWM2B, map(__speed, 0, 100, 0, 255) );
  analogWrite(PWM0B, map(__speed, 0, 100, 0, 255) );
  analogWrite(PWM0A, map(__speed, 0, 100, 0, 255) );
  analogWrite(PWM2A, map(__speed, 0, 100, 0, 255) );
}

void motorInitial(void){
  pinMode(DIR_LATCH, OUTPUT);
  pinMode(DIR_CLK, OUTPUT);
  pinMode(DIR_SER, OUTPUT);
  pinMode(DIR_EN,OUTPUT);
  
  pinMode(PWM2B,OUTPUT);
  pinMode(PWM0B,OUTPUT);
  pinMode(PWM0A,OUTPUT);
  pinMode(PWM2A,OUTPUT);
  analogWrite(PWM2B,0);
  analogWrite(PWM0B,0);
  analogWrite(PWM0A,0);
  analogWrite(PWM2A,0);
}
SoftwareSerial BT04(9,10);
byte command=0;

void setup() {
  motorInitial();
  Serial.begin(9600);
  BT04.begin(9600);
}

void loop() {
//  if(Serial.available()){
//    BT04.write(Serial.read());
//  }
  
  if(BT04.available()){
    command=BT04.read();
  }

  if (command == 'a')setMove(Forward,__SPEED__);
  if (command == 'b')setMove(Backward,__SPEED__);
  if (command == 'c')setMove(Right,__SPEED__);
  if (command == 'd')setMove(Left,__SPEED__);
  if (command == 'e')setMove(LeftForward,__SPEED__);
  if (command == 'f')setMove(RightForward,__SPEED__);
  if (command == 'g')setMove(RightBackward,__SPEED__);
  if (command == 'h')setMove(LeftBackward,__SPEED__);
  if (command == 'i')setMove(Clockwisespin,__SPEED__);
  if (command == 'j')setMove(0,0);
  

//  setMove(0, 0);
  command=0;
}
