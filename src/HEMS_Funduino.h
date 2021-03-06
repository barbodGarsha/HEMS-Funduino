#ifndef HEMS_Funduino_h
#define HEMS_Funduino_h

// HEMS_Funduino version
#define HEMS_FUNDUINO_VERSION "0.1"

// Define the Arduino library
#include <Arduino.h>

// Define standard libraries.
#include <avr/io.h>
#include <avr/pgmspace.h>
#include <avr/interrupt.h>
#include <avr/wdt.h>
#include <util/delay.h>
#include <math.h>
#include <inttypes.h>    
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

// Define the HEMS_Funduino system include files.
// NOTE: Do not alter organization.
#include "CPU_MAPS.h"
#include "confiq.h"
#include "prints.h"
#include "serial.h"
#include "basic_functions.h"
#include "protocol.h"
#include "pin_modes.h"
#include "programs.h"
#include "help.h"

#endif