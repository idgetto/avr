#include <avr/io.h>
#include <avr/interrupt.h>

#define LED PC5

#define set_bit(reg, bit) (reg |= (1 << bit))
#define clear_bit(reg, bit) (reg &= ~(1 << bit))
#define toggle_bit(reg, bit) (reg ^= (1 << bit))

ISR (TIMER1_OVF_vect) {
  toggle_bit(PORTC, LED);
  TCNT1 = 61629;
}

int main() {
  set_bit(DDRC, LED);

  // set timer value
  TCNT1 = 61629;

  // start timer at FCU/256
  TCCR1B = 1 << CS12;

  // enable overflow interrupt
  TIMSK1 = 1 << TOIE1;
  sei();

  while (1) {
  }


  return 0;
}
