/* Finalised version using the Multifunction shield 
 *  Ultrasonic obstcle detector is used to develop 
 *an electronic scale for measuring the distance 
 *developed specially for the Innovation Hub students of the  
 *Nehru Science Centre, 
 *Dr.E.Moses Road, 
 *Worli,Mumbai
 */
 
//timer2 will interrupt at 8kHz
/* Define shift register pins used for seven segment display */
#define LATCH_DIO 4
#define CLK_DIO 7
#define DATA_DIO 8
byte dig1 = 10,dig2=10,dig3=10,dig4=10;
int digitCounter = 0;
// Segment byte maps for numbers 0 to 9,space, and dot
//                           0    1    2    3    4    5    6    7    8    9    0.   1.   2.   3.   4.   5.   6.   7.   8.   9.  spc   dot     
const byte SEGMENT_MAP[] = {0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0X80,0X90,0x40,0x79,0x24,0x30,0x19,0x12,0x02,0x78,0X00,0X10,0xFF,0x7f};
/* Byte maps to select digit 1 to 4 */
const byte SEGMENT_SELECT[] = {0xF1,0xF2,0xF4,0xF8};
  // defines pins numbers for ultrasonic sensor
const int trigPin = 5;
const int echoPin = 6;

// defines variables
long duration;
int distance;
 void setup(){
 //set pins as outputs
  pinMode(LATCH_DIO,OUTPUT);

  pinMode(CLK_DIO,OUTPUT);
  pinMode(DATA_DIO,OUTPUT);
  pinMode(13,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  Serial.begin(9600); // Starts the serial communication
  delay(10); 
  cli();//stop interrupts
//set timer2 interrupt at 8kHz
  TCCR2A = 0;// set entire TCCR2A register to 0
  TCCR2B = 0;// same for TCCR2B
  TCNT2  = 0;//initialize counter value to 0
  // set compare match register for 8khz increments
  OCR2A = 255;// = (16*10^6) / (8000*8) - 1 (must be <256)
  // turn on CTC mode
  TCCR2A |= (1 << WGM21);
  // Set CS21 bit for 8 prescaler
  TCCR2B |= (1 << CS21);   
  // enable timer compare interrupt
  TIMSK2 |= (1 << OCIE2A);
sei();//allow interrupts
digitCounter = 0;
}//end setup

void WriteNumberToSegment(byte Segment, byte Value)
{
digitalWrite(LATCH_DIO,LOW);
shiftOut(DATA_DIO, CLK_DIO, MSBFIRST, SEGMENT_MAP[Value]);
shiftOut(DATA_DIO, CLK_DIO, MSBFIRST, SEGMENT_SELECT[Segment] );
digitalWrite(LATCH_DIO,HIGH);
}
 
ISR(TIMER2_COMPA_vect){//timer1 interrupt 8kHz toggles pin 9
//generates pulse wave of frequency 8kHz/2 = 4kHz (takes two cycles for full wave- toggle high then toggle low)
digitalWrite(12,HIGH);
digitalWrite(13,LOW);
  digitCounter++;
  if(digitCounter == 1) WriteNumberToSegment(digitCounter-1,dig1);
  if(digitCounter == 2) WriteNumberToSegment(digitCounter-1,dig2);
  if(digitCounter == 3) WriteNumberToSegment(digitCounter-1, dig3);
  if(digitCounter == 4){WriteNumberToSegment(digitCounter-1, dig4); digitCounter = 0;}

}

void loop(){
  //do other things here; // defines pins numbers
// Clears the trigPin
digitalWrite(12,LOW);
digitalWrite(13,HIGH);
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin,LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
cli();
duration = pulseIn(echoPin, HIGH);
sei();
delay(10);
//dig1=20; dig2=20; dig3=20; dig4=20;

// Calculating the distance
distance= duration*0.35/2;
// Prints the distance on the Serial Monitor
cli();
dig4=distance%10;   //4
dig3=(distance/10)%10; //The +10m adds the decimalpoint to convert mm to cm 
dig2 = (distance/100)%10;
dig1=distance/1000;
dig3=dig3+10;
if(!dig1){dig1=20;if(!dig2){dig2=20;}}
sei();
//Serial.print("Distance: ");
//Serial.print(float(distance)/25.4);
//Serial.print("in     ");
//Serial.println(float(distance)/10.);
//Serial.print(dig1); Serial.print(dig2);

//Serial.print(dig3);Serial.print(dig4);

//  delay(20); 
}
