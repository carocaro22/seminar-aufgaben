/******************************************************************************
 * Definition of the CTrafficLight class to abstract the traffic light        * 
 * CTrafficLight.cpp                                                          *
 *                                                                            *
 * Module: "Embedded Systems II" - Uebung 3-05                                *
 *                                                                            *
 * Hochschule Mittweida, INW                                                  *
 * Prof. J. Thomanek                                                          *
 *                                                                            *
 ******************************************************************************/
#include "CTrafficLight.h"
#include "arduino.h"

// ----------------------------------------------------------------------------
//  D e f i n i t i o n   M e t h o d s
// ----------------------------------------------------------------------------

// Set state of traffic light
void CTrafficLight::SetState(StateType_t state) {
  // Red lamp 
  //---------
  if (state & LIGHTSTATE_RED_MSK) {
    digitalWrite(m_u8Port_Red, HIGH);
  }
  else {
    digitalWrite(m_u8Port_Red, LOW);
  }

  // Yellow lamp
  //------------
  if (state & LIGHTSTATE_YELLOW_MSK) {
    digitalWrite(m_u8Port_Yellow, HIGH);
  }
  else {
    digitalWrite(m_u8Port_Yellow, LOW);
  }

  // Green lamp
  //-----------
  if (state & LIGHTSTATE_GREEN_MSK) {
    digitalWrite(m_u8Port_Green, HIGH);
  }
  else {
    digitalWrite(m_u8Port_Green, LOW);
  }
}


  
