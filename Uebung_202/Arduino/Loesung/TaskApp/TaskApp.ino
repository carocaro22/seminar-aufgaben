/******************************************************************************
 * Demonstrator of a simple non-preemptive scheduler                          *
 * TaskApp.ino                                                                *
 *                                                                            *
 * Module: "Embedded Systems 2" - Uebung 2-2                                  *
 *                                                                            *
 * Hochschule Mittweida, INW                                                  *
 * Prof. J. Thomanek                                                          *
 *                                                                            *
 ******************************************************************************/

/******************************************************************************
 *    I N C L U D E S                                                         *
 ******************************************************************************/
#include "sched.h"


/******************************************************************************
 *    C O N S T A N T S                                                       *
 ******************************************************************************/
#define PORT_LED_RED     12
#define PORT_LED_YELLOW  10 
#define PORT_LED_GREEN   8


/******************************************************************************
 *    T A S K  D E F I N I T I O N S                                          *
 ******************************************************************************/

// ---> TODO: Definieren Sie hier Ihre Task-Funktionen <--- 

// Cyclic Task 1 - cycle time 100 ms 
// ---------------------------------------------------------
void My100msTask() {
  static bool mode = false;

  // Toogle mode
  mode = !mode;
  
  if (mode == true) 
    digitalWrite(PORT_LED_RED, HIGH);
  else
    digitalWrite(PORT_LED_RED, LOW);
}

// Cyclic Task 2 - cycle time 500 ms 
// ---------------------------------------------------------
void My500msTask() {
  static bool mode = false;
  
  // Toogle mode
  mode = !mode;
  
  if (mode == true) 
    digitalWrite(PORT_LED_YELLOW, HIGH);
  else
    digitalWrite(PORT_LED_YELLOW, LOW);
}

// Cyclic Task 3 - cycle time 1000 ms 
// ---------------------------------------------------------
void My1000msTask() {
  static bool mode = false;

  // Toogle mode
  mode = !mode;
  
  if (mode == true) 
    digitalWrite(PORT_LED_GREEN, HIGH);
  else
    digitalWrite(PORT_LED_GREEN, LOW);
}


/******************************************************************************
 *    I N I T I A L I Z A T I O N  F U N C T I O N                            *
 ******************************************************************************/
void setup() {
  // Set port as output
  pinMode(PORT_LED_YELLOW, OUTPUT);
  pinMode(PORT_LED_RED, OUTPUT);
  pinMode(PORT_LED_GREEN, OUTPUT);
    
  // Initialize the scheduler
  SchedInit();

  // Add the user tasks 
  AddTask(TASKTYPE_CYCLIC, (Task_fp)My100msTask, 100);
  AddTask(TASKTYPE_CYCLIC, (Task_fp)My500msTask, 500);
  AddTask(TASKTYPE_CYCLIC, (Task_fp)My1000msTask, 1000);
}


/******************************************************************************
 *   C Y C L I C  F U N C T I O N                                             *
 ******************************************************************************/

void loop() {
  // put your main code here, to run repeatedly
  SchedRun();
}
