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

// Turns on the LED with fade
// At the end this function returns the brightness just in case we need it for example in led_fade_on_off it is needed
int led_fade_on(int n, int brightness, int brightness_max, int fade_schritte, int delay_ms)
{
  while(brightness < brightness_max)
  {
    analogWrite(n, brightness);
    delay(delay_ms);
    brightness += fade_schritte;
  }
  return brightness;
}

// Turns off the LED with fade
// At the end this function returns the brightness just in case we need it for example in led_fade_on_off it is needed
int led_fade_off(int n, int brightness, int brightness_min, int fade_schritte, int delay_ms)
{
  while(brightness > brightness_min)
  {
    analogWrite(n, brightness);
    delay(delay_ms);
    brightness -= fade_schritte;
  }
  return brightness;
}

// Turns on and off the LED with fade
void led_fade_on_off(int n, int delay_ms)
{
  int brightness = 0;
  brightness = led_fade_on(n, brightness, BRIGHTNESS_MAX, FADE_STEPS, 100);
  led_fade_off(n, brightness, BRIGHTNESS_MIN, FADE_STEPS, 100);
}

// Returns the pin number of each color for PA5
int get_color_pin(int x)
{
  if(x == R)
  {
    return A5_LED_R;
  }
  if(x == G)
  {
    return A5_LED_G;
  }
  if(x == B)
  {
    return A5_LED_B;
  }
  
  return -1;
}

// Changes the color of the color of the led in PA5
void RGB_led_color_change(int red_light_value, int green_light_value, int blue_light_value)
{
  analogWrite(get_color_pin(R), red_light_value);
  analogWrite(get_color_pin(G), green_light_value);
  analogWrite(get_color_pin(B), blue_light_value);
}