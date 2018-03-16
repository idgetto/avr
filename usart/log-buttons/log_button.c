// ------- Preamble -------- //
#include <avr/io.h>
#include <util/delay.h>
#include "devboard.h"
#include "usart.h"

int main(void) {

  // -------- Inits --------- //
  clear_bit(BTN_DDR, BTN);
  set_bit(BTN_PORT, BTN);

  set_bit(LED1_DDR, LED1);
  set_bit(LED2_DDR, LED2);

  initUSART();
  
  // turn off USART RX
  clear_bit(UCSR0B, RXEN0);

  printString("Hello World!\r\n");                          /* to test */

  // ------ Event loop ------ //
  while (1) {
    _delay_ms(50);
    if (BTN_PIN & _BV(BTN)) {
      transmitByte('0');
      printString("\r\n");
    } else {
      transmitByte('1');
      printString("\r\n");
    }
  } 

  return 0;
}

