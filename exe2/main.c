#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <stdio.h>


//botões são sensores
const int BTN_PIN = 26;
const int BTN_PIN_E = 7 ;
int main() {
  stdio_init_all();

  gpio_init(BTN_PIN);
  gpio_init(BTN_PIN_E);
  gpio_set_dir(BTN_PIN_E, GPIO_IN);
  gpio_set_dir(BTN_PIN, GPIO_IN);
  gpio_pull_up(BTN_PIN);
  gpio_pull_up(BTN_PIN_E);


  while (true) {
    if (!gpio_get(BTN_PIN)) {
      printf("Botao 1\n");
      while (!gpio_get(BTN_PIN)) {
      };
    }
    if(!gpio_get(BTN_PIN_E)){
      printf("Botão 2\n");
      while(!gpio_get(BTN_PIN_E)){

      };
    }
  }
}
