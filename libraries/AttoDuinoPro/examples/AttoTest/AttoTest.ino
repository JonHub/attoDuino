#include <AttoDuinoPro.h>
#include "attoPinMap.h"

#define PR(x) Serial.print(x)

// leds are PF1, PF2 and PF3 ..
void setup() {
  setupAtto();    // enables the LEDS, and the battery read
}

void turnBluetoothOnAndOff() {
  while( true ) {
    BluetoothOn();  delay( 10000 );
    BluetoothOff(); delay( 10000 );
  }
}

void writeAllPins() {
  // pin 18 is the button
  // pins 21, 22, 23 are the leds
  // pins 24 and 25 are serial
  for( int p=0; p<21; ++p ) {
    if( p == 18 ) continue;
    pinMode( p, OUTPUT);
  }
  pinMode( 26, OUTPUT);

  // write red, green, blue ... these are reversed polarity
  for( int p=21; p<=23; ++p ) {
    digitalWrite( p, 0); delay( 1000 ); digitalWrite( p, 1 );
  }
  
  // write the other pins
  for( int p=0; p<21; ++p ) {
    if( p == 18 ) continue;
    digitalWrite( p, 1); delay( 1000 ); digitalWrite( p, 0 );
  }
  digitalWrite( 26, 1); delay( 1000 ); digitalWrite( 26, 0 );
}

// 13 pins, excludes LEDs
const int PWM_LIST[] = {
  4,
  5,
  6,
  7,
  12,
  13,
  14,
  15,
  16,
  17,
  18,
  19,
  20
};

void testPWM() {
  for( int i = 0; i<13; ++i ) {
    int p = PWM_LIST[i];         // get the pin from the list
    
    float startTime = secs();
    float t = 0;
    
    // flash all for one second
    while( t < 1 ) {
      t = secs() - startTime;
      float v = cosf( PI * t);
      v = constrain( v, 0, 1);
      analogWriteFloat( p, v);
    }
    analogWriteFloat( p, 0);   // make sure it's off
  }
}

void testAnalogIn() {
  // test the 0-10 analog inputs
  for( int p = 0; p<11; ++p ) {
    pinMode( p, INPUT);
  }
  
  PR( "A0: " ); PR( 100.0 * analogReadFloat( 0 ) ); PR( "\n" );
  PR( "A1: " ); PR( 100.0 * analogReadFloat( 1 ) ); PR( "\n" );
  PR( "A2: " ); PR( 100.0 * analogReadFloat( 2 ) ); PR( "\n" );
  PR( "A3: " ); PR( 100.0 * analogReadFloat( 3 ) ); PR( "\n" );
  PR( "A4: " ); PR( 100.0 * analogReadFloat( 4 ) ); PR( "\n" );
  PR( "A5: " ); PR( 100.0 * analogReadFloat( 5 ) ); PR( "\n" );
  PR( "A6: " ); PR( 100.0 * analogReadFloat( A6 ) ); PR( "\n" );
  PR( "A7: " ); PR( 100.0 * analogReadFloat( A7 ) ); PR( "\n" );
  PR( "A8: " ); PR( 100.0 * analogReadFloat( A8 ) ); PR( "\n" );
  PR( "A9: " ); PR( 100.0 * analogReadFloat( A9 ) ); PR( "\n" );
  PR( "A10: " ); PR( 100.0 * analogReadFloat( A10 ) ); PR( "\n" );
  PR( "BATT: " ); PR( 2.0 * analogReadVolts( A11 ) ); PR( "\n" );

  PR("\n\n");
  delay( 1000 );
}

void simpleColors() {
  long i = 0;
  byte b = 0;
  while( true ) {
    ++i;
    ++b;

    float t = secs();

    // use a fast PWM to write to LEDs
    float r = 0.5 + 0.5*cosf( TWO_PI / (3.0*PI) * t);
    float g = 0.5 + 0.5*cosf( TWO_PI / (7.0*expf(1.0)) * t);
    float b = 0.5 + 0.5*cosf( TWO_PI / (5.0*sqrtf(2.0)) * t);
    
    analogWriteFloat( RED_LED,   r );
    analogWriteFloat( GREEN_LED, g );
    analogWriteFloat( BLUE_LED,  b );

    delay( 1 );  // this is required to have a smooth fade (can't update faster than the PWM)

  }
}


void loop() {
  delay( 1000 );
  testAnalogIn();
  //testPWM();
  //writeAllPins();
  //delay(10000); turnBluetoothOnAndOff();
  
  //simpleColors();
  //writeAllPins();
  
  //simpleColorsFastPWM();
  //testLoop();
}
