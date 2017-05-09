//Author: Anthony Garcia
//Date: 5/9/17
//Project: Lisset - 2017 Golden Scissors Fashion Show
//Version: 1.3

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif

#define PIN 1

#define NUM_LEDS 36

#define BRIGHTNESS 50

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, PIN, NEO_GRBW + NEO_KHZ800);

int maxBrightness = 200;
int minBrightness = 0;
int fadeSpeed = 5;


void setup()
{
  strip.setBrightness(BRIGHTNESS);
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
}

void loop()
{
  //fade all flowers 5 times
  for (uint16_t i = 0; i < 5; i++)
  {
    pulseColor(strip.Color(255, 255, 255), 1);
  }

  //colorwipe all flowers 5 times
  for (uint16_t i = 0; i < 5; i++)
  {
    //reset brightness from pulse function
    strip.setBrightness(200);
    colorWipe(strip.Color(0, 0, 0), 75);  //wipe black/off
    colorWipe(strip.Color(255, 255, 255), 75);//wipe white
  }

}

//change each LED to color c one at a time for each "flower"
void colorWipe(uint32_t c, uint8_t wait)
{
  for (uint16_t i = 0; i < 12; i++)
  {
    //change each "flower" at same time
    strip.setPixelColor(i, c);      //flower #1
    strip.setPixelColor(i + 12, c); //flower #2
    strip.setPixelColor(i + 24, c); //flower #3
    strip.setPixelColor(i + 36, c); //flower #4
    strip.setPixelColor(i + 48, c); //flower #5
    strip.show();
    delay(wait);
  }
}

//pulse all flowers together color c
void pulseColor(uint32_t c, uint8_t wait)
{
  int i;
  
  //changes color for all "flowers" (just in case color is changed)
  for (int x = 0; x < strip.numPixels(); x++)
  {
    strip.setPixelColor(x, c);
  }
  
  //Increase Brightness / Fade In
  for (i = minBrightness; i < maxBrightness; i++)
  {
    //set brighness for all "flowers"
    strip.setBrightness(i);

    strip.show();
    delay(wait);
  }

  //Lower Brightness / Fade Out
  for (i = maxBrightness; i > minBrightness; i--)
  {
    //set brighness for all "flowers"
    strip.setBrightness(i);

    strip.show();
    delay(wait);
  }
}

