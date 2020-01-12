#include "HEMS_Funduino.h"

// execute the program based on the program code we got from the PC/Laptop
// for example PA2B means the Program for the Aufgabe 2B
void program_change(String program)
{
    
    if (program == PA2B)
    {    
        printPgmString(PSTR("PA2B\n"));
        program_A2B();
    }
    else if(program == PA3)
    {
        program_A3_init();
    }
    else if(program == PA4)
    {
        program_A4_init();
    }
    else
    {
        /* TO DO1: no program with this code error */
    }
    
    
    
}

// it's a basic blink program for 5 LEDs
int program_A2B()
{
    // set the pins
    program_A2B_init();
    for (;;)
    {        
        led_blink(A2B_LED1, PA2B_BLINK_DELAY_MS);
        led_blink(A2B_LED2, PA2B_BLINK_DELAY_MS);
        led_blink(A2B_LED3, PA2B_BLINK_DELAY_MS);
        led_blink(A2B_LED4, PA2B_BLINK_DELAY_MS);
        led_blink(A2B_LED5, PA2B_BLINK_DELAY_MS);
        delay_ms(PA2B_LOOP_DELAY_MS);
    }
    
    return 0;
}

int program_A3()
{
    program_A3_init();
    for (;;)
    {
        /* code */
    }
    
    return 0;
}

int program_A4()
{
    program_A4_init();
    for (;;)
    {
        /* code */
    }

    return 0;
}