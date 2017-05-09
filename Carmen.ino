//Author: Anthony Garcia
//Date: 5/9/17
//Project: Carmen - 2017 Golden Scissors Fashion Show
//Version: 1.2

int brightness = 0;    // how bright the LED is
int fadeAmount = 5;    // how many points to fade the LED by
int counter = 0;       // counter to cycle through pins


void setup()
{
  // declare all pins to be an outputs for Gemma
  pinMode(0, OUTPUT);
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
}

void loop()
{
  // set the brightness of the LEDs one group at a time
  analogWrite(counter, brightness);

  // change the brightness for next time through the loop
  brightness = brightness + fadeAmount;

  // reverse the direction of the fading at the ends of the fade:
  if (brightness == 0 || brightness == 255)
  {
    fadeAmount = -fadeAmount;
  }
  
  // if end of fade, change to different output pin
  if (brightness == 0)
  {
    // if not on last pin increment
    if (counter < 2)
    {
      counter++;
    }
    else  // if on last pin, reset to pin 0
    {
      counter = 0;
    }
  }

  delay(15);
}
