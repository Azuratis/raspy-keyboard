#ifndef _SYSTEM__RING_BUS__HPP
#define _SYSTEM__RING_BUS__HPP
namespace sys::dev::ringbus{

  struct Header{
    uint8_t source[6];
    uint8_t target[6];
    uint8_t number = 0;
    uint16_t action = 0;
    uint16_t length = 0;
  };

  class Port{

  protected:
    virtual void write( uint8_t ) = 0;
    virtual bool available( void ) = 0;
    virtual uint8_t read( void ) = 0;
  
  public:
    void setup( void );
    void loop( void );
  };
}


void sys::dev::ringbus::Port::setup( void ){}
void sys::dev::ringbus::Port::loop( void ){}

#endif
