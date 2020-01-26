#include "HEMS_Funduino.h"

//each function here will set the in/output pins for each program

void program_A2B_init()
{
    // Setting pins 3,4,5,6,7 as outputs for the LEDs
    pinMode(A2B_LED1, OUTPUT);
    pinMode(A2B_LED2, OUTPUT);
    pinMode(A2B_LED3, OUTPUT);
    pinMode(A2B_LED4, OUTPUT);
    pinMode(A2B_LED5, OUTPUT);
}

void program_A3_init()
{
    // Setting pin 3 as output for the LED1
    pinMode(A3_LED1, OUTPUT);
}

void program_A4_init()
{
    // Setting pin 3 as output for the LED1
    pinMode(A4_LED1, OUTPUT);
    // Setting pin 2 as output for the PIEPS
    pinMode(A4_PIEPS, OUTPUT);
}

void program_A4A_init()
{
    // Setting pin 3,4,5 as output for the LEDs
    pinMode(A4A_LED1, OUTPUT);
    pinMode(A4A_LED2, OUTPUT);
    pinMode(A4A_LED3, OUTPUT);
    // Setting pin 2 as output for the PIEPS
    pinMode(A4A_PIEPS, OUTPUT);
}

void program_A4B_init()
{
    // Setting pin 3,4,5 as output for the LEDs
    pinMode(A4B_LED1, OUTPUT);
    pinMode(A4B_LED2, OUTPUT);
    pinMode(A4B_LED3, OUTPUT);
    // Setting pin 2 as output for the PIEPS
    pinMode(A4B_PIEPS, OUTPUT);
}

void program_A5_init()
{
    pinMode(A5_LED_R, OUTPUT);
    pinMode(A5_LED_G, OUTPUT);
    pinMode(A5_LED_B, OUTPUT);
}

void program_A6_init()
{
    pinMode(A6_LED1, OUTPUT);
    pinMode(A6_BUTTON, INPUT);
}

void program_A7_init()
{
    pinMode(A7_MOTION_DETECTOR, INPUT);
    pinMode(A7_PIEZO, OUTPUT);
}

void program_A8_init()
{
    pinMode(A8_LED1, OUTPUT);
}

void program_A9_init()
{
    pinMode(A9_LED1, OUTPUT);
}

void program_A10_init()
{
    pinMode(A10_PIEZO, OUTPUT);
}

void program_A11_init(){}

/*
void program_12_init(){}

void program_13_init(){}

void program_14_init(){}

void program_15_init(){}

void program_16_init(){}

void program_17_init(){}

void program_18_init(){}

void program_19_init(){}
*/
