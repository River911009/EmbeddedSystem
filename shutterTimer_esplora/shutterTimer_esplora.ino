#include <Esplora.h>
#include <SPI.h>
#include <TFT.h>

char printOut[6];
uint16_t raw=0, level=0;
long t;

void reDraw(int t){
  EsploraTFT.background(32,128,32); // (B,G,R)

  EsploraTFT.stroke(255,255,255);
  EsploraTFT.setTextSize(3);
  EsploraTFT.text("ms",125,8);

  String str=String(t);
  str.toCharArray(printOut,6);
  EsploraTFT.setTextSize(4);
  EsploraTFT.text(printOut,0,0);
}

void sensorInitial(){
  digitalWrite(A0, HIGH);
  digitalWrite(A1, LOW);
  digitalWrite(A2, HIGH);
  digitalWrite(A3, LOW);
}

uint8_t catchTime(){
  long  x=0;
  short timeout=millis();

  while(level > raw){
    x=micros();
    if((t-timeout) > 3000) return(0);
  }
  timeout=millis();
  while(level < raw){
    if((micros()-timeout) > 3000) return(0);
  }
  t=micros()-x;
}

void setup() {
  sensorInitial();
  EsploraTFT.begin();
  Serial.begin(115200);
  while(!Serial);
}

void loop() {
//  reDraw(30000);
//  delay(500);

  if(Esplora.readJoystickButton()) catchTime();
  
  digitalWrite(A0, LOW);
  level=analogRead(A4);
  
  digitalWrite(A0, HIGH);
  raw=analogRead(A4);
  
}
