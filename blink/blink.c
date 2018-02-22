#include <avr/io.h>
#include <util/delay.h>

int main() {
  DDRC |= (1 << PC5);
  PORTC &= ~(1 << PC5);

  while (1) {
    PORTC |= (1 << PC5);
    _delay_ms(500);
    PORTC &= ~(1 << PC5);
    _delay_ms(500);
  }

  return 0;
}
