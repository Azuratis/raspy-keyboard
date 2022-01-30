#include "system/ring-bus.hpp"
//#include <Keyboard>
#include <Mouse.h>

const class RingBus__class
: public sys::dev::ringbus::Port{

protected:
  void write( uint8_t b ){ Serial1.write(b); }
  bool available( void ){ return Serial1.available(); }
  uint8_t read( void ){ return Serial1.read(); }
public:
  RingBus__class(){}
} RingBus;

/*-----------------------------------------------------------------*\
|* <·> <·> <·> <·> <·>  Main Function Segment  <·> <·> <·> <·> <·> *|
\*-----------------------------------------------------------------*/

void setup( void ){
  RingBus.setup();
}
void loop( void ){
  RingBus.loop();
}
