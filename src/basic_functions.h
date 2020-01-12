#ifndef basic_functions_h 
#define basic_functions_h

// Delays variable-defined milliseconds. Compiler compatibility fix for _delay_ms().
void delay_ms(uint16_t ms);

// This functions makes the LED blink
void led_blink(int n, int delay_ms);


#endif