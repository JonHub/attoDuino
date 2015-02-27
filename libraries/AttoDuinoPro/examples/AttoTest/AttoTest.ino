#include <AttoDuinoPro.h>
#include "attoPinMap.h"

#define PR(x) Serial.print(x)

// leds are PF1, PF2 and PF3 ..

void BluetoothOff() {
  // use a dummy pin for now
  // flip pin low to hold in reset
  // note, never flip pin to a high output!
  // the module is not 3.3V tollerant
  // note, output must be set before specifying a value
  // this causes the pin to go high for about 2 microseconds
  // ... however, the RC filter on the board takes care of this
  // tau on the board reset is 1 ms, though
  // takes about 50 ms to get around to this
  // the weak PU on the BT module is about 30 to 50k
  
  pinMode( PIN_BT_RESET, OUTPUT );
  digitalWrite( PIN_BT_RESET, 0 );
}

void BluetoothOn() {
  // flip to input (high impedance) to allow reset pin to come high
  // note, never flip pin to a high output!
  // the module is not 3.3V tollerant
  pinMode( PIN_BT_RESET, INPUT );
  Serial.begin( 460800 );
}

void setup() {
  //BluetoothOff();
  // put your setup code here, to run once:

  // setup LEDs, and write them to zero
  pinMode( RED_LED, OUTPUT);   digitalWrite( RED_LED,   1 );
  pinMode( GREEN_LED, OUTPUT); digitalWrite( GREEN_LED, 1 );
  pinMode( BLUE_LED, OUTPUT);  digitalWrite( BLUE_LED,  1 );
  
  // the general button is left in a weak pull-up state from the bootloader ...
  // this is fine, keep it!
  
  // Digital Pins Setup
  /*
  pinMode( D0, OUTPUT);
  pinMode( D1, OUTPUT);
  pinMode( D2, OUTPUT);
  pinMode( D3, OUTPUT);
  pinMode( D4, OUTPUT);
  pinMode( D5, OUTPUT);
  pinMode( D6, OUTPUT);
  pinMode( D7, OUTPUT);
  pinMode( D8, OUTPUT);
  pinMode( D9, OUTPUT);
  pinMode( D10, OUTPUT);
  //pinMode( D11, OUTPUT);
  pinMode( D12, OUTPUT);
  pinMode( D13, OUTPUT);
  pinMode( D14, OUTPUT);
  pinMode( D15, OUTPUT);
  pinMode( D16, OUTPUT);
  pinMode( D17, OUTPUT);
  //pinMode( D18, OUTPUT);  // general button, don't set as output!
  pinMode( D19, OUTPUT);
  pinMode( D20, OUTPUT);
  pinMode( D21, OUTPUT);
  pinMode( D22, OUTPUT);
  pinMode( D23, OUTPUT);
  // D24 and D25 are TX / RX, don't touch these ...
  
  pinMode( D26, OUTPUT);
  */
}

void turnBluetoothOnAndOff() {
  while( true ) {
    BluetoothOn();  delay( 10000 );
    BluetoothOff(); delay( 10000 );
  }
}

void writeAllPins() {
  digitalWrite( D0, 1); delay(1000); digitalWrite( D0,0 );
  digitalWrite( D1, 1); delay(1000); digitalWrite( D1,0 );
  digitalWrite( D2, 1); delay(1000); digitalWrite( D2,0 );
  digitalWrite( D3, 1); delay(1000); digitalWrite( D3,0 );
  digitalWrite( D4, 1); delay(1000); digitalWrite( D4,0 );
  digitalWrite( D5, 1); delay(1000); digitalWrite( D5,0 );
  digitalWrite( D6, 1); delay(1000); digitalWrite( D6,0 );
  digitalWrite( D7, 1); delay(1000); digitalWrite( D7,0 );
  digitalWrite( D8, 1); delay(1000); digitalWrite( D8,0 );
  digitalWrite( D9, 1); delay(1000); digitalWrite( D9,0 );
  digitalWrite( D10, 1); delay(1000); digitalWrite( D10,0 );
  //  digitalWrite( D11, 1); delay(1000); digitalWrite( D11,0 );
  digitalWrite( D12, 1); delay(1000); digitalWrite( D12,0 );
  digitalWrite( D13, 1); delay(1000); digitalWrite( D13,0 );
  digitalWrite( D14, 1); delay(1000); digitalWrite( D14,0 );
  digitalWrite( D15, 1); delay(1000); digitalWrite( D15,0 );
  digitalWrite( D16, 1); delay(1000); digitalWrite( D16,0 );
  digitalWrite( D17, 1); delay(1000); digitalWrite( D17,0 );
  digitalWrite( D18, 1); delay(1000); digitalWrite( D18,0 );
  digitalWrite( D19, 1); delay(1000); digitalWrite( D19,0 );
  digitalWrite( D20, 1); delay(1000); digitalWrite( D20,0 );

  digitalWrite( D21, 1); delay(1000); digitalWrite( D17,0 );
  digitalWrite( D22, 1); delay(1000); digitalWrite( D18,0 );
  digitalWrite( D23, 1); delay(1000); digitalWrite( D19,0 );

  digitalWrite( D26, 1); delay(1000); digitalWrite( D20,0 );

  /*
  if( !digitalRead( PF_4 ) ) {
    delay( 1000 );
    return;
  }
   */
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
    
    /*
    if( !digitalRead( PF_4 ) ) {
      analogWriteFloat( RED_LED,   1 );
      analogWriteFloat( GREEN_LED, 1 );
      analogWriteFloat( BLUE_LED,  1 );

      delay( 1000 );
      return;
    }
     */
  }
}


void loop() {
  //delay(10000); turnBluetoothOnAndOff();
  
  simpleColors();
  //writeAllPins();
  
  //simpleColorsFastPWM();
  //testLoop();
}
