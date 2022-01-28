#ifndef _SYSTEM__MIDI_DRIVER__HPP
#define _SYSTEM__MIDI_DRIVER__HPP
namespace sys::dev{

  class MIDI{

  public:
    static const uint16_t BAUD_RATE = 31250;

  protected:

    virtual void write( uint8_t ) = 0;
    virtual bool availalbe( void ) = 0;
    virtual uint8_t read( void ) = 0;

  public:
    void setup( void );
    void loop( void );
  };

}

/*----------------------*\
|* <-->> CPP-FILE <<--> *|
\*----------------------*/

void sys::dev::MIDI::setup( void ){}
void sys::dev::MIDI::loop( void ){
}
#endif
