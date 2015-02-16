#ifndef CircBuff_h
#define CircBuff_h

class CircBuff {
public:
  
  CircBuff( int size=3, float initialVal=1 );
  ~CircBuff();
  
  void push( float val );
  
  float getLastValue();
  
  float getMean();
    
  float getSum();
  
  float getVar();
  
  float getSigma();
  
  float getCV();
  
  void print();
  
private:
  int Size;  // size of the buffer (length)
  float* DataArray;
  
  int iter;  // iterator for the DataArray
};

void testBuff();

#endif

// variance of a six-sided die is 35/12, or 2.92 ... this is a good test