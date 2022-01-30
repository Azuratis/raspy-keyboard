#ifndef _SYSTEM__MIDI_DRIVER__HPP
#define _SYSTEM__MIDI_DRIVER__HPP
namespace sys::dev{

  class MIDI{

  public:
    static const uint16_t BAUD_RATE = 31250;
  private:

  private:
    uint8_t index = 0x00;
    uint8_t state = 0x00;
    uint8_t byte1 = 0x00;
    uint8_t byte2 = 0x00;

  protected:
    virtual void write( uint8_t ) = 0;
    virtual bool available( void ) = 0;
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
  if( !available() )return;
  uint8_t data = read();

  

  /*switch( state ){
    default: state = value = 0x0000;
    case 0x0000: state = 0x0100|data; return;

    //>>> Load Step 1 <<<//
    case 0x018C: return; // Note Off
    case 0x019C: return; // Note On
    case 0x01AC: return; // Key Pressure
    case 0x01BC: return; // Controller Change
    case 0x01CC: return; // Program Change
    case 0x01DC: return; // Channel Pressure
    case 0x01EC: return; // Pitch Bend

    case 0x01F0: return; // System Exclusive
    case 0x01F2: return; // Song Position
    case 0x01F3: return; // Song Select
    case 0x01F5: return; // *Bus Select* (unofficial)

    case 0x01F6: return; // Tune Request
    case 0x01F7: return; // End of SysEx
    case 0x01F8: return; // Timing Tick
    case 0x01FA: return; // Start Song
    case 0x01FB: return; // Continue Song
    case 0x01FC: return; // Stop Song
    case 0x01FE: return; // Activate Sensing
    case 0x01FF: return; // System Reset
  }*/
}
#endif
