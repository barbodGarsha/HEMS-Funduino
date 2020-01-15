#ifndef confiq_h 
#define confiq_h

//CLI enable
#define CLI_ENABLE

//Start-Up message enable
#define STRAT_UP_MESSAGE_ENABLE
#ifdef STRAT_UP_MESSAGE_ENABLE
    #define STRAT_UP_MESSAGE "Developed by Barbod Garshasbi\n"
#endif


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