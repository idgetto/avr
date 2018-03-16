/*
A simple test of serial-port functionality.
Takes in a character at a time and sends it right back out,
 displaying the ASCII value on the LEDs.
*/

// ------- Preamble -------- //
#include <avr/io.h>
#include <util/delay.h>
#include "devboard.h"
#include "usart.h"


void byteToString(char b, char *s) {
  s[0] = b & _BV(7) ? '1' : '0'; 
  s[1] = b & _BV(6) ? '1' : '0'; 
  s[2] = b & _BV(5) ? '1' : '0'; 
  s[3] = b & _BV(4) ? '1' : '0'; 
  s[4] = b & _BV(3) ? '1' : '0'; 
  s[5] = b & _BV(2) ? '1' : '0'; 
  s[6] = b & _BV(1) ? '1' : '0'; 
  s[7] = b & _BV(0) ? '1' : '0'; 
  s[8] = '\0';
}

int main(void) {
  char serialCharacter;

  // -------- Inits --------- //
  set_bit(LED1_DDR, LED1);
  set_bit(LED2_DDR, LED2);

  set_bit(LED1_PORT, LED1);
  initUSART();
  printString("Hello World!\r\n");                          /* to test */

  // ------ Event loop ------ //
  char s[9];
  while (1) {
    serialCharacter = receiveByte();
    byteToString(serialCharacter, s);

    transmitByte(serialCharacter);
    transmitByte('\t');
    printString(s);
    printString("\r\n");

    LED1_PORT = serialCharacter;
    LED2_PORT = serialCharacter;
  } 
  return 0;
}

