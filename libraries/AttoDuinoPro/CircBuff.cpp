#include "CircBuff.h"
#include "Arduino.h"

CircBuff::CircBuff( int size, float initialVal ) {
  Size = size;
  DataArray = new float [Size];
  
  iter = -1;
  
  // populate array with an an initial value
  for( int i=0; i<Size; ++i ) {
    DataArray[i] = initialVal;
  }
}

CircBuff::~CircBuff() {
  delete[] DataArray;
}

void CircBuff::push( float val ) {
  ++iter;
  iter = iter % Size;   // make sure this stays in range
  
  DataArray[iter] = val;
}

float CircBuff::getLastValue() {
  return DataArray[iter];
}

float CircBuff::getMean() {
  float sum = 0;

  for( int i=0; i<Size; ++i )
    sum += DataArray[i];

  return sum / float(Size);
}

float CircBuff::getSum() {
    float sum = 0;
    
    for( int i=0; i<Size; ++i )
        sum += DataArray[i];
    
    return sum;
}

float CircBuff::getVar() {
  // sigma is <
  float meanSq = 0;

  for( int i=0; i<Size; ++i )
    meanSq += sq(DataArray[i]);
  
  meanSq /= float(Size);
  
  // for now, use /N, rather than /(N-1) ...
  return meanSq - sq(getMean());
}

float CircBuff::getSigma() {
  return sqrt(getVar() );
}

//jd - should probably keep this from a divide by zero
float CircBuff::getCV() { return getSigma() / getMean(); }

void CircBuff::print() {
  Serial.print( "[" );
  for( int i=0; i<Size - 1; ++i ) {
    Serial.print( DataArray[i] );
    Serial.print( " " );
  }
  Serial.print( DataArray[Size-1]);  // print the last element (no space afterwards
  Serial.print("]");
  
  Serial.print( "\tmean: " ); Serial.print( getMean() );

  Serial.print( "\tvar: " ); Serial.print( getVar() );

  Serial.print( "\tsigma: "); Serial.print( getSigma() );
  
  Serial.print( "\tcv: "); Serial.print( getCV() );
  
  Serial.print( "\n" );
}

void testBuff() {
  /*
  Serial.print( "Testing the circuilar buffer, using 6 elements ...\n");
  
  CircBuff testBuff( 6, 1 );
  
  Serial.print( "Created: \n");
  
  testBuff.print();
  
  Serial.print( "Added elements 1 through 6:\n");
  
  for( int i=1; i<7; ++ i)
    testBuff.push( i );
  
  Serial.print( "mean should be 3.5, var should be 2.92, and sigma should be 1.71, cv should be 0.49\n" );
  
  testBuff.print();
  
  Serial.print( "Adding two zeros: \n" );
  
  testBuff.push( 0 );
  testBuff.push( 0 );
  
  testBuff.print();
   */
}