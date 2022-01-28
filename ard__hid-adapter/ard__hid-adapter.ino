#include "system/ring-bus__lmic.hpp"
#include "values.hpp"

/*const class RingBus_class
: sys::dev::RigBus::Port{
  void write( uint8_t b ){ Serial1.write(b); delay(1); }
  bool available( void ){ return Serial1.available(); }
  uint8_t read( void ){ return Serial1.read(); }
} RingBus;

const class RBSerial_class
: sys::dev::RingBus::Device{
  const uint8_t id = {'S','e','r','i','a','l'};
  
  void begin( void ){}
  void write( uint8_t b ){ Serial.write(b); }
  void end( void ){}
} RBSerial;

const class HidAdapter_class
: sys::dev::RingBus::Device{
  const uint8_t id = {'H','i','d','D','e','v'};
  void begin( void ){}
  void write( uint8_t ){}
  void end( void ){}
} HidAdapter;*/

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
