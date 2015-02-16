#ifndef Waveform_h
#define Waveform_h

#include "Arduino.h"

// move this someplace else at some point ...
void waveformTestApp();

// tests the waveform by printing to screen
void waveformPrintTest();

enum WaveformType {
  DC,                   // constant value (1), but can be useful to implement fade-in and fade-out
  SIN,                  // sine wave [-1 1], starts at 0
  SIN_01,               // sine wave [0 1], starts at 0
  TRIANGLE,             // simple triangle with rounded edges [-1 1], starts at 0
  TRIANGLE_01,          // simple triangle with rounded edges [0 1], starts at 0
  SAWTOOTH_THREE_01,    // rising sawtooth, made of three pulses [0 1], starts at 0
  SAWTOOTH_FOUR_01,     // rising sawtooth, made of four pulses [0 1], starts at 0
  SAWTOOTH_FIVE_01,     // rising sawtooth, made of five pulses [0 1], starts at 0
  N_WAVEFORM_TYPES,
  
  PULSE_01,
  PULSE_HALF_01,
  PULSE_THIRD_01,
  PULSE_QUARTER_01
};

struct Waveform {
  // encapsulates an oscillator in the form
  //   Pos = Amp*sin(2*PI*Freq*time + Phase)
  // resolution is milliseconds, to prevent counter wraparound
  // (this could be changed in future releases)
  // phase is typically not useful to the user,
  // but is adjusted internally when the frequency changes
  // to keep the position continuous
  //
  // note - there is no need to call update() on this class!float
  //        solutions are analytic, and just a function of time
  float Freq;
  float Phase;
  float StartTime;
  
  public:
  Waveform( float freq=1, float phase=0 );
  WaveformType Type;

  // returns the current position
  float getPosition( float phaseShift = 0 );
  
  float getAngle( float phaseShift = 0 );

  void setFrequency( float newFreq );
  
  float getTime();
  
  void resetPhase( float phase=0 );

  void fadeIn( float fadeInTime=1 ) {}

  void fadeOut( float fadeInTime=1) {}
};

#endif
