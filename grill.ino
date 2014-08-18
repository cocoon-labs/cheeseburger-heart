void grill_step()
{
  uint32_t color;
  uint8_t i;
  
  for(i = 0; i < SESAME_NUM; i++) {
    grill_wheelPos = random(256);
  
    color = Wheel(grill_wheelPos, S_FIRE);
    color = fadeFactory(color, 1 + random(5));
    grill.setPixelColor(i, color);
  }
  grill.show();
}
