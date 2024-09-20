#include <Servo.h>
int servopin=5;
int led=13;
int keypin=A1;
int keypin2=A2;
int keypin3=A3;
Servo digit1;
void setup() {
  pinMode(13,OUTPUT);
  digit1.attach(servopin);
  digit1.write(0);
}

void loop() {
  //if(!digitalRead(keypin2))
//  {
    digit1.write(0);
    delay(500);
    digit1.write(90);
    delay(500);
    digit1.write(180);
    delay(500);
    digit1.write(90);
    delay(500);
// }
  /*if(!digitalRead(keypin))
  {
    digit1.write(random(0,180));
    delay(100);
  }
  if(!digitalRead(keypin3))
  {
    digit1.write(180);
    delay(random(50,100));
    digit1.write(0);
  }*/
}
