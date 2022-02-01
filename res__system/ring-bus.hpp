#ifndef _SYSTEM__RING_BUS__HPP
#define _SYSTEM__RING_BUS__HPP
#define RingBus__BAUD 115200
namespace sys::dev::ringbus{

  struct Header{
    uint8_t source[6];
    uint8_t target[6];
    uint8_t number = 0;
    uint16_t action = 0;
    uint16_t length = 0;
  };
  struct DevID{

  };

  class Port{

  protected:
    virtual void write( uint8_t ) = 0;
    virtual bool available( void ) = 0;
    virtual uint8_t read( void ) = 0;
  
  public:
    Header meta;
    void setup( void );
    void loop( void );
  };

  class Device{
#define RingBus__comName(value) void comName( uint8_t id[6] ){ return true }
  protected:  
    virtual bool cmpName( uint8_t[6] ) = 0;
    virtual void write( uint8_t ) = 0;
    virtual void begin( void ){}
    virtual void end( void ){};
  public:
    void setup( void ){}
    void loop( void ){}
  };
}


void sys::dev::ringbus::Port::setup( void ){}
void sys::dev::ringbus::Port::loop( void ){}

#endif
