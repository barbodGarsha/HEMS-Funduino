#include "HEMS_Funduino.h"

// Delays variable defined milliseconds. Compiler compatibility fix for _delay_ms(),
// which only accepts constants in future compiler releases.
void delay_ms(uint16_t ms) 
{
  while ( ms-- ) { _delay_ms(1); }
}

// This functions makes the LED blink
void led_blink(int n, int ms)
{
  digitalWrite(n, HIGH);   // turn the LED on
  delay_ms(ms);               // wait
  digitalWrite(n, LOW);    // turn the LED off
}
