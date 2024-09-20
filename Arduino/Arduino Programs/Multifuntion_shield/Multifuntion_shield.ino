#include <TimerOne.h>
#include <Wire.h>
#include <MultiFuncShield.h>
void setup() {
// put your setup code here, to run once:
  Timer1.initialize();
  MFS.initialize(&Timer1); // initialize multi-function shield library
}
void loop() {
  MFS.write("aarav");
  delay(2000);
  MFS.write(-273);
  delay(2000);
  MFS.write(3.141, 2); // display to 2 decimal places.
  delay(2000);
}
