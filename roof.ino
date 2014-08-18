uint8_t roof_pos = 0;

void roof_step()
{
  roof_mode = 0;
  switch (roof_mode) {
    case 0:
      sidesSolid();
      break;
    case 1:
      marquee();
      break;
    case 2:
      chase();
      break;
  }
  rb_wheelPos += roof_shift_by;
  roof.show();
}

void marquee()
{
  uint8_t i;
  for(i = 0; i < ROOF_NUM; i++) {
    if ((i + roof_pos) % 6 != 0)
      roof.setPixelColor(i, roof.Color(0,0,0));
    else roof.setPixelColor(i, Wheel(rb_wheelPos & 255, rb_scheme));
  } 
  if(roof_dir == 0) roof_pos = (roof_pos + 1) % ROOF_NUM;
  else if(roof_dir == 1) roof_pos = (roof_pos - 1) % ROOF_NUM;
}

void chase()
{
  uint8_t i;
  
  fadeRoof(); 
  for (i = 0; i < num_chases; i++) {
    roof.setPixelColor((roof_pos + i*(ROOF_NUM / num_chases)) % ROOF_NUM, Wheel(rb_wheelPos & 255, rb_scheme));
  }
  if(roof_dir == 0) roof_pos = (roof_pos + 1) % ROOF_NUM;
  else if(roof_dir == 1) roof_pos = (roof_pos - 1) % ROOF_NUM;
}

void raise()
{
  
}

void sidesSolid()
{
  uint8_t i;
  
  for (i = 0; i < ROOF_NUM; i++) {
    if(i < 20 || (i >= 30 && i < 50)) {
      roof.setPixelColor(i, Wheel(rb_wheelPos & 255, rb_scheme));
    } else {
      roof.setPixelColor(i, Wheel((rb_wheelPos + 128) & 255, rb_scheme));
    }
  }
}

void fadeRoof()
{
  uint8_t i;
  uint32_t color;
  
  
  for (i = 0; i < ROOF_NUM; i++) {
    color = roof.getPixelColor(i);
    color = fadeFactory(color, fadeFactor);
    roof.setPixelColor(i, color);
  }
}
