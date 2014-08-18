void back_pat()
{
  uint32_t color;
  uint8_t i;
  int j;

  for(i = 0; i < BACK_NUM; i++) {
    back.setPixelColor(i, Wheel(rb_wheelPos & 255, rb_scheme));
  }
  
  for(i = 0; i<BACK_NUM; i++) {
    j = (rb_fadePos - i) / 3;
    j = abs(j);
    color = back.getPixelColor(i);
    for( ; j>0 ; j--) {
      color = fadeFactory(color, fadeFactor);
    }
    back.setPixelColor(i, color);
  }
  if(back_dir == 0) rb_fadePos = (rb_fadePos + 1) % BACK_NUM;
  else if(back_dir == 1) rb_fadePos = (rb_fadePos - 1) % BACK_NUM;
  
  back.show();
  rb_wheelPos += back_shift_by;
}
