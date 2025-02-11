#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <stdio.h>

int main() {
  stdio_init_all();

  const int BTN_PIN = 28 ;//GP28
  const int LED_PIN_R = 5;//GP5
  const int LED_PIN_P = 8;//GP8
  const int LED_PIN_B = 11;//GP11
  const int LED_PIN_Y = 15;//GP15
  gpio_init(BTN_PIN);
  gpio_init(LED_PIN_R);
  gpio_init(LED_PIN_P);
  gpio_init(LED_PIN_B);
  gpio_init(LED_PIN_Y);

  gpio_set_dir(BTN_PIN,GPIO_IN);
  gpio_set_dir(LED_PIN_R,GPIO_OUT);
  gpio_set_dir(LED_PIN_P,GPIO_OUT);
  gpio_set_dir(LED_PIN_B,GPIO_OUT);
  gpio_set_dir(LED_PIN_Y,GPIO_OUT);

  gpio_pull_up(BTN_PIN);


  while (true) {

    if(!gpio_get(BTN_PIN)){
      gpio_put(LED_PIN_R,1);
      sleep_ms(300);
      gpio_put(LED_PIN_R,0);
      //Purple
      gpio_put(LED_PIN_P,1);
      sleep_ms(300);
      gpio_put(LED_PIN_P,0);
      //Blue
      gpio_put(LED_PIN_B,1);
      sleep_ms(300);
      gpio_put(LED_PIN_B,0);
      //Yellow
      gpio_put(LED_PIN_Y,1);
      sleep_ms(300);
      gpio_put(LED_PIN_Y,0);
      while(!gpio_get(BTN_PIN)){
      }

    }

    // Use delay de 300 ms entre os estados!
  }
}
