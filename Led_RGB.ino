#include <pwmWrite.h>

#define led_r_pin 4
#define led_g_pin 6
#define led_b_pin 16

Pwm LED_RGB = Pwm();

void setup() {
  Serial.begin(115200);
  pinMode(led_r_pin, OUTPUT);
  pinMode(led_g_pin, OUTPUT);
  pinMode(led_b_pin, OUTPUT);
}

void loop() {
  uint8_t maxColor = 255;
  for(uint8_t r = 0;r<maxColor; r+=3){
    for(uint8_t g = 0;g<maxColor; g+=5){
      for(uint8_t b = 0;b<maxColor; b+=5){
        LED_RGB.write(led_r_pin, r);
        LED_RGB.write(led_g_pin, g);
        LED_RGB.write(led_b_pin, b);
        Serial.printf("rgb bits = r:%d, g:%d, b:%d,\n", r, g, b);
      }
    }
  }
}