/* Control LEDs with switch and button */

#include <avr/io.h>

#define LED1 PC5
#define LED2 PC2
#define BTN PD1
#define SW PD5

#define read_bit(reg, bit) (reg & (1 << bit))
#define clear_bit(reg, bit) (reg &= ~(1 << bit))
#define set_bit(reg, bit) (reg |= (1 << bit))


int main(void) {

  // -------- Inits --------- //

  // Data Direction Register C is used 
  // to enable output on PC5 and PC2
  set_bit(DDRC, LED1);
  set_bit(DDRC, LED2);

  // Data Direction Register D is used
  // to enable input on PD1 and PD5
  //
  // Port D is used to enable the 
  // internal pullup resistors
  clear_bit(DDRD, SW);
  clear_bit(DDRD, BTN);
  set_bit(PORTD, SW);
  set_bit(PORTD, BTN);


  // ------ Event loop ------ //
  while (1) {


    // if the button is pressed
    // then turn LED1 on
    if (read_bit(PIND, BTN)) {
      clear_bit(PORTC, LED1);
    } else {
      set_bit(PORTC, LED1);
    }

    // if the switch has is flipped
    // then turn the LED2 on
    if (read_bit(PIND, SW)) {
      clear_bit(PORTC, LED2);
    } else {
      set_bit(PORTC, LED2);
    }
  }       

  return 0;
}
