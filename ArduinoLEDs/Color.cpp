#include <math.h>
#include "Color.h"

using namespace std;

Color::Color(void) {
  red = green = blue = 0;
}

Color::Color(int r, int g, int b) {
  red = r;
  green = g;
  blue = b;
}

int Color::toInt() {
  return (red << 16) | (green << 8) | blue;
}

Color Color::lerp(Color c1, Color c2, float t) {
  return Color(
    (t - 1) * (float)c1.red + t * (float)c2.red,
    (t - 1) * (float)c1.green + t * (float)c2.green,
    (t - 1) * (float)c1.blue + t * (float)c2.blue
  );
}

Color Color::fromInt(int i) {
  return Color((i >> 16) & 255, (i >> 8) & 255, i & 255);
}

Color Color::fromHSV(float h, float s, float v) {
  h = fmod(h, 360);
  if (h < 0) h += 360;

  float M = v * 255;
  float m = M * (1 - s);

  //For some reason abs() in math.h doesn't work on my laptop. If it works on yours, replace next 3 lines with commented line below
  float a = fmod(h / 60, 2) - 1;
  if(a < 0) a *= 1;
  float z = (M - m) * (1 - a);
  
  //float z = (M - m) * (1 - abs(fmod(h / 60, 2) - 1));
  int r, g, b;

  if (0 <= h && h < 60) {
    return Color((int)M, (int)z + m, (int)m);
  }
  else if (60 <= h && h < 120) {
    return Color((int)z + m, (int)M, (int)m);
  }
  else if (120 <= h && h < 180) {
    return Color((int)m, (int)M, (int)z + m);
  }
  else if (180 <= h && h < 240) {
    return Color((int)m, (int)z + m, (int)M);
  }
  else if (240 <= h && h < 300) {
    return Color((int)z + m, (int)m, (int)M);
  }
  else {
    return Color((int)M, (int)m, (int)z + m);
  }
}
