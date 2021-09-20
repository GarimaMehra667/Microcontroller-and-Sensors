// C++ code
//
#include<Adafruit_NeoPixel.h>
#define PIN 2
#define NUMPIXELS 12
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
int red=0;
int green=0;
int blue=0;
void setup()
{
  pixels.begin();
}
void loop()
{
  setColour();
  for(int i=0; i< NUMPIXELS ;i++)
  {
    pixels.setPixelColor(i, pixels.Color(red,green,blue));
    pixels.show();
    delay(300);
  }
}
void setColour(){
  red =random(0,255);
  green =random(0,255);
  blue =random(0,255);
}