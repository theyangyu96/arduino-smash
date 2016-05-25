/*
ProTrinketKeyboard example
For Pro Trinket (ATmega328 based Trinket) by Adafruit Industries
Please use library TrinketKeyboard for the ATtiny85 based Trinket
Version 1.0  2015-01-01 Initial Version derived from TrinketKeyBoardExample  Mike Barela
*/

#include <ProTrinketKeyboard.h>  // Ensure the library is installed

// Switches are connected from ground to these defined pins
const int PIN_BUTTON_A = 9;
const int PIN_BUTTON_B    = 10;
const int PIN_BUTTON_C    = 11;

const int xAxis  = 1;         // joystick X axis to A1 
const int yAxis  = 0;         // joystick Y axis to A0
// parameters for reading the joystick
int range = 12;               // output range of X or Y movement (zero to range)
int responseDelay = 5;        // response delay of the mouse, in ms
int threshold = range/3;      // resting threshold
int center = range/2;         // resting position value
const float powerValue = 1.4; // for exponential behavior, 1 < value < 2


bool arrow_pressed = false;
bool a_pressed = false;
bool b_pressed = false;
bool c_pressed = false;
void setup()
{
  // Declare button pins as inputs
  pinMode(PIN_BUTTON_A, INPUT);
  pinMode(PIN_BUTTON_B,    INPUT);
  pinMode(PIN_BUTTON_C,    INPUT);

  // setting input pins to high means turning on internal pull-up resistors
  digitalWrite(PIN_BUTTON_A, HIGH);
  digitalWrite(PIN_BUTTON_B,    HIGH);
  digitalWrite(PIN_BUTTON_C,    HIGH);
  // remember, the buttons are active-low, they read LOW when they are not pressed

  // start USB stuff
  TrinketKeyboard.begin();
}

int readAxis(int thisAxis) { 
  int reading = analogRead(thisAxis);  // read the analog input

  // map the reading from the analog input range to the output range
  reading = map(reading, 0, 1023, 0, range);

  // if the output reading is outside from the rest position threshold, use it
  int distance = center - reading;

  if (abs(distance) < threshold) { // if distance not to threshold, no move
    distance = 0;                  // prevents tiny jitters due to readings
  } 
  return distance;   // return the distance for this axis
}

void loop()
{
  TrinketKeyboard.poll();
  // the poll function must be called at least once every 10 ms
  // or cause a keystroke
  // if it is not, then the computer may think that the device
  // has stopped working, and give errors
  
  int xReading, yReading; // readings of the joystick movements
  //read joystick
  xReading = readAxis(yAxis);
  yReading = readAxis(xAxis);
  //joystick movement
  if(xReading > 0) {
      if (digitalRead(PIN_BUTTON_A) == LOW)
        TrinketKeyboard.pressKey(0, KEYCODE_ARROW_RIGHT, KEYCODE_A);
      else if (digitalRead(PIN_BUTTON_B) == LOW)
        TrinketKeyboard.pressKey(0, KEYCODE_ARROW_RIGHT, KEYCODE_S);
      else
        TrinketKeyboard.pressKey(0, KEYCODE_ARROW_RIGHT);
      arrow_pressed = true; 
   }
   else if(xReading < 0) {
      if (digitalRead(PIN_BUTTON_A) == LOW)
        TrinketKeyboard.pressKey(0, KEYCODE_ARROW_LEFT, KEYCODE_A);
      else if (digitalRead(PIN_BUTTON_B) == LOW)
        TrinketKeyboard.pressKey(0, KEYCODE_ARROW_LEFT, KEYCODE_S);
      else
        TrinketKeyboard.pressKey(0, KEYCODE_ARROW_LEFT);
      arrow_pressed = true; 
   }
   if(yReading > 0) {
      if (digitalRead(PIN_BUTTON_A) == LOW)
        TrinketKeyboard.pressKey(0, KEYCODE_ARROW_UP, KEYCODE_A);
      else if (digitalRead(PIN_BUTTON_B) == LOW)
        TrinketKeyboard.pressKey(0, KEYCODE_ARROW_UP, KEYCODE_S);
      else
        TrinketKeyboard.pressKey(0, KEYCODE_ARROW_UP); 
      arrow_pressed = true; 
   }
  else if(yReading < 0){ 
      if (digitalRead(PIN_BUTTON_A) == LOW)
        TrinketKeyboard.pressKey(0, KEYCODE_ARROW_DOWN, KEYCODE_A);
      else if (digitalRead(PIN_BUTTON_B) == LOW)
        TrinketKeyboard.pressKey(0, KEYCODE_ARROW_DOWN, KEYCODE_S);
      else
        TrinketKeyboard.pressKey(0, KEYCODE_ARROW_DOWN);
      arrow_pressed = true; 
     }
  if (xReading == 0 && arrow_pressed) {
    arrow_pressed = false;
    TrinketKeyboard.pressKey(0, 0);
  }
  
  if (digitalRead(PIN_BUTTON_A) == LOW)
  {
    TrinketKeyboard.pressKey(0, KEYCODE_A);
    // this should type a capital A
    a_pressed = true;
    
  }
  if (digitalRead(PIN_BUTTON_A) == HIGH && a_pressed)
  {
    TrinketKeyboard.pressKey(0, 0);
    a_pressed = false;
  }
  
   //this style simulates the hold so we can actually use smash attacks
  if (digitalRead(PIN_BUTTON_B) == LOW)
  {
    // type out a string using the Print class
    TrinketKeyboard.pressKey(0, KEYCODE_S);
    b_pressed = true;
  }
    if (digitalRead(PIN_BUTTON_B) == HIGH && b_pressed )
  {
    TrinketKeyboard.pressKey(0, 0);
    b_pressed = false;
  }
  if (digitalRead(PIN_BUTTON_C) == LOW)
  {
    // type out a string using the Print class
    TrinketKeyboard.pressKey(0, KEYCODE_    D);
    c_pressed = true;
  }
    if (digitalRead(PIN_BUTTON_C) == HIGH && c_pressed )
  {
    TrinketKeyboard.pressKey(0, 0);
    c_pressed = false;
  }

}
