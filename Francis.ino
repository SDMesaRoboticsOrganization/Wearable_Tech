//Author: Anthony Garcia
//Date: 5/9/17
//Project: Francis - 2017 Golden Scissors Fashion Show
//Version: 1.2

int brightness = 0;    // how bright the LED is
int fadeAmount = 5;    // how many points to fade the LED by
int counter = 0;       // counter to keep track of cycles
bool both = false;     // switch for effect
bool rSleeve = true;   // switch for sleeves


void setup()
{
  // declare pins to be an outputs:
  pinMode(0, OUTPUT);  //right sleeve
  pinMode(1, OUTPUT);  //left sleeve
}

void loop()
{
  if (both)
  {
    fadeBoth();  //fades sleeves at same time
  }
  else
  {
    fadeAlternating();  //fades sleeves alternating
  }

  //when each function is called 8 times, switches to next function
  if ((counter != 0) && (counter % 8 == 0))
  {
    both = !both;
  }
}

void fadeBoth()
{
  // set the brightness of the LEDs
  analogWrite(0, brightness);
  analogWrite(1, brightness);

  // change the brightness for next time through the loop
  brightness = brightness + fadeAmount;

  // reverse the direction of the fading at the ends of the fade:
  if (brightness == 0 || brightness == 255)
  {
    fadeAmount = -fadeAmount;
  }

  //increment counter for each fade in/out
  if (brightness == 0)
  {
    counter++;
  }

  delay(15);
}

void fadeAlternating()
{
  if (rSleeve)
  {
    // set the brightness of the LEDs
    analogWrite(0, brightness);

    // change the brightness for next time through the loop
    brightness = brightness + fadeAmount;

    // reverse the direction of the fading at the ends of the fade
    if (brightness == 0 || brightness == 255)
    {
      fadeAmount = -fadeAmount;
    }

    //increment counter for each fade in/out
    if (brightness == 0)
    {
      counter++;
      rSleeve = !rSleeve;  //change to left sleeve when right sleeve is off
    }

    delay(15);
  }
  else
  {
    // set the brightness of the LEDs
    analogWrite(0, brightness);

    // change the brightness for next time through the loop
    brightness = brightness + fadeAmount;

    // reverse the direction of the fading at the ends of the fade
    if (brightness == 0 || brightness == 255)
    {
      fadeAmount = -fadeAmount;
    }

    //increment counter for each fade in/out
    if (brightness == 0)
    {
      counter++;
      rSleeve = !rSleeve;  //change to right sleeve when left sleeve is off
    }

    delay(15);
  }
}
