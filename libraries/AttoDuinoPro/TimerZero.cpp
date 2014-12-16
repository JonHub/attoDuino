#include "TimerZero.h"

#include "Arduino.h"
#include "inc/hw_ints.h"
#include "driverlib/interrupt.h"
#include "driverlib/sysctl.h"
#include "driverlib/timer.h"

// holds the location of the user's code to run on timer interrupt
static void (*userCallbackFunctionPointer)();

void _timerCallback() {
  TimerIntClear (TIMER0_BASE, TIMER_TIMA_TIMEOUT);  // reset the timer
  (*userCallbackFunctionPointer)();                 // call the user's function
}

void startTimer ( void (*callbackFunction)(), float frequency) {
  userCallbackFunctionPointer = callbackFunction;
  
  SysCtlPeripheralEnable (SYSCTL_PERIPH_TIMER0);
  TimerConfigure (TIMER0_BASE, TIMER_CFG_PERIODIC);
  
  //unsigned long ulPeriod = (SysCtlClockGet () / Hz);
  unsigned long ulPeriod = long(float(SysCtlClockGet ()) / frequency);
  TimerLoadSet (TIMER0_BASE, TIMER_A, ulPeriod -1);
  
  IntEnable (INT_TIMER0A);
  TimerIntEnable (TIMER0_BASE, TIMER_TIMA_TIMEOUT);
  
  //TimerIntRegister (TIMER0_BASE, TIMER_A, Timer0IntHandler);  // this is IntMasterEnable(); in the workshop
  TimerIntRegister (TIMER0_BASE, TIMER_A, _timerCallback );  // this is IntMasterEnable(); in the workshop
  
  TimerEnable (TIMER0_BASE, TIMER_A);
}

void testTimerCallback() {
  static int j = 0;
  digitalWrite (RED_LED, j % 2);
  j ++;
}

// tests the timer interrupts by blinking the LED ... note, this function does not exit!
void testTimer( float frequency) {
  pinMode (RED_LED, OUTPUT);
  startTimer( testTimerCallback, frequency );
  while( true );
}

