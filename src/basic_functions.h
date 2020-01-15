#ifndef basic_functions_h 
#define basic_functions_h

// Delays variable-defined milliseconds. Compiler compatibility fix for _delay_ms().
void delay_ms(uint16_t ms);

// This functions makes the LED blink
void led_blink(int n, int delay_ms);

// Turns on the LED with fade
int led_fade_on(int n, int helligkeit, int helligkeit_min, int helligkeit_max, int fade_schritte, int delay_ms);
  
// Turns off the LED with fade
int led_fade_off(int n, int helligkeit, int helligkeit_min, int helligkeit_max, int fade_schritte, int delay_ms);

// Turns on and off the LED with fade
void led_fade_on_off(int n, int delay_ms);

#endif