#ifndef _SYSTEM__RING_BUS__HPP
#define _SYSTEM__RING_BUS__HPP
#define RING_BUS__BAUD 115200
namespace sys::dev::RingBus{

  struct Message;
  class Device;
  class Port;

  struct Message{
    uint8_t source[6];
    uint8_t target[6];
    uint8_t number = 0;
    uint16_t action = 0;
    uint16_t length = 0;
  };

  class Port{
    const uint8_t STATE__IDLE = 0x00;
    const uint8_t STATE__SEND = 0x01;
    const uint8_t STATE__READ = 0x02;
    const uint8_t STATE__THRU = 0x03;

    uint8_t state = STATE__IDLE;
    Message value = {0};
    int16_t index = -16;
  protected:
    virtual void write( uint8_t ) = 0;
    virtual bool available( void ) = 0;
    virtual uint8_t read( void ) = 0;

  public:
    void setup( void );
    void loop( void );
  };

  class Device{
    friend class Port;

  protected:
    virtual void begin( Message& ) = 0;
    virtual void apply( uint8_t ) = 0;
    virtual void end( void ) = 0;

  public:

  };
}

void sys::dev::RingBus::Port::setup( void ){}
void sys::dev::RingBus::Port::loop( void ){
  if( state == STATE__SEND )return;
  if( !available() )return;
  state |= STATE__READ;
  uint8_t data = read();

}
#endif
