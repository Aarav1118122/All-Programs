#include <TimerOne.h>
#include <Wire.h>
#include <MultiFuncShield.h>

/*

For more information and help, please visit https://www.cohesivecomputing.co.uk/hackatronics/arduino-multi-function-shield/part-3/

All our hackatronics projects are free for personal use, and there are many more
in the pipeline. If you find our projects helpful or useful, please consider making
a small donation to our hackatronics fund using the donate buttons on our web pages.
Thank you.

*/

enum SpeedoModeValues
{
  SETUP_WHEEL,
  CALCULATE_SPEED
};

byte speedoMode = CALCULATE_SPEED;
byte wheelDiameterCm = 60;
unsigned int wheelCirmcumferenceCm = (wheelDiameterCm * 314) / 100;

float SpeedKmh (unsigned int wheelCircumferenceCm, unsigned int periodMs);


void setup() {
  // put your setup code here, to run once:
  
  pinMode(5, INPUT_PULLUP);
  
  Timer1.initialize();
  MFS.initialize(&Timer1);
  
  MFS.initPulseInCounter(
      5,                 // use digital pin 5 for pulse input.
      2000,              // the number of milliseconds to wait for a pulse, before resetting pulse in period to 0.
      LOW                // trigger pulse on LOW input.
  );
}


void loop() {
  // put your main code here, to run repeatedly:

  byte btn = MFS.getButton();
  
  switch (speedoMode)
  {
    case SETUP_WHEEL:
        if (btn == BUTTON_1_PRESSED)
        {
          speedoMode = CALCULATE_SPEED;
          MFS.blinkDisplay(DIGIT_ALL, OFF);
          wheelCirmcumferenceCm = (wheelDiameterCm * 314) / 100;
        }
        else if (btn == BUTTON_2_PRESSED || btn == BUTTON_2_LONG_PRESSED)
        {
          wheelDiameterCm--;
          
          if (wheelDiameterCm < 30)
          {
            wheelDiameterCm = 30;
          }
          MFS.write(wheelDiameterCm);
        }
        else if (btn == BUTTON_3_PRESSED || btn == BUTTON_3_LONG_PRESSED)
        {
          wheelDiameterCm++;
          
          if (wheelDiameterCm > 100)
          {
            wheelDiameterCm = 100;
          }
          MFS.write(wheelDiameterCm);
        }
        break;
        
    case CALCULATE_SPEED:
        if (btn == BUTTON_1_LONG_PRESSED)
        {
          speedoMode = SETUP_WHEEL;
          MFS.write(wheelDiameterCm);
          MFS.blinkDisplay(DIGIT_ALL, ON);
        }
        else
        {
          unsigned int pulsePeriodMs = MFS.getPulseInPeriod();
          
          if (pulsePeriodMs == 0)
          {
            MFS.write(0.0, 1);
          }
          else
          {
            MFS.write(SpeedKmh(wheelCirmcumferenceCm, pulsePeriodMs), 1);
          }
        }
        break;
  }
  delay(100);
}


float SpeedKmh (unsigned int wheelCircumferenceCm, unsigned int periodMs)
{
  return (float)(wheelCircumferenceCm * 36) / periodMs;
}
