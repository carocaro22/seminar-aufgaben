/******************************************************************************
 * Definition of the TrafficControl class to define the state machine         *
 * CTrafficControl.cpp                                                        *
 *                                                                            *
 * Module: "Embedded Systems II" - Uebung 3-05                                *
 *                                                                            *
 * Hochschule Mittweida, INW                                                  *
 * Prof. J. Thomanek                                                          *
 *                                                                            *
 ******************************************************************************/
#include "CTrafficControl.h"
#include "arduino.h"


// ----------------------------------------------------------------------------
//  L o c a l   D e f i n e s (C o n s t a n t s)
// ----------------------------------------------------------------------------

//  State machine states 
// ---------------------------------------------------------------------------- 
// masks
#define STATE_LEVEL1_MSK 0x0F   // level 1: On/Off-Modus
#define STATE_LEVEL2_MSK 0xFF   // level 2: different lights

// level 1
#define STATE_OP_OFF 0x01       // No-operation (yellow flashing)
#define STATE_OP_ON  0x02       // Normal operation

// level 2
#define STATE_YELLOW_OFF  (STATE_OP_OFF | 0x10)  // Yellow-Flashing Off
// ...
// ...


//  Times in 100 ms ticks
// ----------------------------------------------------------------------------
#define TIME_OP_OFF_YELLOW       5  // 0.5s - time of flashing yellow 
                                    // (out of order)

#define TIME_OP_ON_RDY_TO_DRV   10  //   1s - time of red/yellow 
#define TIME_OP_ON_RDY_TO_STP   10  //   1s - time of yellow
#define TIME_OP_ON_GO_MIN      100  //  10s - minimum time of green

#define TIME_OP_ON_PEDEST_SAFE  15  // 1.5s - safety time between red and walk
#define TIME_OP_ON_PEDEST_WALK  50  //  5s   - time of pedestrian walking


// ----------------------------------------------------------------------------
//  D e f i n i t i o n   C o n s t r u c t o r s
// ----------------------------------------------------------------------------
CTrafficControl::CTrafficControl() : m_u8State(STATE_YELLOW_OFF),
                                     m_u8Timer(TIME_OP_OFF_YELLOW),
                                     m_u8Operation(0),
                                     m_bSigRequest(false) { }

CTrafficControl::CTrafficControl(unsigned char ptRed,
                                 unsigned char ptYellow,
                                 unsigned char ptGreen,
                                 unsigned char ptStop,
                                 unsigned char ptGo) : m_u8State(STATE_YELLOW_OFF),
                                                       m_u8Timer(TIME_OP_OFF_YELLOW),
                                                       m_u8Operation(0),
                                                       m_bSigRequest(false) 
{ 
   m_oPdLght = CPedesLight(ptStop, ptGo);
   m_oTrLght = CTrafficLight(ptRed, ptYellow, ptGreen);
}
  

// ----------------------------------------------------------------------------
//  D e f i n i t i o n   M e t h o d s
// ----------------------------------------------------------------------------

void CTrafficControl::Process() {

  // ---> TO DO ... <---

}


  
