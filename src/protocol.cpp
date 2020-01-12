#include "HEMS_Funduino.h"

static char line[LINE_BUFFER_SIZE]; // Line to be executed

// executes the codes we send to the program bz serial port
static void protocol_execute_line(char *line)
{
    if (line[0] == 0) {

    } else if (line[0] == '#') {
        // '#' is system code
        printPgmString(PSTR("system code\n"));
    } else if (line[0] == 'P') {
        // 'P' is the code for changing the program
        printPgmString(PSTR("Program change\n"));
    } else {
        // maybe there will be realtime commands
        printPgmString(PSTR("realtime\n"));
    }
}

// Program main loop
void protocol_loop()
{
    uint8_t char_counter = 0;
  	uint8_t c;	

	for (;;)
    {
        while((c = serial_read()) != SERIAL_NO_DATA) 
        {
            if ((c == '\n') || (c == '\r')) { // the line ended
                line[char_counter] = 0; // set string termination character.
                protocol_execute_line(line); //  execute the line.
                char_counter = 0;
            }
            else  if (c <= ' ') { 
                // do nothing because we don't need the whitepaces and control characters 
            }
            else if (0){
                // TO DO2: handle line buffer overflow
            }
            else if (c >= 'a' && c <= 'z') { // Upcase lowercase
                line[char_counter++] = c-'a'+'A';
            } else {
                line[char_counter++] = c;
            }
        }
	
    }
    
}
