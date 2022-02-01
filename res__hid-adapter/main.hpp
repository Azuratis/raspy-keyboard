#ifndef _HID_ADAPTER__MAIN__HPP
#define _HID_ADAPTER__MAIN__HPP
#include <Keyboard.h>
#include <Mouse.h>
namespace sys::dev{

  /*--> Hid Device - Action List <-----------*\
  |*  act | size | 
  |* -----+------+-----------
  |*  000 |    1 | Press Key
  |*  001 |    1 | Release Key
  |*  002 |    1 | Click Key
  |* ·····|······|···················
  |*  010 |    1 | Mouse Press Button
  |*  011 |    1 | Mouse Release Button
  |*  012 |    1 | Mouse Click Button
  |* ·····|······|···················
  |*  018 |    4 | Mouse Move to Point
  |*  019 |    4 | Mouse Move relative
  |*  01A |      |
  \*-----------------------------------------*/
  class HideAdapter{

  public:
    static const PROGMEM uint8_t SELECT_DEVICE     = 0x00;
    static const PROGMEM uint8_t KEYBOARD_PRESS    = 0x01;
    static const PROGMEM uint8_t KEYBOARD_RELEASE  = 0x02;
    static const PROGMEM uint8_t KEYBOARD_CLICK    = 0x03;
    static const PROGMEM uint8_t KEYBOARD_CLEAR    = 0x04;
  protected:
    uint8_t flags = 0x00;

    //---> <·> SELECT_DEVICE <·> <---//
    void act000_ready( void ){ flags |= 0x07; }
    void act000_close( void ){}
    void act000_apply( uint8_t data ){
      //---> <!!!> Execution order is relevant <!!!> <---//
      if( flags == 0x02 ) flags = (data=='0') ? 0x01 : 0x00;
      if( flags == 0x03 ) flags = (data=='M') ? 0x02 : 0x00;
      if( flags == 0x04 ) flags = (data=='O') ? 0x03 : 0x00;
      if( flags == 0x05 ) flags = (data=='C') ? 0x04 : 0x00;
    }

    //---> <·> KEYBOARD_PRESS <·> <---//
    void act001_ready( void ){}
    void act001_close( void ){}
    void act001_apply( uint8_t data ){
      if( flags ) Keyboard.press( data );
    }
  }
}
#endif
