#ifndef _RING_BUS__HPP
#define _RING_BUS__HPP
/*--> Alterted Version of Ring-Bus for Low-Memory ICs <-----*\
\*----------------------------------------------------------*/
#define RING_BUS__BAUD 115200

namespace RingBus{
  const uint8_t STATE__IDLE = 0x0;
  const uint8_t STATE__SEND = 0x1;
  const uint8_t STATE__READ = 0x2;
  const uint8_t STATE__THRU = 0x3;

  extern void write( uint8_t );
  extern bool available( void );
  extern uint8_t read( void );

  uint8_t state = 0x0;
  int16_t index = -16;

  void setup( void );
  void loop( void );
}

void RingBus::setup( void ){}
void RingBus::loop( void ){
  if( state == STATE__SEND ) return;
  if( !available() ) return;
  uint8_t data = read();
  state |= STATE__READ;

  switch( index ){
    case -16: return;
  }
}

#endif
