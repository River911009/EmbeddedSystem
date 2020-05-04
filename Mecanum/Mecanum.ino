#include <SoftwareSerial.h>
#include "config.h"
#define __SPEED__ 100
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
//  analogWrite(PWM1A, map(__speed, 0, 100, 0, 255) );
//  analogWrite(PWM1B, map(__speed, 0, 100, 0, 255) );
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
//  pinMode(PWM1A,OUTPUT);
//  pinMode(PWM1B,OUTPUT);
  pinMode(PWM2A,OUTPUT);
}
SoftwareSerial BT04(9,10);
byte command=0;

void setup() {
  motorInitial();
  Serial.begin(9600);
  BT04.begin(9600);
}

void loop() {
  if(Serial.available()){
    BT04.write(Serial.read());
  }
  
  if(BT04.available()){
    command=BT04.read();
  }

      switch(command){
      case 49:
        setMove(Forward, __SPEED__);delay(__time__); break;
      case 50:
        setMove(Backward, __SPEED__);delay(__time__); break;
      case 51:
        setMove(Right, __SPEED__); delay(__time__);break;
      case 52:
        setMove(Left, __SPEED__); delay(__time__);break;
      case 53:
        setMove(LeftForward, __SPEED__); delay(__time__);break;
      case 54:
        setMove(RightForward, __SPEED__);delay(__time__); break;
      case 55:
        setMove(RightBackward, __SPEED__); delay(__time__);break;
      case 56:
        setMove(LeftBackward, __SPEED__); delay(__time__);break;
      case 57:
        setMove(Clockwisespin, __SPEED__);delay(__time__); break;
      case 58:
        setMove(Counterclockwisespin, __SPEED__);delay(__time__); break;
        
      default:
      setMove(0,0);break;
    }
//delay(1000);
  setMove(0, 0);
  command=0;
}
