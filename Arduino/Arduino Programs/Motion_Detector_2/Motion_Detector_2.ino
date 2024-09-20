int pirpin=5;
int pir_stat=0;
#define beeppin 3
#define keypin A1
int key_stat=HIGH;
void setup() {
  pinMode(beeppin,OUTPUT);     
  pinMode(pirpin, INPUT);
  pinMode(keypin, INPUT); 
  digitalWrite(beeppin,HIGH);
  Serial.begin(9600);
  key_stat=digitalRead(keypin);
}
void loop() {
  // put your main code here, to run repeatedly;
  pir_stat=digitalRead(pirpin);
  if(key_stat==LOW)
  {
    pir_stat=digitalRead(pirpin);
    Serial.println("i have started");
    if(pir_stat==HIGH)
    {
      digitalWrite(beeppin,LOW);
      Serial.println("i am beeping");
    } 
    else
    {
      digitalWrite(beeppin,HIGH);
    }
  }
  else
  {
    Serial.println("i have stopped");
    digitalWrite(beeppin,HIGH);
  }
}
