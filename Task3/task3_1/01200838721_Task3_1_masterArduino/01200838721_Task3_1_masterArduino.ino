//including library for communication
#include <Wire.h>

//inializing needed variables
int led = 5, state = 0;

void setup()
{
  //initializing led pin as output
  pinMode(led, OUTPUT);
  
  //start communication as master
  Wire.begin();
  
  //initialize Serial communication
  Serial.begin(9600);
  
  //initializing led with 0 state
  analogWrite(led, state);
}

void loop()
{
  //request from slave with address 10, 2 bytes
  Wire.requestFrom(10, 2);
  
  //check for data in receiver buffer
  if(Wire.available())
  {
    //saving received data in state variable
    state = Wire.read();
  }

  //print current state
  Serial.println(state);
  
  //deciding action on each state
  switch(state)
  {
    //case no button is pressed
    case 0:
        analogWrite(led, 0);
        Serial.println("No Massege");
      break;
    
    //case first button is pressed
    case 1: 
        analogWrite(led, 127);
        Serial.println("Vector Focused");
      break;
    
  //case second button is pressed
    case 2: 
        analogWrite(led, 191);
        Serial.println("Vector distracted");
      break;

    //case both buttons are pressed
    case 3: 
        analogWrite(led, 255);
        Serial.println("Glitch");
      break;
  }
  
}
