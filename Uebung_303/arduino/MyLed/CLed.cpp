/******************************************************************************
 * Definition of the LED class to abstract the access                         *
 * CLed.cpp                                                                   *
 *                                                                            *
 * Module: "Embedded Systems II" - Uebung 3-03                                *
 *                                                                            *
 * Hochschule Mittweida, INW                                                  *
 * Prof. J. Thomanek                                                          *
 *                                                                            *
 ******************************************************************************/
#include "CLed.h"


// ----------------------------------------------------------------------------
//  D e f i n i t i o n   C o n s t r u c t o r s
// ----------------------------------------------------------------------------

// Standard constructor - use the internal LED of the board (Port B5) 
CLed::CLed() {
  
  // Initialize attributes
  m_pu8Port = PORTADDR[PB]; 
  m_pu8DDR  = DDRADDR[PB];
  m_u8BitMsk = (1 << 5);
  m_bVccConn = false;
       
  // set output direction
  *m_pu8DDR |= m_u8BitMsk;

  // Switch led off
  Off();
}

// Constructor 
CLed::CLed(PortType_t eP, unsigned char u8B, bool bVcc) {
 
  // Initialize attributes
  m_pu8Port = PORTADDR[eP]; 
  m_pu8DDR = DDRADDR[eP];
  m_u8BitMsk = (1 << u8B);
  m_bVccConn = bVcc;
       
  // set output direction
  *m_pu8DDR |= m_u8BitMsk;

  // Switch led off
  Off();
}

// ----------------------------------------------------------------------------
//  D e f i n i t i o n   M e t h o d s
// ----------------------------------------------------------------------------

// Switch LED on
void CLed::On() {
  if (m_bVccConn) 
    *m_pu8Port &= ~m_u8BitMsk;
  else
    *m_pu8Port |= m_u8BitMsk;  
}

// Switch LED off
void CLed::Off() {
  if (m_bVccConn) 
    *m_pu8Port |= m_u8BitMsk;
  else
    *m_pu8Port &= ~m_u8BitMsk; 
}

// Change state of LED
void CLed::Toggle() {
  *m_pu8Port ^= m_u8BitMsk;
}

// Get current state of LED
bool CLed::IsOn() {
  return (!m_bVccConn == (*m_pu8Port & m_u8BitMsk));
}
  
