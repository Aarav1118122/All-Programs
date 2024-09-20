#include<TimerOne.h>;
#include<Wire.h>;
#include<MultiFuncShield.h>;
#define echoPin 9 // attach pin D2 Arduino to pin Echo of HC-SR04
#define trigPin 6 //attach pin D3 Arduino to pin Trig of HC-SR04

// defines variables
long duration; // variable for the duration of sound wave travel
int distance; // variable for the distance measurement

void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
  Timer1.initialize();
  MFS.initialize(&Timer1);
  Serial.begin(9600);
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
  MFS.write(distance);
  Serial.print(distance);
  Serial.println("cm");
  delay(100);
}
