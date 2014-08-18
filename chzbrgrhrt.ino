#include <Adafruit_NeoPixel.h>

using namespace std;

#define S_RAINBOW 0
#define S_CRISPY 1
#define S_SNOWSKIRT 2
#define S_ROYAL 3
#define S_GLEAM 4
#define S_FIRE 5
#define S_SPORKLE 6
#define S_DORK 7
#define S_KELPY 8
#define S_JUNGLE 9
#define S_AMERICA 10
#define S_SESAME 11

#define NUM_ROOF_MODES 3
#define NUM_RB_SCHEMES 11

#define ROOF_PIN 3
#define SESAME_PIN 5
#define BACK_PIN 6
#define MENU_PIN 9
#define GRILL_PIN 10

#define ROOF_NUM 60
#define SESAME_NUM 7
#define BACK_NUM 27
#define MENU_NUM 5
#define GRILL_NUM 10

Adafruit_NeoPixel roof = Adafruit_NeoPixel(ROOF_NUM, ROOF_PIN, NEO_GRB + NEO_KHZ400);
Adafruit_NeoPixel sesame = Adafruit_NeoPixel(SESAME_NUM, SESAME_PIN, NEO_GRB + NEO_KHZ400);
Adafruit_NeoPixel back = Adafruit_NeoPixel(BACK_NUM, BACK_PIN, NEO_GRB + NEO_KHZ400);
Adafruit_NeoPixel menu = Adafruit_NeoPixel(MENU_NUM, MENU_PIN, NEO_GRB + NEO_KHZ400);
Adafruit_NeoPixel grill = Adafruit_NeoPixel(GRILL_NUM, GRILL_PIN, NEO_GRB + NEO_KHZ400);

uint8_t roof_mode = 0;
uint8_t rb_scheme = 0;
uint8_t interval = 200;
uint8_t chance = 100;

uint8_t roof_shift_by = 2;
uint8_t back_shift_by = 7;

uint8_t rb_wheelPos = 0;
uint8_t rb_fadePos = 0;

uint8_t back_dir = 0;
uint8_t roof_dir = 0;

uint8_t grill_wheelPos = 0;
uint8_t sesame_wheelPos = 0;

uint8_t fadeFactor = 2;

uint8_t num_chases = 4;

void setup()
{
  roof.begin();
  roof.show();
  setToBlack(&roof);
  
  sesame.begin();
  sesame.show();
  
  back.begin();
  back.show();
  
  menu.begin();
  menu.show();
  
  grill.begin();
  grill.show();
  
  randomSeed(analogRead(0));
  delay(10);
}

void loop()
{
  randomize();
  roof_step();
  //grill_step();
  //ses_step();
  //back_step();
  //menu_step();
  delay(interval);
}
  
void randomize()
{
  if (!random(chance)) {
    roof_mode = random(NUM_ROOF_MODES);
  }
  if (!random(chance)) {
    rb_scheme = random(NUM_RB_SCHEMES);
  }
  if (!random(chance)) {
    fadeFactor = 3 + random(4);
  }
  if (!random(chance)) {
    back_dir = random(3);
  }
  if (!random(chance)) {
    roof_dir = random(2);
  }
  if (!random(chance)) {
    back_shift_by = random(10);
  }
  if (!random(chance)) {
    roof_shift_by = random(5);
  }
  if (!random(chance)) {
    interval = 20 + random(200);
  }
  if (!random(chance)) {
    num_chases = 1 + random(10);
  }
  
}


