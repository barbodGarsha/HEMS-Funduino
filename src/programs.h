#ifndef programs_h 
#define programs_h

#define PA2B "PA2B"
#define PA3 "PA3"
#define PA4 "PA4"

// PA2B DEFAULTS ------------------------------------------------------------

// the delay for program loops in ms
#define PA2B_LOOP_DELAY_MS 1000 

// the delay for led_blink in ms
#define PA2B_BLINK_DELAY_MS 100 


void program_change(String program);

int program_A2B();

int program_A3();

int program_A4();

#endif