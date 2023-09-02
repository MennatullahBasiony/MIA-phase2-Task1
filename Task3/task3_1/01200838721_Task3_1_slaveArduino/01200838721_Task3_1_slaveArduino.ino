//including needed library for communication
#include <Wire.h>

//initializing needed variables
int btn1 = 3, btn2 = 7, state = 0;

void setup()
{
  //initializing pins of both buttons as input pullup
  pinMode(btn1, INPUT_PULLUP);
  pinMode(btn2, INPUT_PULLUP);
  
  //initiate communication as slave with address 10
  Wire.begin(10);
  
  //initiate serial communication
  Serial.begin(9600);
}

void loop()
{
  //on receiving request call function sendState
  Wire.onRequest(sendState);
  
  //case no button is pressed
  if(digitalRead(btn1) && digitalRead(btn2))  state = 0;
  
  //case first button is pressed
  else if(!digitalRead(btn1) && digitalRead(btn2))  state = 1;
    
  //case second button is pressed
  else if(digitalRead(btn1) && !digitalRead(btn2))  state = 2;
    
  //case both buttons are pressed
  else if(!digitalRead(btn1) && !digitalRead(btn2)) state = 3;
    
  //print state on serial monitor
  Serial.println(state);
  
}

//function to call on request
void sendState()
{  
  //send state
  Wire.write(state);
}
