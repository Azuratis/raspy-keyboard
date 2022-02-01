#include "system/ring-bus.hpp"
#include <Keyboard.h>
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

// <·> <·> <·> RB-Serial <·> <·> <·> //
const class SerialRB__class
: public sys::dev::ringbus::Device{

protected:
  bool cmpName( uint8_t id[6] ){
    return id[0] == 'S'
        && id[1] == 'e'
        && id[2] == 'r'
        && id[3] == 'i'
        && id[4] == 'a'
        && id[5] == 'l' ; 
  }
  void write( uint8_t data ){
    if( RingBus.select & 0x01 ) return;
    switch( RingBus.action ){
      case 0x000: act000w( data ); return;
      case 0x001: act001w( data ); return;
      case 0x002: act002w( data ); return;
    }
  }
public:
  const PROGMEM uint8_t NAME[6] = {'S','e','r','i','a','l'};
  SerialRB__class(){}
} SerialRB;

/*-----------------------------------------------------------------*\
|* <·> <·> <·> <·> <·>  Main Function Segment  <·> <·> <·> <·> <·> *|
\*-----------------------------------------------------------------*/

void setup( void ){
  RingBus.setup();
}
void loop( void ){
  RingBus.loop();
}
