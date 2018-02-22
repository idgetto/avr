#include <avr/io.h>
#include <util/delay.h>

#define LED PC5

#define set_bit(reg, bit) (reg |= (1 << bit))
#define clear_bit(reg, bit) (reg &= ~(1 << bit))

int main() {
  set_bit(DDRC, LED);

  while (1) {
    set_bit(PORTC, LED);
    _delay_ms(500);
    clear_bit(PORTC, LED);
    _delay_ms(500);
  }

  return 0;
}
