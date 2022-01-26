#include "system/ring-bus__lmic.hpp"
#include "values.hpp"

void RingBus::write( uint8_t b ){ Serial1.write(b); delay(1); }
bool RingBus::available( void ){ return Serial1.available(); }
uint8_t RingBus::read( void ){ return Serial1.read(); }

void setup(){
  Serial.begin( STDIO__BAUD );
  Serial1.begin( RING_BUS__BAUD );
  while( !Serial || !Serial1 ) yield();

  RingBus::setup();
}

void loop(){
  RingBus::loop();
}
