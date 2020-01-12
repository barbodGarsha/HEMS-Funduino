#include "HEMS_Funduino.h"

int main()
{
	serial_init();
	sei();
	protocol_loop();
	return 0;
}