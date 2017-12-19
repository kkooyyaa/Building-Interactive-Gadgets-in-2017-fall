//include libraries
#include <SoftwareSerial.h>
#include <Stepper.h>

SoftwareSerial esp8266(3, 2); //RX pin = 3, TX pin = 2

//definition of variables
#define DEBUG true //show messages between ESP8266 and Arduino in serial port
const int stepsPerRevolution = 500;


Stepper rightStepper(stepsPerRevolution, 8,10,9,11);
Stepper leftStepper(stepsPerRevolution, 4,6,5,7);

//*****
//SETUP
//*****
void setup()
{
  //start communication
  Serial.begin(9600);
  esp8266.begin(19200);
  
 
/*
double plus = 1;
 for ( double j = 115 ; j < 187.5; j= j + plus) {
  plus = plus / 5 * 3+0.001;
Serial.println(j);
 for ( int i = 0 ; i <100 ; i ++) {
 rightStepper.setSpeed(j);
 rightStepper.step(1);
  }
  }
*/

 
  
  
}

void loop()
{

int mode = 0 ;

  int state = 1 ;
//going forward
  if ( state == 1) {
    state=state+1;
  for ( int j = 50 ; j <= 100 ; j=j+5) {
  Serial.println(j);
    Serial.println(state-1);
   for ( int i = 0 ; i <200 ; i ++) {
    rightStepper.setSpeed(j);
    rightStepper.step(1);
    leftStepper.setSpeed(j);
    leftStepper.step(1);
   }
  } 
  }

//going back 
  if ( state == 2) {
    state++;
  for ( int j = 50 ; j <= 100 ; j=j+5) {
  Serial.println(j);
    Serial.println(state-1);
   for ( int i = 0 ; i <200 ; i ++) {
    rightStepper.setSpeed(j);
    rightStepper.step(-1);
    leftStepper.setSpeed(j);
    leftStepper.step(-1);
   }
  } 
  }

//turning left 
  if ( state == 3) {
    state++;
  for ( int j = 50 ; j <= 100 ; j=j+5) {
  Serial.println(j);
    Serial.println(state-1);
   for ( int i = 0 ; i <200 ; i ++) {
    rightStepper.setSpeed(j);
    rightStepper.step(1);
    if (  mode == 1 ) {
    leftStepper.setSpeed(j);
    leftStepper.step(1);
    mode = 0 ;
    }
    else
    mode = 1;
   }
  } 
  }

//turn right
mode = 1 ;
 if ( state == 4) {
  state = 1;
  for ( int j = 50 ; j <= 100 ; j=j+5) {
  Serial.println(j);
    Serial.println(state-1);
   for ( int i = 0 ; i <200 ; i ++) {
    leftStepper.setSpeed(j);
    leftStepper.step(1);
       if (  mode == 1 ) {
    rightStepper.setSpeed(j);
    rightStepper.step(1);
    mode = 0 ;
    }
    else
    mode = 1;
   
   }
  } 
  }

  




  
}
