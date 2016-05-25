/* 
 * this mouse controller builds on the excellent Adafruit examples 
 * at https://github.com/adafruit/Pro_Trinket_USB_Mouse
 */
#include <ProTrinketMouse.h>

const int axisHatX = 0;
const int axisHatY = 1;

const int blue = 5;
const int green = 6;
const int red = 8;

const int buttonA = 9;     
const int buttonB = 10;     
const int buttonC = 11;     
const int trinketRed =  13;  

int buttonAState = 0;     
int buttonBState = 0;
int buttonCState = 0;

const int LED_ON = 0;
const int LED_OFF = 1;

void setup(){
  pinMode(axisHatX, INPUT);
  pinMode(axisHatY, INPUT);

  // let u
  pinMode(trinketRed, OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
  
  // set up the buttons
  pinMode(buttonA, INPUT);
  pinMode(buttonB, INPUT);
  pinMode(buttonC, INPUT);

  TrinketMouse.begin();
}
  
void loop(){
  
  int A = digitalRead(buttonA);
  int B = digitalRead(buttonB);
  int C = digitalRead(buttonC);
  
  if (A == 0){
   //send a mouse click signal here
  }
  
  if (B == 0){
   //send a mouse click signal here
  }
  
  if (C == 0){
   //send a mouse click signal here    
  } 

  if (A == 0 || B == 0  || C == 0){
    digitalWrite(green, LED_ON); 
  } else {
    digitalWrite(green, LED_OFF); 
  }

  int processedX = readAxis(axisHatX);
  int processedY = -readAxis(axisHatY);

  if(processedX > 0){
    digitalWrite(blue, LED_ON);    
  } else if (processedX < 0) {
    digitalWrite(red, LED_ON);
  } else {
    digitalWrite(red, LED_OFF);  
    digitalWrite(blue, LED_OFF);
  }
  
  if(processedY > 0){
    //pass
  } else if (processedY < 0) {
    //pass
  }

  TrinketMouse.move(processedX, processedY, 0, 0);
  delay(5); //mustcheck in every 10ms or less or OS will conclude device is gone
}

int readAxis(int thisAxis) { 
  int reading = analogRead(thisAxis);  // read the analog input
  
  //for an xbox controller the standard range is [-32768, 32767]
  //the trinket reads the adafruit joystick at [0, 1023]
  
  int distance = reading - 512;
  if (abs(distance) > 80){
    return distance/32;
  }
  
  return 0;
}
