void setToBlack(Adafruit_NeoPixel *strip) {
  uint8_t i;
  
  for (i = 0; i < strip->numPixels(); i++) {
    strip->setPixelColor(i, strip->Color(0,0,0));
  }
}

uint32_t fadeFactory(uint32_t color, uint8_t factor) {
  uint32_t r = (color >> 16) * 2 / factor;
  uint32_t g = ((color >> 8) & 255) * 2 / factor;
  uint32_t b = (color & 255) * 2 / factor;
  return (r << 16) | (g << 8) | b;
}

// Input a value 0 to 255 to get a color value.
uint32_t Wheel(byte WheelPos, uint8_t scheme) {
  // Use selected color scheme.
  switch (scheme) {
    case S_RAINBOW: // Rainbow
      return generalWheel(WheelPos, roof.Color(255,0,0), roof.Color(0,255,0), roof.Color(0,0,255));
    case S_CRISPY: //
      return generalWheel(WheelPos, roof.Color(2,255,222), roof.Color(229,149,217), roof.Color(210,255,0));
    case S_SNOWSKIRT: //
      return generalWheel(WheelPos, roof.Color(229,255,46), roof.Color(240,23,0), roof.Color(147,0,131));
    case S_ROYAL: //
      return generalWheel(WheelPos, roof.Color(0,0,0), roof.Color(128,0,255), roof.Color(128,0,128));
    case S_GLEAM: //
      return generalWheel(WheelPos, roof.Color(0,0,0), roof.Color(23,7,0), roof.Color(85,60,0));
    case S_FIRE: //
      return generalWheel(WheelPos, roof.Color(255,0,0), roof.Color(255,100,0), roof.Color(232,120,0));
    case S_SPORKLE: //
      return generalWheel(WheelPos, roof.Color(0,0,0), roof.Color(80,0,230), roof.Color(0,0,0));
    case S_DORK: //
      return generalWheel(WheelPos, roof.Color(0,0,0), roof.Color(196,0,255), roof.Color(209,209,209));
    case S_KELPY: //
      return generalWheel(WheelPos, roof.Color(0,0,133), roof.Color(0,196,255), roof.Color(0,240,44));
    case S_JUNGLE: //
        return generalWheel(WheelPos, roof.Color(214,185,0), roof.Color(0,255,17), roof.Color(60,138,80));
    case S_AMERICA: //
      return generalWheel(WheelPos, roof.Color(255,0,0), roof.Color(209,209,209), roof.Color(0,0,255));
  }
}

uint32_t generalWheel(byte WheelPos, uint32_t C0, uint32_t C1, uint32_t C2) {
  uint8_t r0 = C0 >> 16;
  uint8_t g0 = (C0 >> 8) & 255;
  uint8_t b0 = C0 & 255;
  uint8_t r1 = C1 >> 16;
  uint8_t g1 = (C1 >> 8) & 255;
  uint8_t b1 = C1 & 255;
  uint8_t r2 = C2 >> 16;
  uint8_t g2 = (C2 >> 8) & 255;
  uint8_t b2 = C2 & 255;
  
  if(WheelPos < 85) {
   return roof.Color(r0 + (WheelPos * (r1 - r0) / 85), g0 + (WheelPos * (g1 - g0) / 85), b0 + (WheelPos * (b1 - b0) / 85));
  } else if(WheelPos < 170) {
   WheelPos -= 85;
   return roof.Color(r1 + (WheelPos * (r2 - r1) / 85), g1 + (WheelPos * (g2 - g1) / 85), b1 + (WheelPos * (b2 - b1) / 85));
  } else {
   WheelPos -= 170;
   return roof.Color(r2 + (WheelPos * (r0 - r2) / 85), g2 + (WheelPos * (g0 - g2) / 85), b2 + (WheelPos * (b0 - b2) / 85));
  }
}
