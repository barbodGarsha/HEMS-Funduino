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
        program_A3();
    }
    else if(program == PA4)
    {
        #ifdef CLI_ENABLE
        printPgmString(PSTR("PA4 is running\n"));
        #endif
        program_A4();
    }
    else if(program == PA4A)
    {
        #ifdef CLI_ENABLE
        printPgmString(PSTR("PA4A is running\n"));
        #endif
        program_A4A();
    }
    else if(program == PA4B)
    {
        #ifdef CLI_ENABLE
        printPgmString(PSTR("PA4B is running\n"));
        #endif
        program_A4B();
    }
    else if(program == PA5)
    {
        #ifdef CLI_ENABLE
        printPgmString(PSTR("PA5 is running\n"));
        #endif
        program_A5();
    }
    else if(program == PA6)
    {
        #ifdef CLI_ENABLE
        printPgmString(PSTR("PA6 is running\n"));
        #endif
        program_A6();
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
    // set the pins
    program_A3_init();
    for (;;)
    {
        // trun on and off the LED with fade
        led_fade_on_off(A3_LED1, 10);

        // wait
        delay_ms(PA3_LOOP_DELAY_MS);

        //TO DO2: realtime command... it just works for reset command 
        // check if there is an interrupt 
        if (check_realtime()) { break; }
    }
    
    return 0;
}

int program_A4()
{
    // set the pins
    program_A4_init();
    for (;;)
    {
        digitalWrite(A4_LED1, HIGH);
        digitalWrite(A4_PIEPS, HIGH);
        delay_ms(PA4_LOOP_DELAY_MS);
  
        digitalWrite(A4_LED1, LOW);
        digitalWrite(A4_PIEPS, LOW);
        delay_ms(PA4_LOOP_DELAY_MS);

        //TO DO2: realtime command... it just works for reset command 
        // check if there is an interrupt 
        if (check_realtime()) { break; }
    }

    return 0;
}

int program_A4A()
{
    // set the pins
    program_A4A_init();
    for (;;)
    {
        digitalWrite(A4_LED1, HIGH);
        digitalWrite(A4_PIEPS, HIGH);
        delay_ms(PA4_LOOP_DELAY_MS);
  
        digitalWrite(A4_LED1, LOW);
        digitalWrite(A4_PIEPS, LOW);
        delay_ms(PA4_LOOP_DELAY_MS);

        //TO DO2: realtime command... it just works for reset command 
        // check if there is an interrupt 
        if (check_realtime()) { break; }
    }

    return 0;
}

int program_A4B()
{
    // set the pins
    program_A4B_init();
    for (;;)
    {
        
        led_blink(A4B_LED1, PA4B_LOOP_DELAY_MS);
        led_blink(A4B_LED2, PA4B_LOOP_DELAY_MS);
        led_blink(A4B_LED3, PA4B_LOOP_DELAY_MS);
        digitalWrite(A4B_PIEPS, HIGH);
        delay_ms(PA4B_LOOP_DELAY_MS);
        digitalWrite(A4B_PIEPS, LOW);
        delay_ms(PA4B_LOOP_DELAY_MS);

        //TO DO2: realtime command... it just works for reset command 
        // check if there is an interrupt 
        if (check_realtime()) { break; }
    }

    return 0;
}

int program_A5()
{
    // set the pins
    program_A5_init();
    for (;;)
    {
        RGB_led_color_change(random(0,255), random(0,255), random(0,255));
        delay_ms(PA5_LOOP_DELAY_MS);
       
        //TO DO2: realtime command... it just works for reset command 
        // check if there is an interrupt 
        if (check_realtime()) { break; }
    }

    return 0;
}

int program_A6()
{
    // set the pins
    program_A6_init();
    
    int clicked = 0;

    for (;;)
    {
        clicked = digitalRead(A6_BUTTON);

        if (clicked == HIGH)
        {
            led_blink(A6_LED1, 5000);
        }
        
        //TO DO2: realtime command... it just works for reset command 
        // check if there is an interrupt 
        if (check_realtime()) { break; }
    }

    return 0;
}

int program_A7()
{
    // set the pins
    program_A7_init();
    
    int moved = 0;

    for (;;)
    {
        moved = digitalRead(A7_MOTION_DETECTOR);

        if (moved == HIGH)
        {
            led_blink(A6_LED1, 5000);
        }
        
        //TO DO2: realtime command... it just works for reset command 
        // check if there is an interrupt 
        if (check_realtime()) { break; }
    }

    return 0;
}

int program_A8()
{
    // set the pins
    program_A8_init();
    
    int sensor = 0;

    for (;;)
    {
        sensor = analogRead(A8_BRIGHTNESS_SENSOR);

        printPgmString(PSTR("Sensorwert: \n"));
        printInteger(sensor);        
        printPgmString(PSTR("\n"));

        if (sensor > 512)
        {
            digitalWrite(A8_LED1, HIGH);
        }
        else
        {
            digitalWrite(A8_LED1, LOW);
        }
        
        delay_ms(PA8_LOOP_DELAY_MS);

        //TO DO2: realtime command... it just works for reset command 
        // check if there is an interrupt 
        if (check_realtime()) { break; }
    }

    return 0;
}

int program_A9()
{
    // set the pins
    program_A9_init();
    
    int knob = 0;

    for (;;)
    {
        knob = analogRead(A9_KNOB);

        digitalWrite(A9_LED1, HIGH);

        delay_ms(knob);

        digitalWrite(A9_LED1, LOW);

        delay_ms(knob);

        //TO DO2: realtime command... it just works for reset command 
        // check if there is an interrupt 
        if (check_realtime()) { break; }
    }

    return 0;
}

int program_A10()
{
    // set the pins
    program_A10_init();
    
    int tem = 0;
    int sensor = 0;

    for (;;)
    {
        sensor = analogRead(A10_TMP36);
        tem= map(sensor, 0, 410, -50, 150);

        printInteger(tem);        
        printPgmString(PSTR(" Grad Celsius\n"));

        if (tem >= 30)
        {
            digitalWrite(A10_PIEZO, HIGH);
        }
        else
        {
            digitalWrite(A10_PIEZO, LOW);
        }

        delay_ms(PA10_LOOP_DELAY_MS);
        //TO DO2: realtime command... it just works for reset command 
        // check if there is an interrupt 
        if (check_realtime()) { break; }
    }

    return 0;
}