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
  
  MFS.write("Hi");
  delay(2000);
  MFS.write(-273);
  delay(2000);
  MFS.write(3.141, 2);  // display to 2 decimal places.
  delay(2000);
}

int counter=0;
byte ended = false;

void loop() {
  // put your main code here, to run repeatedly:

  if (counter < 20)
  {
    MFS.write((int)counter);
    counter++;
  }
  else if (!ended)
  {
    ended = true;
    MFS.write("Aditi");
    MFS.blinkDisplay(DIGIT_ALL, ON);
  }
  delay(50);
}
