/******************************************************************************
 * Sketch for Simulation a Trffic Light                                       *
 * TrafficLight.ino                                                           *
 *                                                                            *
 * Module: "Embedded Systems II" - Uebung 3-05                                *
 *                                                                            *
 * Hochschule Mittweida, INW                                                  *
 * Prof. J. Thomanek                                                          *
 *                                                                            *
 ******************************************************************************/

// Include class definition of Traffic Control 
#include "CTrafficControl.h"

// ----------------------------------------------------------------------------
//   C O N S T A N T S    D E F I N I T I O N S
// ----------------------------------------------------------------------------

//  Port definitions
// ---------------------------------------------------------------------------- 
// traffic light
#define PORT_LED_RED        10
#define PORT_LED_YELLOW      9
#define PORT_LED_GREEN       8

// pedestrian light
#define PORT_LED_WAIT       12
#define PORT_LED_WALK       11

// button for pedestrian
#define PORT_BUTTON          2

// operator switch 
#define PORT_SWITCH          1



// ----------------------------------------------------------------------------
//   V A R I A B L E S    D E F I N I T I O N S
// ----------------------------------------------------------------------------

// TrafficControl object
CTrafficControl oTrCntl;




// ----------------------------------------------------------------------------
//   F U N C T I O N S    D E F I N I T I O N S
// ----------------------------------------------------------------------------

//  Interrupt Service Routine for Button
// ---------------------------------------------------------------------------- 
void MyISR() {
  // Inform CTrafficControl object that button was pressed
  oTrCntl.SetRequest();
}

// ----------------------------------------------------------------------------
//   A R D U I N O  F U N C T I O N S    D E F I N I T I O N S
// ----------------------------------------------------------------------------

//   Initialization function
// ----------------------------------------------------------------------------
void setup() {
  // Set Port modes 
  pinMode(PORT_LED_RED,    OUTPUT);
  pinMode(PORT_LED_YELLOW, OUTPUT);
  pinMode(PORT_LED_GREEN,  OUTPUT);
  pinMode(PORT_LED_WAIT,   OUTPUT);
  pinMode(PORT_LED_WALK,   OUTPUT);
  
  pinMode(PORT_BUTTON, INPUT);
  pinMode(PORT_SWITCH, INPUT);
  
  // Enable Interrupt for the Button port
  attachInterrupt(digitalPinToInterrupt(PORT_BUTTON), MyISR, RISING); 

  // Initialize the Traffic control object
  oTrCntl = CTrafficControl(PORT_LED_RED, PORT_LED_YELLOW, PORT_LED_GREEN,
                            PORT_LED_WAIT, PORT_LED_WALK);
}

//   Cyclic function
// ----------------------------------------------------------------------------
void loop() {

 // First check the operation mode
  // ------------------------------
  if (digitalRead(PORT_SWITCH) == HIGH) {
    // Inform Traffic Control object about Out-Of-Order Mode
    oTrCntl.SetOpMode(0);
  }
  else {
    // Inform Traffic Control object about Normal Mode
    oTrCntl.SetOpMode(1);
  }
  
  // Process State Machine
  oTrCntl.Process();
  
  // Wait 100 ms
  delay(100);
}
