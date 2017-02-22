#include <Adafruit_NeoPixel.h>
#include "Color.h"

#define PIN 6
#define PIXELS 15

using namespace std;

Adafruit_NeoPixel strip = Adafruit_NeoPixel(PIXELS, PIN, NEO_GRB + NEO_KHZ800);

int frameCount = 0;
void setup() {
  strip.setBrightness(51);
  strip.begin();
  strip.show();
}

void loop() {
  for(int i = 0; i < PIXELS; i++){
    Color c = Color::fromHSV((float)frameCount + (float)i / PIXELS * 360 , 1, 1);
    strip.setPixelColor(i, c.toInt());
  }
}
