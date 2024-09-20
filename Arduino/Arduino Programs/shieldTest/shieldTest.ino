
//timer interrupts
//by Amanda Ghassaei
//June 2012
//https://www.instructables.com/id/Arduino-Timer-Interrupts/

/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
*/

//timer setup for timer0, timer1, and timer2.
//For arduino uno or any board with ATMEL 328/168.. diecimila, duemilanove, lilypad, nano, mini...

//this code will enable all three arduino timer interrupts.
//timer0 will interrupt at 2kHz
//timer1 will interrupt at 1Hz
//timer2 will interrupt at 8kHz

//storage variables
boolean toggle0 = 0;
boolean toggle1 = 0;
boolean toggle2 = 0;
/* Define shift register pins used for seven segment display */
#define LATCH_DIO 4
#define CLK_DIO 7

#define DATA_DIO 8
byte dig1 = 10,dig2=10,dig3=10,dig4=10;
int digitCounter = 0;
 
/* Segment byte maps for numbers 0 to 9 */
const byte SEGMENT_MAP[] = {0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0X80,0X90,0xFF,0x7f};
/* Byte maps to select digit 1 to 4 */
const byte SEGMENT_SELECT[] = {0xF1,0xF2,0xF4,0xF8};
 

void setup(){
  
  //set pins as outputs
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13,OUTPUT);
  pinMode(LATCH_DIO,OUTPUT);
  pinMode(CLK_DIO,OUTPUT);
  pinMode(DATA_DIO,OUTPUT);
  pinMode(3,OUTPUT);

cli();//stop interrupts

//set timer0 interrupt at 2kHz
//  TCCR0A = 0;// set entire TCCR2A register to 0
//  TCCR0B = 0;// same for TCCR2B
//  TCNT0  = 0;//initialize counter value to 0
  // set compare match register for 2khz increments
//  OCR0A = 124;// = (16*10^6) / (2000*64) - 1 (must be <256)
  // turn on CTC mode
//  TCCR0A |= (1 << WGM01);
  // Set CS01 and CS00 bits for 64 prescaler
 // TCCR0B |= (1 << CS01) | (1 << CS00);   
  // enable timer compare interrupt
 // TIMSK0 |= (1 << OCIE0A);

//set timer1 interrupt at 1Hz
  TCCR1A = 0;// set entire TCCR1A register to 0
  TCCR1B = 0;// same for TCCR1B
  TCNT1  = 0;//initialize counter value to 0
  // set compare match register for 1hz increments
  OCR1A = 15624;// = (16*10^6) / (1*1024) - 1 (must be <65536)
  // turn on CTC mode
  TCCR1B |= (1 << WGM12);
  // Set CS12 and CS10 bits for 1024 prescaler
  TCCR1B |= (1 << CS12) | (1 << CS10);  
  // enable timer compare interrupt
  TIMSK1 |= (1 << OCIE1A);

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
dig1 =3;
digitCounter = 0;
}//end setup

void WriteNumberToSegment(byte Segment, byte Value)
{
digitalWrite(LATCH_DIO,LOW);
shiftOut(DATA_DIO, CLK_DIO, MSBFIRST, SEGMENT_MAP[Value]);
shiftOut(DATA_DIO, CLK_DIO, MSBFIRST, SEGMENT_SELECT[Segment] );
digitalWrite(LATCH_DIO,HIGH);
}
ISR(TIMER0_COMPA_vect){//timer0 interrupt 2kHz toggles pin 8
//generates pulse wave of frequency 2kHz/2 = 1kHz (takes two cycles for full wave- toggle high then toggle low)
  if (toggle0){
    digitalWrite(10,HIGH);
    toggle0 = 0;
  }
  else{
    digitalWrite(10,LOW);
    toggle0 = 1;
  }
}

ISR(TIMER1_COMPA_vect){//timer1 interrupt 1Hz toggles pin 13 (LED)
//generates pulse wave of frequency 1Hz/2 = 0.5kHz (takes two cycles for full wave- toggle high then toggle low)
  if (toggle1){
    digitalWrite(11,LOW);
    toggle1 = 0;
  }
  else{
    digitalWrite(11,HIGH);
    toggle1 = 1;
  }
}
  
ISR(TIMER2_COMPA_vect){//timer1 interrupt 8kHz toggles pin 9
//generates pulse wave of frequency 8kHz/2 = 4kHz (takes two cycles for full wave- toggle high then toggle low)
  digitCounter++;
  if(digitCounter == 1) WriteNumberToSegment(digitCounter-1,dig1);
  if(digitCounter == 2) WriteNumberToSegment(digitCounter-1,dig2);
  if(digitCounter == 3) WriteNumberToSegment(digitCounter-1, dig3);
  if(digitCounter == 4){WriteNumberToSegment(digitCounter-1, dig4); digitCounter = 0;}

}

void loop(){
  //do other things here
  for (int i=0;i<=7;i++){
  dig1=i+0;dig2=i+1,dig3=i+2, dig4=i+3;
  if(toggle2){//digitalWrite(3,HIGH); 
    digitalWrite(10,HIGH);digitalWrite(12,HIGH);digitalWrite(11,LOW);digitalWrite(13, LOW);
    toggle2=0;}
  else{//digitalWrite(3,LOW);  
  digitalWrite(10,LOW);digitalWrite(12,LOW);digitalWrite(11,HIGH);digitalWrite(13, HIGH);
    toggle2=1;}
digitalWrite(3,HIGH);
  delay(20); }

}
