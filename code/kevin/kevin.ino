#include <ProTrinketKeyboard.h>  // Ensure the library is installed
// 
// buttons are 9, 10, 11
const int BUTTON1 = 9;
const int BUTTON2 = 10;
const int BUTTON3 = 11;

const int DIR_UD = 0;
const int DIR_LR = 1;
const int DIR_PR = 3;

bool BUTTON1P = false;
bool BUTTON2P = false;
bool BUTTON3P = false;
bool UDP = false;
bool LRP = false;
bool PRP = false;

void setup() {
  // Declare button pins as inputs
  pinMode(BUTTON1, INPUT);
  pinMode(BUTTON2, INPUT);
  pinMode(BUTTON3, INPUT);

  pinMode(DIR_UD, INPUT);
  pinMode(DIR_LR, INPUT);
  pinMode(DIR_PR, INPUT);

  // setting input pins to high means turning on internal pull-up resistors
  digitalWrite(BUTTON1, HIGH);
  digitalWrite(BUTTON2, HIGH);
  digitalWrite(BUTTON3, HIGH);

  digitalWrite(DIR_UD, LOW);
  digitalWrite(DIR_LR, LOW);
  digitalWrite(DIR_PR, LOW);

  // start USB stuff
  TrinketKeyboard.begin();
}

void loop() {
  // TrinketKeyboard.pressKey(KEYCODE_MOD_LEFT_SHIFT, KEYCODE_A);
  // TrinketKeyboard.pressKey(0, 0);
  
  TrinketKeyboard.poll();
  
  if (digitalRead(BUTTON1) == LOW) {
    if (!BUTTON1P) {
      TrinketKeyboard.print("a");
      BUTTON1P = true;
    }
  } else {
    BUTTON1P = false;
  }
  if (digitalRead(BUTTON2) == LOW) {
    if (!BUTTON2P) {
      TrinketKeyboard.print("b");
      BUTTON2P = true;
    }
  } else {
    BUTTON2P = false;
  }
  if (digitalRead(BUTTON3) == LOW) {
    if (!BUTTON3P) {
      TrinketKeyboard.print("c");
      BUTTON3P = true;
    }
  } else {
    BUTTON3P = false;
  }

  if (digitalRead(DIR_UD) == HIGH) {
    if (!UDP) {
      TrinketKeyboard.print("ud ");
      UDP = true;
    }
  } else {
    UDP = false;
  }
  if (digitalRead(DIR_LR) == HIGH) {
    if (!LRP) {
      TrinketKeyboard.print("lr ");
      LRP = true;
    }
  } else {
    LRP = false;
  }
  if (digitalRead(DIR_PR) == HIGH) {
    if (!PRP) {
      TrinketKeyboard.print("pr ");
      PRP = true;
    }
  } else {
    PRP = false;
  }

//  char buf[10];
//  for (int i = 0; i < 64; i++) {
//    sprintf(buf, "%d", digitalRead(i));  
//    TrinketKeyboard.print(buf);
//  }
//  TrinketKeyboard.print(" ");

  // signals:
  // NORMAL: 0001111111111011000000000010000000100000000000001000000000000000
  // UP:     0001111111111010000000000010000000100000000000001000000000000000 signal 15: 1 to 0
  // DOWN:   0001111111111011000000000010000000100000000000001000000000000000
  // LEFT:   0001111111111011000000000010000000100000000000001000000000000000
  // RIGHT:  0001111111111001000000000010000000100000000000001000000000000000 signal 14: 1 to 0
  // PRESS:  0000111111111011000000000010000000100000000000001000000000000000 signal 3: 1 to 0
}
