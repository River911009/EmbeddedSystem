/**
 * Recycling platfrom Arduino code
 * it's developing version for several sensors input and decise an platform angle by control two servo-motors.
 * this code doesn't checked, should debug on Arduino. its structure is what i think, should works fine.
 * hardware circuit connection, can check tinkercad link: [ https://www.tinkercad.com/things/lwp72w4AnAf ]
 * coding by Riviere on 30 June.
 */

#include <servo.h>

// types of object
#define types 4
// change following lines if hardware change
#define motor_1  5
#define motor_2  6
// for adding sensor, duplicate the next command
#define sensor_entry 2
#define sensor_1 3

// result table
int angleOfMotor_1[types]={70,90,110,90};  // necessary to change those angle values
int angleOfMotor_2[types]={90,70,90,110};

// each "angle_x" object controls a motor
Servo angle_1,angle_2;

// for showing angles on serial monitor
int value_1,value_2;


void setup(void){
  angle_1.attach(motor_1);
  angle_2.attach(motor_2);

  // initial serial monitor for debuging
  Serial.begin(9600);
  
  // initial sensor pins
  pinMode(sensor_entry,INPUT);
}

void loop(void){
  if(digitalRead(sensor_entry)){
    Serial.println("Starting determine...");
    
    // call sub-function to determine
    ans=determine();
    
    // write angles into two motors by check the result table
    angle_1.write(angleOfMotor_1[ans]);
    angle_2.write(angleOfMotor_2[ans]);
    
    // wait a while, until object dropped
    delay(2000);
    
    // return to centre
    angle_1.write(90);
    angle_2.write(90);
  }
  delay(100);
}
