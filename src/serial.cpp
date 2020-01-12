#include "HEMS_Funduino.h"

uint8_t serial_rx_buffer[RX_BUFFER_SIZE];
uint8_t serial_rx_buffer_head = 0;
volatile uint8_t serial_rx_buffer_tail = 0;

uint8_t serial_tx_buffer[TX_BUFFER_SIZE];
uint8_t serial_tx_buffer_head = 0;
volatile uint8_t serial_tx_buffer_tail = 0;


void serial_init()
{
 	#if BAUD_RATE < 57600
    	uint16_t UBRR0_value = ((F_CPU / (8L * BAUD_RATE)) - 1)/2 ;
    	UCSR0A &= ~(1 << U2X0); // baud doubler off  - Only needed on Uno XXX
  	#else
    	uint16_t UBRR0_value = ((F_CPU / (4L * BAUD_RATE)) - 1)/2;
    	UCSR0A |= (1 << U2X0);  // baud doubler on for high baud rates, i.e. 115200
  	#endif

	// Set baud rate
	UBRR0H = UBRR0_value >> 8;
	UBRR0L = UBRR0_value;

	// Enable receiver, transmitter and RX complete interrupt
	UCSR0B |= (1 << RXEN0 | 1 << TXEN0 | 1 << RXCIE0);
}

void serial_write(uint8_t data)
{
	// Calculate next head
	uint8_t next_head = serial_tx_buffer_head + 1;
	if (next_head == TX_BUFFER_SIZE) { next_head = 0; }

	// Wait until there is space in the buffer
	while (next_head == serial_tx_buffer_tail) {}

	// Store data and advance head
	serial_tx_buffer[serial_tx_buffer_head] = data;
	serial_tx_buffer_head = next_head;

	// Enable Data Register Empty Interrupt to make sure tx-streaming is running
	UCSR0B |= (1 << UDRIE0);
}

ISR(SERIAL_UDRE)
{
	uint8_t tail = serial_tx_buffer_tail; // Temporary serial_tx_buffer_tail (to optimize for volatile)

	// Send a byte from the buffer
	UDR0 = serial_tx_buffer[tail];

	// Update tail position
	tail++;
	if (tail == TX_BUFFER_SIZE) { tail = 0; }

	serial_tx_buffer_tail = tail;

	// Turn off Data Register Empty Interrupt to stop tx-streaming if this concludes the transfer
	if (tail == serial_tx_buffer_head) { UCSR0B &= ~(1 << UDRIE0); }
}

uint8_t serial_read()
{
	uint8_t tail = serial_rx_buffer_tail; 
	if (serial_rx_buffer_head == tail) {
		return SERIAL_NO_DATA;
	}
	else {
		uint8_t data = serial_rx_buffer[tail];

		tail++;
		if (tail == RX_BUFFER_SIZE) { tail = 0; }
		serial_rx_buffer_tail = tail;

		return data;
	}
}

ISR(SERIAL_RX)
{
	uint8_t data = UDR0;
	uint8_t next_head;

	next_head = serial_rx_buffer_head + 1;
	if (next_head == RX_BUFFER_SIZE) { next_head = 0; }

	// Write data to buffer unless it is full.
	if (next_head != serial_rx_buffer_tail) {
		serial_rx_buffer[serial_rx_buffer_head] = data;
		serial_rx_buffer_head = next_head;
	}

}