//Author: Anthony Garcia
//Date: 5/9/17
//Project: Brooke - 2017 Golden Scissors Fashion Show
//Version: 1.2

int brightness = 0;    // how bright the LED is
int fadeAmount = 5;    // how many points to fade the LED by

void setup()  
{ 
  // declare all pins to be an outputs so user can connect to any pin
  pinMode(0, OUTPUT);
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
} 

void loop()  
{ 
  // set the brightness of the sequins
  analogWrite(0, brightness);
  analogWrite(1, brightness);  
  analogWrite(2, brightness);
  
  // change the brightness for next time through the loop
  brightness = brightness + fadeAmount;

  // reverse the direction of the fading at the ends of the fade
  if (brightness == 0 || brightness == 255) 
  {
    fadeAmount = -fadeAmount; 
  }     
    
  delay(15); 
}
