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
  // This is for Trinket 5V 16MHz, you can remove these three lines if you are not using a Trinket
#if defined (__AVR_ATtiny85__)
  if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
#endif
  // End of trinket special code
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
    strip.setBrightness(200);
    colorWipe(strip.Color(0, 0, 0), 75);
    colorWipe(strip.Color(255, 255, 255), 75);
  }

}

void colorWipe(uint32_t c, uint8_t wait)
{
  for (uint16_t i = 0; i < 12; i++)
  {
    strip.setPixelColor(i, c);    //flower #1
    strip.setPixelColor(i + 12, c); //flower #2
    strip.setPixelColor(i + 24, c); //flower #3
    strip.setPixelColor(i + 36, c); //flower #4
    strip.setPixelColor(i + 48, c); //flower #5
    strip.show();
    delay(wait);
  }
}

void pulseColor(uint32_t c, uint8_t wait)
{
  int i;
  //Increase Brightness / Fade In
  for (i = minBrightness; i < maxBrightness; i++)
  {
    strip.setBrightness(i);

    for (int x = 0; x < strip.numPixels(); x++)
    {
      strip.setPixelColor(x, c);
    }
    strip.show();
    delay(wait);
  }
  //colorWipe(strip.Color(255, 255, 255), 5);
  //Lower Brightness / Fade Out
  for (i = maxBrightness; i > minBrightness; i--)
  {
    strip.setBrightness(i);

    for (int x = 0; x < strip.numPixels(); x++)
    {
      strip.setPixelColor(x, c);
    }
    strip.show();
    delay(wait);
  }
}

