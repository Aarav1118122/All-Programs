int ledPin = 3;                // LED 
int pirPin = 5;                 // PIR Out pin 
int pirStat = LOW;                   // PIR status
void setup() {
 pinMode(ledPin, OUTPUT);     
 pinMode(pirPin, INPUT);     
 Serial.begin(9600);
}
void loop(){
  sensing:
 pirStat = digitalRead(pirPin); 
 switch(pirStat)
 {
  case HIGH:
   digitalWrite(ledPin, LOW);  // turn LED ON
   delay(1000);
   digitalWrite(ledPin, HIGH);
   delay(100);
   Serial.println("Hey I got you!!!");
   goto sensing;
   break;
   case LOW:
   digitalWrite(ledPin, HIGH);
   goto sensing;
   break;
   default:
   digitalWrite(ledPin, HIGH);
 }
} 
