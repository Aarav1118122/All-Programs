/*
 * The ultrasonic moduleHC-SR04 measures the 
 * distance of the various obstacles from it.
 * With this simple sketch we shall learn how to use this
 *sheld with the Arduino. We shall also learn to use the 
 *Serial Monotor and Serial plotter 
 *
 */
#define trigPin 6
#define echoPin 5
#define greenLED 11
#define redLED 10

void setup() {
Serial.begin (9600);
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
pinMode(greenLED, OUTPUT);
pinMode(redLED, OUTPUT);
}

void loop() {
long duration, distance;
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distance = (duration/2) / 29.1;
if (distance < 4) { // This is where the LED On/Off happens
digitalWrite(greenLED,HIGH); // When the Red condition is met, the Green LED should turn off digitalWrite(redLED,LOW);
} else {
digitalWrite(greenLED,LOW); digitalWrite(redLED,HIGH);
}
if (distance >= 200 || distance <= 0){
Serial.println("Out of range");
} else {
Serial.print(distance);  Serial.println(" cm");
} delay(1);

}
