//include libraries
#include <SoftwareSerial.h>
#include <Stepper.h>

SoftwareSerial esp8266(3, 2); //RX pin = 3, TX pin = 2

//definition of variables
#define DEBUG true //show messages between ESP8266 and Arduino in serial port
const int stepsPerRevolution = 500;
int state = 0;
long timer;

Stepper rightStepper(stepsPerRevolution, 8,10,9,11);
Stepper leftStepper(stepsPerRevolution, 4,6,5,7);

void setup()
{
  //start communication
  Serial.begin(9600);
 
  
  rightStepper.setSpeed(60);
  leftStepper.setSpeed(60);
  
}

void loop()
{

if(millis()-timer>5000){
  timer = millis();
  state++;
  Serial.println(state);
}
if(state>4){
  state=0;
}


  if(state==0){
    rightStepper.step(0);
    leftStepper.step(0);
  }
  // Forward
  if (state==1){
    rightStepper.step(1);
    leftStepper.step(-1);
  }

  //Right
  if (state==2){
    rightStepper.step(-1);
    leftStepper.step(-1);
  }

  //Back
  if (state==3){
    rightStepper.step(-1);
    leftStepper.step(1);
  }

  //Left
  if (state==4){
    rightStepper.step(1);
    leftStepper.step(1);
  }
}

