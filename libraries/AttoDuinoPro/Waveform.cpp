#include "Waveform.h"
#include "AttoDuinoPro.h"


Waveform::Waveform( float freq, float phase) {
  Freq = freq;
  Type = DC;   // default to DC
  
  resetPhase();
}

void Waveform::resetPhase( float phase ) {
  Phase = phase;
  StartTime = secs();
}

float Waveform::getTime() { return secs() - StartTime; }

float Waveform::getAngle( float phaseShift ) {
  // returns the argument to the sin function, 
  // which is a number from 0 to PI
  float time = getTime();

  return 2*PI*Freq*time + Phase + phaseShift;   // take the sin of this to get the amplitude ... 
}

float Waveform::getPosition( float phaseShift ) {
  // returns the ccurent position
  // the phaseShift is any additional shift
  // this can be used to look forward (negative phase shift)
  // or backward (positive phase shift in time
  // or get the cosine component (positive PI/2 phase shift)

  float angle = getAngle(phaseShift);
  float returnVal;

  // return the appropriate waveform ... use switches

  switch (Type) {
  case DC:                            
    returnVal = 1;
    break;

  case SIN:                                          // standard sine wave ranges from 0 to 1 (starts at zero)   
    returnVal = sin(angle);
    break;

  case SIN_01:                                       // sine wave that ranges from 0 to 1 (starts at zero)            
    returnVal = 0.5*(1.0 - cos(angle)); 
    break;

  case TRIANGLE:                                         // triangle wave from -1 to 1 (starts at 0)
    returnVal = .9 * (sin(angle) - 1/9*sin(3*angle));    // only two Fourire components, has rounded cornerss
    break;
    
  case TRIANGLE_01:                                   // triangle wave  ranges from 0 to 1 (starts at 0)
    angle += HALF_PI;                                 // shift the phase to start the wave at 0
    returnVal = 0.5*(1.0-.9 * (sin(angle) - 1/9*sin(3*(angle))));
    break;
    
  case SAWTOOTH_THREE_01:                            // sawtooth with three pulses, range is 0 to 1 (starts at 0)
    angle += 3.927;                                  // shift the phase to start the wave at 0
    returnVal = 0.5*(1.0+0.693*(sin(angle) - sin(2*angle)/2 + sin(3*angle)/3));
    break;

  case SAWTOOTH_FOUR_01:                           // sawtooth with four pulses, range is 0 to 1 (starts at 0)
    angle += 3.770;                                  // shift the phase to start the wave at 0
    returnVal = 0.5*(1.0+0.654*(sin(angle) - sin(2*angle)/2 + sin(3*angle)/3 - sin(4*angle)/4)); 
    break;
    
  case SAWTOOTH_FIVE_01:                             // sawtooth with five pulses, range is 0 to 1 (starts at 0)
    angle += 3.663;                                  // shift the phase to start the wave at 0
    returnVal = 0.5*(1.0+0.631*(sin(angle) - sin(2*angle)/2 + sin(3*angle)/3 - sin(4*angle)/4 + sin(5*angle)/5));
    break;
        
  case PULSE_01:
    
    break;

  case PULSE_HALF_01:                           
    // a pulse that ranges from 0 to 1 (starts at zero) 
    // and pulses for the first half of the cycle
    break;

  case PULSE_THIRD_01:                          
    break;

  case PULSE_QUARTER_01:                         
    break; 

  default:                           // no default
    ;
  } // end switch
  
  return returnVal;
}

void Waveform::setFrequency( float newFreq ) {
  // will not create a change in amplitude
  // since the phase in the cycle is preserve
  //   phase + TWO_PI*Freq*time = newPhase + TWO_PI*newFreq*time
  //   newPhase = phase + 2*PI*time*(Freq-newFreq);
  Phase += TWO_PI*getTime()*(Freq-newFreq);

  //if( Phase > PI ) Phase -= PI;
  //else if( Phase < -PI ) Phase += PI;

  Freq = newFreq;
}

