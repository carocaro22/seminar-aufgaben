/******************************************************************************
 * Declaration of the TrafficControl class to define the state machine        *
 * CTrafficControl.h                                                          *
 *                                                                            *
 * Module: "Embedded Systems II" - Uebung 3-05                                *
 *                                                                            *
 * Hochschule Mittweida, INW                                                  *
 * Prof. J. Thomanek                                                          *
 *                                                                            *
 ******************************************************************************/
// please include this file only once
#pragma once

#include "CTrafficLight.h"
#include "CPedesLight.h"

// ----------------------------------------------------------------------------
//  C L A S S     D E C L R A T I O N
// ----------------------------------------------------------------------------
class CTrafficControl {

public:
 
  // --------------------------------------------------------------
  //  C o n s t r u c t o r s   D e c l a r a t i o n
  // --------------------------------------------------------------
  CTrafficControl();
  
  CTrafficControl(unsigned char ptRed,
                  unsigned char ptYellow,
                  unsigned char ptGreen,
                  unsigned char ptStop,
                  unsigned char ptGo);                  

  
  // --------------------------------------------------------------
  //  P u b l i c   M e t h o d s   De c l a r a t i o n
  // --------------------------------------------------------------
  // To process the state machine - must be called cyclically 
  // by the application
  void Process();

  // Set functions
  void SetRequest()                {m_bSigRequest = true;}
  void SetOpMode(unsigned char op) {m_u8Operation = op;}
  
private:
  
  // --------------------------------------------------------------
  //  P r i v a t e   A t t r i b u t e s
  // --------------------------------------------------------------

  unsigned char m_u8State;     // State Machine variable
  unsigned char m_u8Timer;     // Counter variable in 100 ms ticks
  unsigned char m_u8Operation; // Operation Mode: Out-of-order or Normal operation
  bool          m_bSigRequest; // Button pressed flag
  
  CPedesLight   m_oPdLght;     // Pedestrian light object
  CTrafficLight m_oTrLght;     // Traffic light object

  
    
};
