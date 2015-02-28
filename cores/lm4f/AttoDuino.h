#ifndef AttoDuinoPro_h
#define AttoDuinoPro_h

#include "Energia.h"

#define PR(x) (Serial.print(x))            /* make it easier to print a line */

// sets up the pins for the Atto
void setupAtto();

// returns the battery voltage, in volts
float batteryReadVolts();

// turns on bluetooth (release from reset), and starts serial port
void BluetoothOff();

// turns off bluetooth module (holds in reset)
void BluetoothOn();

// return elapsed time, in seconds
float secs();

// returns the analog value as a float, in the range [0,1.0]
float analogReadFloat( int pin );

// returns the analog value as a float, in the range [0,3.3]
float analogReadVolts( int pin );

// analog write, with a floating point number (0 to 1), and FAST update
// (10 bits is 78.125 kHz)
void analogWriteFloat( int pin, float val, int bits=10 );

#endif
