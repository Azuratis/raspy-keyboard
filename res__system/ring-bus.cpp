#include "system/ring-bus.hpp"

void sys::dev::RingBus::Port::setup( void ){}
void sys::dev::RingBus::Port::loop( void ){
  if( state == STATE__SEND )return;
  if( !available() )return;
  state |= STATE__READ;

  switch( index ){
    case -16: value.source[0] = data; index++; return;
    case -15: value.source[1] = data; index++; return;
    case -14: value.source[2] = data; index++; return;
    case -13: value.source[3] = data; index++; return;
    case -12: value.source[4] = data; index++; return;
    case -11: value.source[5] = data; index++; return;

    case -10: value.target[0] = data; index++; return;
    case  -9: value.target[1] = data; index++; return;
    case  -8: value.target[2] = data; index++; return;
    case  -7: value.target[3] = data; index++; return;
    case  -6: value.target[4] = data; index++; return;
    case  -5: value.target[5] = data; index++; return;

    case  -4: value.number = data; index++; return;
    case  -3: value.action = data; index++; return;
    case  -2: value.action = (value.action << 4)|(data >> 4);
              value.length = data; index++; return;
    case  -1: value.length = (value.length << 8)|(data >> 0);
              value.action &=  0x0FFF; value.length &= 0x0FFF;
              
              return;
  }
}


