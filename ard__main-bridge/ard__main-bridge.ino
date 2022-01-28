#include "system/ring-bus.hpp"
#include "values.hpp"
#define MIDI_BUS__BAUD 44500

const class RingBus_class
: public sys::dev::RingBus::Port{
  void write( uint8_t data ){ Serial1.write(data); delay(1); }
  bool available( void ){ return Serial1.available(); }
  uint8_t read( void ){ return Serial1.read(); }
} RingBus;



void setup(){
  Serial.begin( STDIO__BAUD );
  Serial1.begin( RING_BUS__BAUD );
  Serial2.begin( MIDI_BUS__BAUD );

  RingBus.setup();
}

void loop() {
  RingBus.loop();
}
