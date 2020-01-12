#include "HEMS_Funduino.h"
#include <Arduino.h>

int main()
{
	serial_init();
	sei();
	protocol_loop();
	return 0;
}