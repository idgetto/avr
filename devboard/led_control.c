/* Control LEDs with switch and button */

#include <avr/io.h>
#include <avr/interrupt.h>

#define LED1 PD5
#define LED2 PB0
#define BTN PD0
#define SW PD1

#define read_bit(reg, bit) (reg & (1 << bit))
#define clear_bit(reg, bit) (reg &= ~(1 << bit))
#define set_bit(reg, bit) (reg |= (1 << bit))
#define toggle_bit(reg, bit) (reg ^= (1 << bit))

ISR (PCINT2_vect) {
  toggle_bit(PORTD, LED1);
  toggle_bit(PORTB, LED2);
}


int main(void) {

  // Data Direction Register C is used 
  // to enable output on PC5 and PC2
  set_bit(DDRD, LED1);
  set_bit(DDRB, LED2);

  // Data Direction Register D is used
  // to enable input on PD1 and PD5
  //
  // Port D is used to enable the 
  // internal pullup resistors
  clear_bit(DDRD, SW);
  clear_bit(DDRD, BTN);
  set_bit(PORTD, SW);
  set_bit(PORTD, BTN);

  // use Pin Change Interrupt Control Register
  // to enable interrupts for PCINT23:16
  PCICR |= 1 << PCIE2;

  // use Pin Change Mask to enable 
  // interrupts on PCINT17 and PCINT21
  PCMSK2 = (1 << PCINT16) | (1 << PCINT17);

  // enable global interrupts
  sei();

  while (1) {
  }       

  return 0;
}
