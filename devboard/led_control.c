/* Control LEDs with switch and button */

#include <avr/io.h>

// LED1 = PC5
// LED2 = PC2
// Button = PD1
// Switch = PD5


int main(void) {

  // -------- Inits --------- //

  // Data Direction Register C is used 
  // to enable output on PC5 and PC2
  DDRC |= (1 << PC5);
  DDRC |= (1 << PC2);

  // Data Direction Register D is used
  // to enable input on PD1 and PD5
  //
  // Port D is used to enable the 
  // internal pullup resistors
  DDRD &= ~(1 << PD1);
  DDRD &= ~(1 << PD5);
  PORTD |= (1 << PD1);
  PORTD |= (1 << PD5);


  // ------ Event loop ------ //
  while (1) {

    if (PIND & (1 << PD5)) {
      PORTC &= ~(1 << PC2);
    } else {
      PORTC |= (1 << PC2);
    }

    if (PIND & (1 << PD1)) {
      PORTC &= ~(1 << PC5);
    } else {
      PORTC |= (1 << PC5);
    }

  }       

  return 0;
}
