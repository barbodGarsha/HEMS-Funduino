#include "HEMS_Funduino.h"

//realtime command bits
volatile uint8_t realtime_command = 0;

// set the realtime bits
//TO DO2: realtime command... it just works for reset command
void set_realtime_command(){realtime_command = 1;}

//check if there is an interrupt
int check_realtime()
{
    if (realtime_command)
    {
        //TO DO2: realtime command... it just works for reset command 

        #ifdef CLI_ENABLE
        printPgmString(PSTR("Exiting...\n"));
        #endif 
        //Reset
        return 1;
    }
    return 0;
    
}

// execute the program based on the program code we got from the PC/Laptop
// for example PA2B means the Program for the Aufgabe 2B
int program_change(String program)
{
    
    if (program == PA2B)
    {   
        #ifdef CLI_ENABLE
        printPgmString(PSTR("PA2B is running\n"));
        #endif 
        program_A2B();
    }
    else if(program == PA3)
    {
        #ifdef CLI_ENABLE
        printPgmString(PSTR("PA3 is running\n"));
        #endif
        program_A3_init();
    }
    else if(program == PA4)
    {
        program_A4_init();
    }
    else
    {
        return 1;
    }
    
    return 0;
    
    
    
}

// it's a basic blink program for 5 LEDs
int program_A2B()
{
    // set the pins
    program_A2B_init();
    for (;;)
    {        
        // make the LEDs blink
        led_blink(A2B_LED1, PA2B_BLINK_DELAY_MS);
        led_blink(A2B_LED2, PA2B_BLINK_DELAY_MS);
        led_blink(A2B_LED3, PA2B_BLINK_DELAY_MS);
        led_blink(A2B_LED4, PA2B_BLINK_DELAY_MS);
        led_blink(A2B_LED5, PA2B_BLINK_DELAY_MS);

        // wait
        delay_ms(PA2B_LOOP_DELAY_MS);

        //TO DO2: realtime command... it just works for reset command 
        // check if there is an interrupt 
        if (check_realtime()) { break; }
    }
    
    return 0;
}

int program_A3()
{
    program_A3_init();
    for (;;)
    {
        // trun on and off the LED with fade
        led_fade_on_off(A3_LED1, 10);

        // wait
        delay(PA3_LOOP_DELAY_MS);

        //TO DO2: realtime command... it just works for reset command 
        // check if there is an interrupt 
        if (check_realtime()) { break; }
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