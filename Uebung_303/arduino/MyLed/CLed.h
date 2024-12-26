/******************************************************************************
 * Declaration of the LED class to abstract the access                        *
 * CLed.h                                                                     *
 *                                                                            *
 * Module: "Embedded Systems II" - Uebung 3-03                                *
 *                                                                            *
 * Hochschule Mittweida, INW                                                  *
 * Prof. J. Thomanek                                                          *
 *                                                                            *
 ******************************************************************************/
// please include this file only once
#pragma once


// ----------------------------------------------------------------------------
//  C L A S S     D E C L R A T I O N
// ----------------------------------------------------------------------------
class CLed {

public:
 
  // --------------------------------------------------------------
  //  T Y P E  D E F I N I T I O N S
  // --------------------------------------------------------------
  // To specify the port (B,C or D)
  typedef enum {
    PB = 0,
    PC,
    PD
  }PortType_t;
  
  // --------------------------------------------------------------
  //  C o n s t r u c t o r s   D e c l a r a t i o n
  // --------------------------------------------------------------
  CLed();
  CLed(PortType_t eP, unsigned char u8B, bool bVcc);


  // --------------------------------------------------------------
  //  P u b l i c   M e t h o d s   De c l a r a t i o n
  // --------------------------------------------------------------
  void On();
  void Off();
  void Toggle();
  bool IsOn();
  
private:

  // Constants members to specify the register addresses 
  const unsigned char PORTADDR[3] = {0x25,0x28,0x2B}; //{PORTB, PORTC, PORTD}
  const unsigned char DDRADDR[3]  = {0x24,0x27,0x2A}; //{DDRB, DDRC, DDRD}
  
  // Attributes of LED classe
  unsigned char* m_pu8Port;  // Address to output register
  unsigned char* m_pu8DDR;   // Address to Data Direction Registers
  unsigned char  m_u8BitMsk; // Bit mask to specify the Pin
  bool           m_bVccConn; // Flag to indicate if LED is connected against 
                             // Power Supply  
  
};
