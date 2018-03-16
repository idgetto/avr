const int UBRR = F_CPU / (16 * BAUD - 1);

void initUSART() {
  // set BAUD rate
  UBRR0H = (unsigned char) UBRR >> 8;
  UBRR0L = (unsigned char) UBRR;

  // enable RX and TX
  UCSR0B = _BV(RXEN0) | _BV(TXEN0);

  // set frame size to 8 bits with 2 stop bits
  // UCSR0C = _BV(UCSZ01) | _BV(UCSZ00) | _BV(USBS0) | _BV(UPM01);
  UCSR0C = _BV(UCSZ01) | _BV(UCSZ00) | _BV(USBS0);
}

void transmitByte(char b) {
  // wait for empty transmit buffer
  while (!(UCSR0A & _BV(UDRE0)));

  // put data into register to be sent
  UDR0 = b;
}

void printString(const char *s) {
  while (*s != '\0') {
    transmitByte(*s);
    ++s;
  }
}

char receiveByte() {
  // wait for data to be received
  while (!(UCSR0A & _BV(RXC0)));
  
  return UDR0;
}
