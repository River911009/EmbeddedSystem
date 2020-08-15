int   currentWheel; // add one flag to switch on four wheels.

long  currentTime,elapsedTime,previousTime;

int   setpoint[4];
int   inpout[4];
int   error[4],cumError[4],rateError[4],lastError[4];
int   output[4];

float kp[4],ki[4],kd[4];


// ...

void loop(void){
  // the if...else... section
  // switch the stage of four different wheels
  // cause four wheels have different kp,ki and kd
  // we seperate processing time to calculate each
  // PID controller for those wheels.
  if(currentWheel>4){
    currentWheel=0;
  }
  else{
    currentWheel++;
  }

  // put all the commands into this section below
  // and each relative variables should be change
  // to an component of array.

  // i.e.
  // counter[0],input[0],kp[0],ki[0],kd[0],output[0] for front-left wheel


  // start PID calculating below
  currentTime=millis();
  elapsedTime=currentTime-previousTime;

  input[currentWheel]=doSomeThingToGetInput(currentWheel);
  error[currentWheel]=setpoint[currentWheel]-input[currentWheel];
  cumError[currentWheel]+=error[currentWheel]*elapsedTime;
  rateError[currentWheel]=(error[currentWheel]-lastError[currentWheel])/elapsedTime;

  output[currentWheel] \
    =kp[currentWheel]*error[currentWheel] \
    +ki[currentWheel]*cumError[currentWheel] \
    +kd[currentWheel]*rateError[currentWheel];

  lastError[currentWheel]=error[currentWheel];
  previousTime=currentTime;
  // PID calculate end


  // output limite from 0-255
  if(output[currentWheel]>255){
    output[currentWheel]=255;
  }
  else if(output[currentWheel]<0){
    output[currentWheel]=0;
  }

  // output to each wheel
  digitalWrite(wheel_pwm_pin, output[currentWheel]);


  // if need bluetooth communicate
  // do NOT let sub-function claim too much time
  if(Serial.available()){
    ...
  }
  
}
