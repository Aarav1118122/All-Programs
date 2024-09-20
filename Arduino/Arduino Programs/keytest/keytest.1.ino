
  // put your setup code here, to run once:
  #define latch 4
  #define led4 10
  #define led3 11
  #define led2 12
  #define led1 13
  #define key1 A1
  #define key2 A2
  #define key3 A3
  #define beepPin 3
void setup (){
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  pinMode(led4,OUTPUT);
  pinMode(beepPin,OUTPUT);
 
  pinMode(key1,INPUT);
  pinMode(key2,INPUT);
  pinMode(key3,INPUT);
  digitalWrite(led1,HIGH);
  digitalWrite(led2,HIGH);
  digitalWrite(led3,HIGH);
  digitalWrite(led4,HIGH);
  digitalWrite(beepPin, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(!digitalRead(key1)){
    digitalWrite(led1,LOW);  
    //digitalWrite(beepPin,LOW);
    delay(100);
    digitalWrite(led1,HIGH);
    digitalWrite(led2,LOW);  
    delay(100);
    digitalWrite(led2,HIGH);
    digitalWrite(led3,LOW);  
    //digitalWrite(beepPin,LOW);
    delay(100);
    digitalWrite(led3,HIGH);
    digitalWrite(led4,LOW);  
    delay(100);
    digitalWrite(led4,HIGH);
  }
  else {
    digitalWrite(led1,HIGH);
    digitalWrite(beepPin,HIGH);
  }
  if(!digitalRead(key2))  {
    digitalWrite(led4,LOW);  
    delay(100);
    digitalWrite(led4,HIGH);
    digitalWrite(led3,LOW);  
    delay(100);
    digitalWrite(led3,HIGH);
    digitalWrite(led2,LOW);  
    delay(100);
    digitalWrite(led2,HIGH);
    digitalWrite(led1,LOW);  
    delay(100);
    digitalWrite(led1,HIGH);
  }
  else digitalWrite(led2,HIGH);
  if(!digitalRead(key3)) {
    digitalWrite(led2,LOW);
    digitalWrite(led3,LOW);
    delay(1000);
    digitalWrite(led2,HIGH);
    digitalWrite(led3,HIGH);
    digitalWrite(led1,LOW);
    digitalWrite(led4,LOW);
    delay(1000);
    digitalWrite(led1,HIGH);
    digitalWrite(led4,HIGH);
  }
  else digitalWrite(led3,HIGH);
  }
