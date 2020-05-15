#include "config.h"



void initial(void){
  pinMode(__pump__,OUTPUT);
  pinMode(__valve__,OUTPUT);
  pinMode(__heater__,OUTPUT);
  pinMode(__indicator__,OUTPUT);
  pinMode(__funcButton__,INPUT_PULLUP);

  digitalWrite(__pump__,LOW);
  digitalWrite(__valve__,LOW);
  digitalWrite(__heater__,LOW);
  digitalWrite(__indicator__,LOW);
}

uint8_t setTemperature(uint8_t temp){}
uint8_t getTemperature(void){}
uint8_t setBrewTime(uint8_t t){}
uint8_t getBrewTime(void){}
