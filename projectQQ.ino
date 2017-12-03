//include libraries
#include <SoftwareSerial.h>
#include <Stepper.h>

SoftwareSerial esp8266(3, 2); //RX pin = 3, TX pin = 2

//definition of variables
#define DEBUG true //show messages between ESP8266 and Arduino in serial port
const int stepsPerRevolution = 500;


Stepper rightStepper(stepsPerRevolution, 8,10,9,11);
//Stepper leftStepper(stepsPerRevolution, 4,6,5,7);

//*****
//SETUP
//*****
void setup()
{
  //start communication
  Serial.begin(9600);
  esp8266.begin(19200);
  
 
for ( int j = 60 ; j <= 100 ; j=j+5) {
Serial.println(j);
 for ( int i = 0 ; i <200 ; i ++) {
 rightStepper.setSpeed(j);
 rightStepper.step(1);
  }
}
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


  
for ( int j = 60 ; j <= 100 ; j=j+5) {
Serial.println(j);
 for ( int i = 0 ; i <200 ; i ++) {
 rightStepper.setSpeed(j);
 rightStepper.step(1);
  }
}


  for ( int j = 60 ; j <= 100 ; j=j+5) {
Serial.println(j);
 for ( int i = 0 ; i <200 ; i ++) {
 rightStepper.setSpeed(j);
 rightStepper.step(-1);
  }
  }


  
}
