#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <stdio.h>

int main() {
  stdio_init_all();
  const int BTN_PIN_R = 28; //G28 
  const int BTN_PIN_G = 26; //G26
  const int LED_PIN_R = 4; //GP4
  const int LED_PIN_G = 6; //GP6

  gpio_init(BTN_PIN_R);
  gpio_init(BTN_PIN_G);
  gpio_init(LED_PIN_R);
  gpio_init(LED_PIN_G);
  
  gpio_set_dir(BTN_PIN_R,GPIO_IN);
  gpio_set_dir(BTN_PIN_G,GPIO_IN);
  gpio_set_dir(LED_PIN_R,GPIO_OUT);
  gpio_set_dir(LED_PIN_G,GPIO_OUT);

  gpio_pull_up(BTN_PIN_R);
  gpio_pull_up(BTN_PIN_G);
  int valor_led_red;
  int valor_led_green;
  while (true) {
    if(!gpio_get(BTN_PIN_R)){
      valor_led_red = gpio_get(LED_PIN_R);
      gpio_put(LED_PIN_R,!valor_led_red);
      while (!gpio_get(BTN_PIN_R)) {
      };
    
    }
    if(!gpio_get(BTN_PIN_G)){
      valor_led_green = gpio_get(LED_PIN_G);
      gpio_put(LED_PIN_G,!valor_led_green);
      while (!gpio_get(BTN_PIN_G)) {
      };
    }

  }
}
