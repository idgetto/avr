#include <avr/io.h>
#include <avr/interrupt.h>

#define LED PD5

#define set_bit(reg, bit) (reg |= (1 << bit))
#define clear_bit(reg, bit) (reg &= ~(1 << bit))
#define toggle_bit(reg, bit) (reg ^= (1 << bit))

ISR (TIMER1_COMPA_vect) {
  toggle_bit(PORTD, LED);
}

void setup_timer() {
  // setup Timer/Counter Control Register
  // as Clear Timer on Compare
  TCCR1B |= 1 << WGM12;

  // use Timer/Counter Control Register
  // to start timer at FCU/64
  TCCR1B |= (1 << CS10) | (1 << CS11);

  // use Output Compare Register
  // to set timer compare value
  OCR1A = 2499;

  // use Timer Interrupt Mask to
  // enable the compare interrupt
  TIMSK1 = 1 << OCIE1A;

  // enable global interrupts
  sei();
}

int main() {
  // enable output to LED
  set_bit(DDRD, LED);

  setup_timer();

  while (1) {
  }

  return 0;
}
