#include <avr/io.h>
#include <util/delay.h>
#include "devboard.h"

int main() {
  set_bit(LED1_DDR, LED1);
  set_bit(LED1_PORT, LED1);

  while (1) {
    set_bit(LED1_PORT, LED1);
    _delay_ms(100);
    clear_bit(LED1_PORT, LED1);
    _delay_ms(100);
  }

  return 0;
}
