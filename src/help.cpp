#include "HEMS_Funduino.h"

int help_line(String help_line)
{
    if (help_line == HPA2B)
    {
        #ifdef CLI_ENABLE
        
        printPgmString(PSTR("\n"));
        printPgmString(PSTR("the CPU map for PA2B : \n"));

        printPgmString(PSTR("LED1 is on digital pin : "));
        printInteger(A2B_LED1);
        printPgmString(PSTR("\n"));
        
        printPgmString(PSTR("LED2 is on digital pin : "));
        printInteger(A2B_LED2);
        printPgmString(PSTR("\n"));
        
        printPgmString(PSTR("LED3 is on digital pin : "));
        printInteger(A2B_LED3);
        printPgmString(PSTR("\n"));
        
        printPgmString(PSTR("LED4 is on digital pin : "));
        printInteger(A2B_LED4);
        printPgmString(PSTR("\n"));
        
        printPgmString(PSTR("LED5 is on digital pin : "));
        printInteger(A2B_LED5);
        printPgmString(PSTR("\n"));
        
        printPgmString(PSTR("\n"));
    
        #endif
    }
    else if (help_line == HPA3)
    {
        #ifdef CLI_ENABLE
        
        printPgmString(PSTR("\n"));
        printPgmString(PSTR("the CPU map for PA3 : \n"));

        printPgmString(PSTR("LED1 is on digital pin : "));
        printInteger(A3_LED1);
        printPgmString(PSTR("\n"));
        
        printPgmString(PSTR("\n"));
        
        #endif
    
    }
    else if (help_line == HPA4)
    {
        
    }
    else
    {
        return 1;
    }
    
    return 0;
           
}
