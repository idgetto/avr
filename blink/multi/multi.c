#include <avr/io.h>
#include <avr/interrupt.h>

#define LED0 PC5
#define LED1 PC2

#define set_bit(reg, bit) (reg |= (1 << bit))
#define clear_bit(reg, bit) (reg &= ~(1 << bit))
#define toggle_bit(reg, bit) (reg ^= (1 << bit))

const int COUNT_START0 = 128;
const int COUNT_START1 = 3036;

ISR (TIMER0_OVF_vect) {
  toggle_bit(PORTC, LED0);
  TCNT0 = COUNT_START0;
}

ISR (TIMER1_OVF_vect) {
  toggle_bit(PORTC, LED1);
  TCNT1 = COUNT_START1;
}

void setup_timer() {
  // use Timer/Counter Control Register
  TCCR0B = (1 << CS10) | (1 << CS12);
  TCCR1B = 1 << CS11;

  // set Timer 1 Counter
  TCNT0 = COUNT_START0;
  TCNT1 = COUNT_START1;

  // use Timer Interrupt Mask to
  // enable then overflow interrupt
  TIMSK0 = 1 << TOIE0;
  TIMSK1 = 1 << TOIE1;

  // enable global interrupts
  sei();
}

int main() {
  // enable output to LED
  set_bit(DDRC, LED0);
  set_bit(DDRC, LED1);

  setup_timer();

  while (1) {
  }

  return 0;
}
