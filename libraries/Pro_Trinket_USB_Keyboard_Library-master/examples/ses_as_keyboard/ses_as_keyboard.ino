/* 
 * this keyboard controller builds on the excellent Adafruit examples 
 * at https://github.com/adafruit/Pro_Trinket_USB_Keyboard_Library
 */

#include <ProTrinketKeyboard.h>

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

  TrinketKeyboard.begin();  
}
  
void loop(){
  TrinketKeyboard.poll();

  int rxReading = readAxis(axisHatX, 0);
  int ryReading = readAxis(axisHatY, 0); 

   int A = digitalRead(buttonA);
   int B = digitalRead(buttonB);
   int C = digitalRead(buttonC);
   
   if (A == 0){
     TrinketKeyboard.pressKey(0, KEYCODE_J);
     TrinketKeyboard.pressKey(0, 0);
   }

   if (B == 0){
     TrinketKeyboard.pressKey(0, KEYCODE_K);
     TrinketKeyboard.pressKey(0, 0);
   }

   if (C == 0){
     TrinketKeyboard.pressKey(0, KEYCODE_L);
     TrinketKeyboard.pressKey(0, 0);     
   } 

   if (A == 0 || B == 0  || C == 0){
      digitalWrite(green, LED_ON); 
   } else {
      digitalWrite(green, LED_OFF); 
   }

  if(rxReading > 0){
    digitalWrite(blue, LED_ON);    
    TrinketKeyboard.pressKey(0, KEYCODE_D);
    //TrinketKeyboard.pressKey(0, 0);
  } else if (rxReading < 0) {
    digitalWrite(red, LED_ON);
    TrinketKeyboard.pressKey(0, KEYCODE_A); 
    //TrinketKeyboard.pressKey(0, 0); 
  } else {
    digitalWrite(red, LED_OFF);  
    digitalWrite(blue, LED_OFF);
  }
  
  if(ryReading > 0){
    TrinketKeyboard.pressKey(0, KEYCODE_W);
  } else if (ryReading < 0) {
    TrinketKeyboard.pressKey(0, KEYCODE_S);
  }

  delay(5); //mustcheck in every 10ms or less or OS will conclude device is gone
  TrinketKeyboard.pressKey(0, 0);

}

int readAxis(int thisAxis, int offset) { 
  int reading = analogRead(thisAxis);  // read the analog input

  reading += offset;

  //for an xbox controller the standard range is [-32768, 32767]
  //the trinket reads the adafruit joystick at [0, 1023]
  
  int distance = reading - 512;
  if (abs(distance) > 80){
    return distance;
  }
  
  return 0;
}
