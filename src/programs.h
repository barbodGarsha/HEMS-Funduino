#ifndef programs_h 
#define programs_h

#define PA2B "PA2B"
#define PA3 "PA3"
#define PA4 "PA4"
#define PA4A "PA4A"
#define PA4B "PA4B"
#define PA5 "PA5"
#define PA6 "PA6"

// PA2B DEFAULTS ------------------------------------------------------------

// the delay for program PA2B loop in ms
#define PA2B_LOOP_DELAY_MS 1000 

// the delay for led_blink in ms
#define PA2B_BLINK_DELAY_MS 100 

//---------------------------------------------------------------------------


// PA3 DEFAULTS ------------------------------------------------------------

// the delay for program PA3 loop in ms
#define PA3_LOOP_DELAY_MS 100 

#define BRIGHTNESS_MAX  255
#define BRIGHTNESS_MIN 0
#define FADE_STEPS 5

//---------------------------------------------------------------------------


// PA4 DEFAULTS ------------------------------------------------------------

// the delay for program PA4 loop in ms
#define PA4_LOOP_DELAY_MS 100 

//---------------------------------------------------------------------------


// PA4A DEFAULTS ------------------------------------------------------------

// the delay for program PA4A loop in ms
#define PA4A_LOOP_DELAY_MS 100 

//---------------------------------------------------------------------------

// PA4B DEFAULTS ------------------------------------------------------------

// the delay for program PA4B loop in ms
#define PA4B_LOOP_DELAY_MS 100 

//---------------------------------------------------------------------------


// PA5 DEFAULTS ------------------------------------------------------------

#define R 0 // Red
#define G 1 // Green
#define B 2 // Blue

// the delay for program PA5 loop in ms
#define PA5_LOOP_DELAY_MS 100 

//---------------------------------------------------------------------------


// PA8 DEFAULTS ------------------------------------------------------------

// the delay for program PA8 loop in ms
#define PA8_LOOP_DELAY_MS 50 

//---------------------------------------------------------------------------


// PA10 DEFAULTS ------------------------------------------------------------

// the delay for program PA10 loop in ms
#define PA10_LOOP_DELAY_MS 500 

//---------------------------------------------------------------------------



void set_realtime_command();

int check_realtime();

int program_change(String program);

int program_A2B();

int program_A3();

int program_A4();

int program_A4A();

int program_A4B();

int program_A5();

int program_A6();

int program_A7();

int program_A8();

int program_A9();

int program_A10();

#endif