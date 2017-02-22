#pragma once

class Color {
public:
  int red, green, blue;
  Color(void);
  Color(int, int, int);
  int toInt(void);
  static Color
    lerp(Color, Color, float),
    fromInt(int),
    fromHSV(float, float, float);
};
