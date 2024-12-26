/******************************************************************************
 * Test of class CLed                                                         *
 * MyLed.ino                                                                  *
 *                                                                            *
 * Module: "Embedded Systems II" - Uebung 3-03                                *
 *                                                                            *
 * Hochschule Mittweida, INW                                                  *
 * Prof. J. Thomanek                                                          *
 *                                                                            *
 ******************************************************************************/

#include "CLed.h"

// Create some LED objects
// ------------------------------------------------
CLed myLed1(CLed::PB, 2, false); // Port B2 --> Arduino Pin 10
CLed myLed2(CLed::PB, 1, false); // Port B1 --> Arduino Pin 9

void setup() {
  // Switch LED 1 On
  myLed1.On();
}

void loop() {

  // Toggle LED 1 (On --> Off)  
  myLed1.Toggle();
  // Toggle LED 2 (Off --> On)
  myLed2.Toggle();
  
  // Wait 200 ms
  delay(200);
  
  // Toggle LED 2 (On --> Off)
  myLed2.Toggle();
  // Toggle LED 1 (Off --> On)
  myLed1.Toggle();
  
  // Wait 200 ms
  delay(200);
}
