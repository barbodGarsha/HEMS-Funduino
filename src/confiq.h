#ifndef confiq_h 
#define confiq_h

// Serial baud rate
#define BAUD_RATE 9600

// Serial port pins
#define SERIAL_RX     USART_RX_vect
#define SERIAL_UDRE   USART_UDRE_vect

#define RX_BUFFER_SIZE 128
#define TX_BUFFER_SIZE 64

#define LINE_BUFFER_SIZE 80

#define N_DECIMAL 3

#endif