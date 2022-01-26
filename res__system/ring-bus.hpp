#ifndef _SYSTEM__RING_BUS__HPP
#define _SYSTEM__RING_BUS__HPP
namespace sys::dev::RingBus{

  struct Message;
  class Device;
  class Port;

  class Port{

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
#endif
