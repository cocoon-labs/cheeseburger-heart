void ses_step()
{
  uint32_t color;
  uint8_t i;
  sesame_wheelPos += 16;
  
  for(i = 0; i < SESAME_NUM; i++) {
    color = Wheel(sesame_wheelPos, S_SESAME);
    color = fadeFactory(color, 1 + random(20));
    sesame.setPixelColor(i, color);
  }
  sesame.show();
}
