/******************************************************************************
 * Demonstrator of FreeRTOS@Arduino                                           *
 * FreeRTOSApp.ino                                                            *
 *                                                                            *
 * Module: "Embedded Systems 2" - Uebung 2-3                                  *
 *                                                                            *
 * Hochschule Mittweida, INW                                                  *
 * Prof. J. Thomanek                                                          *
 *                                                                            *
 ******************************************************************************/

/******************************************************************************
 *    I N C L U D E S                                                         *
 ******************************************************************************/
#include <Arduino_FreeRTOS.h>
#include <avr/io.h>
#include <queue.h>

/******************************************************************************
 *    C O N S T A N T S                                                       *
 ******************************************************************************/
#define PORT_BUTTON 2


/******************************************************************************
 *    G L O B A L  D A T A                                                    *
 ******************************************************************************/
// Button pressed flag
bool bSigRequest;

// Queue handle
QueueHandle_t hQueue;


/******************************************************************************
 *    I N T E R R U P T   S E R V I C E   R O U T I N E                       *
 ******************************************************************************/
void MyISR() {
  bSigRequest = true;
}

/******************************************************************************
 *    T A S K  D E F I N I T I O N S                                          *
 ******************************************************************************/

// Task L1 - Control LED 1 
// ---------------------------------------------------------
void Task_L1(void *pvParameters)  {
  // ---> To Do <---
}

// Task L2 - Control LED 2 
// ---------------------------------------------------------
void Task_L2(void *pvParameters)  {
   // ---> To Do <---
}

// Task L3 - Control LED 3 
// ---------------------------------------------------------
void Task_L3(void *pvParameters)  {
  // ---> To Do <---
}

// Task Bt - Check Button 
// ---------------------------------------------------------
void Task_Bt(void *pvParameters)  {
  // ---> To Do <---
}



/******************************************************************************
 *    M A I N  F U N C T I O N                                                *
 ******************************************************************************/
int main(void)
{
   bSigRequest = false;

   // Enable Interrupt for the Button port
   attachInterrupt(digitalPinToInterrupt(PORT_BUTTON), MyISR, RISING); 

   // Create a queue
   // ---> To Do <---
     
   // Create Tasks
   // ---> To Do <---
       
   // Start Scheduler
   // ---> To Do <---
}

// application idle task hook
void loop(){}
