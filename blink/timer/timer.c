#include <avr/io.h>
#include <avr/interrupt.h>

#define LED PC5

#define set_bit(reg, bit) (reg |= (1 << bit))
#define clear_bit(reg, bit) (reg &= ~(1 << bit))
#define toggle_bit(reg, bit) (reg ^= (1 << bit))

const int COUNT_START = 3036;

ISR (TIMER1_OVF_vect) {
  toggle_bit(PORTC, LED);
  TCNT1 = COUNT_START;
}

void setup_timer() {
  // use Timer/Counter Control Register
  // to start timer at FCU/256
  TCCR1B = 1 << CS11;

  // set Timer 1 Counter
  TCNT1 = COUNT_START;

  // use Timer Interrupt Mask to
  // enable then overflow interrupt
  TIMSK1 = 1 << TOIE1;

  // enable global interrupts
  sei();
}

int main() {
  // enable output to LED
  set_bit(DDRC, LED);

  setup_timer();

  while (1) {
  }

  return 0;
}
