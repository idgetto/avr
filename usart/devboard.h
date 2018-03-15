#define LED1 PD5
#define LED1_DDR DDRD
#define LED1_PORT PORTD

#define LED2 PB0
#define LED2_DDR DDRB
#define LED2_PORT PORTB

#define BTN PD0
#define BTN_DDR DDRD
#define BTN_PORT PORTD
#define BTN_PIN PIND

#define SW1 PD1
#define SW1_DDR DDRD
#define SW1_PORT PORTD
#define SW1_PIN PIND

#define SW2 PD2
#define SW2_DDR DDRD
#define SW2_PORT PORTD
#define SW2_PIN PIND

#define BV(bit) (1 << bit)
#define set_bit(byte, bit) (byte |= BV(bit))
#define clear_bit(byte, bit) (byte &= ~BV(bit))
#define toggle_bit(byte, bit) (byte ^= BV(bit))
