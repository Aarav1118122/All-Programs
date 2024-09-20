#include <Servo.h>
#define echoPin 6
#define trigPin 9 
int servopin=5;
int led=13;
Servo digit1;
long duration; // variable for the duration of sound wave travel
int distance; // variable for the distance measurement

void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
  Serial.begin(9600); // // Serial Communication is starting with 9600 of baudrate speed
  digit1.attach(servopin);
  digit1.write(0);
}
void loop() {
  // Clears the trigPin condition
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  // Displays the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  if(distance>=30&&distance<120)
  {
    digit1.write(0);
    delay(500);
    digit1.write(90);
    delay(500);
  }
  if(distance>=120)
  {
    digit1.write(0);
    delay(500);
    digit1.write(180);
    delay(500);
  }
  if(distance<30)
  {
    digit1.write(0);
    delay(500);
    digit1.write(90);
    delay(500);
    digit1.write(180);
    delay(500);
    digit1.write(90);
    delay(500);
    digit1.write(0);
    delay(500);
  }
}
