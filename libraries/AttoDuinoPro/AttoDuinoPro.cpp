#include "AttoDuinoPro.h"

// define pins for the battery operations
const int PIN_BATT_READ_ENABLE = PD_6;
const int PIN_HALF_BATT = A11;

void setupAtto() {
  pinMode(RED_LED,   OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(BLUE_LED,  OUTPUT);
  
  pinMode(PIN_BATT_READ_ENABLE, OUTPUT);
  digitalWrite( PIN_BATT_READ_ENABLE, false );  // sets this value to low
}

float batteryReadVolts() {
  return analogReadVolts( PIN_HALF_BATT )*2.0;
}

float secs() {
  return float(micros()) * 1e-6;
}

float analogReadFloat( int pin ) {
  // analog input is 12 bits, set the scale here
  static const float scale = 1.0 / (exp2f(12)-1.0);
  return float(analogRead(pin)) * scale;
}

float analogReadVolts( int pin ) {
  return analogReadFloat( pin ) * 3.3;
}

// note, analogWrite, in
//   /Applications/Energia.app/Contents/Resources/Java/hardware/lm4f/cores/lm4f/Energia.h
// calls
//   void PWMWrite(uint8_t pin, uint32_t analog_res, uint32_t duty, unsigned int freq);
// in
//   /Applications/Energia.app/Contents/Resources/Java/hardware/lm4f/cores/lm4f/wiring_analog.c
// ... to be able to see the function, add the function declaration to Energia.h
//
// implements writing to the PWM (analog) output, at various speeds / bit-depths
// 10 bits is 78.125 kHz
void analogWriteFloat( int pin, float val, int bits ) {
  //if max or min, just write the value and exit
  val = constrain( val, 0.0, 1.0 );
  
  if( bits == 8 ) {       // make this as fast as possible, if bits == 8
    PWMWrite( pin, 255, uint32_t(255.0*val), 312500);
  }
  else if( bits == 10 ) { // make this as fast as possible, if bits == 10
    PWMWrite( pin, 1023, uint32_t(1023.0*val), 78125);
  }
  else if( bits == 11 ) { // make this as fast as possible, if bits == 11
    PWMWrite( pin, 2047, uint32_t(2047.0*val), 39063);
  }
  
  else {
    float fullCounts = exp2f( bits ) - 1;  // 2^bits-1 counts in timer
    float freq = 80e6 / exp2f( bits );     // calculate the period, assuming full processor speed
    
    uint32_t thisCounts = uint32_t(fullCounts*val);
    
    //void PWMWrite(uint8_t pin, uint32_t analog_res, uint32_t duty, unsigned int freq)
    PWMWrite( pin, fullCounts, thisCounts, freq);
  }
  
}