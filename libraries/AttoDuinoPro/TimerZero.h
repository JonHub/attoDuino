#ifndef TimerZero_h
#define TimerZero_h

// modified from and the "Getting Started with Tiva TM4C123G" workshop guide and
// http://patolin.com/blog/2014/06/29/stellaris-launchpad-energia-pt-2-timers/

#include "Arduino.h"

void startTimer( void (*callbackFunction)(), float frequency );

// tests the timer interrupts by blinking the LED ... note, this function does not exit!
void testTimer( float frequency = 1.0);

#endif