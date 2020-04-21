#include "config.h"

byte direct=0b00010000;

void setup() {
  // pin initial
  for(int i=3;i<=12;i++) pinMode(i,OUTPUT);

  // 74595 commanding
  digitalWrite(DIR_EN,LOW);
  for(int i=0;i<8;i++){
    digitalWrite(DIR_SER,((direct & 1)==1)? HIGH:LOW);
    delayMicroseconds(1);
    digitalWrite(DIR_CLK,LOW);
    delayMicroseconds(1);
    digitalWrite(DIR_CLK,HIGH);
    delayMicroseconds(1);
    direct = direct >> 1;
  }
  digitalWrite(DIR_LATCH,LOW);
  delayMicroseconds(1);
  digitalWrite(DIR_LATCH,HIGH);
  delayMicroseconds(1);
  digitalWrite(DIR_EN,HIGH);

  test=5;
}

void loop() {

}
