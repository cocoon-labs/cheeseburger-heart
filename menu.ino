void menu_step()
{
  uint8_t i;
  for(i = 0; i < MENU_NUM; i++) {
    menu.setPixelColor(i, menu.Color(22, 20, 18));
  }
  menu.show();
}
