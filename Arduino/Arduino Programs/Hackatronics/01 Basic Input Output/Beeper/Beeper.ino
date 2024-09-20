#include <TimerOne.h>
#include <Wire.h>
#include <MultiFuncShield.h>

/*

For more information and help, please visit https://www.cohesivecomputing.co.uk/hackatronics/arduino-multi-function-shield/part-1/

*/

void setup() {
  // put your setup code here, to run once:

  Timer1.initialize();
  MFS.initialize(&Timer1);    // initialize multi-function shield library
  
  // NOTE beep control is performed in the background, i.e. beep() is non blocking.
  
  // short beep for 200 milliseconds
  MFS.beep();
  
  delay(1000);
  
  // 4 short beeps, repeated 3 times.
  MFS.beep(5,1,10,20,50);
}

void loop() {
  // put your main code here, to run repeatedly:

}
