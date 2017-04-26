int brightness = 0;    // how bright the LED is
int fadeAmount = 5;    // how many points to fade the LED by
int counter = 0;       // counter to keep track of cycles

// the setup routine runs once when you press reset:
void setup()
{
  // declare pins to be an outputs:
  pinMode(0, OUTPUT);
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop()
{
  // set the brightness of the analog-connected LEDs:
  analogWrite(counter, brightness);
  //analogWrite(1, brightness);
  //analogWrite(2, brightness);

  // change the brightness for next time through the loop:
  brightness = brightness + fadeAmount;

  // reverse the direction of the fading at the ends of the fade:
  if (brightness == 0 || brightness == 255)
  {
    fadeAmount = -fadeAmount;
  }
  if (brightness == 0)
  {
    if (counter < 2)
    {
      counter++;
    }
    else
    {
      counter = 0;
    }
  }
  // wait for 15 milliseconds to see the dimming effect
  delay(15);
}
