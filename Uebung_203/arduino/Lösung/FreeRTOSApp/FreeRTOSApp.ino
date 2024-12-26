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
  
  uint16_t time_ms = 100;
    
  // Set as Output
  DDRB |= 0x01; 

  // Swtich off
  PORTB &= ~0x01; 

  // A Task shall never return or exit
  for (;;) {

    // Read message from queue
    xQueueReceive(hQueue, &time_ms, 0);
    
    // Toggle Port Bit
    PORTB ^= 0x01;

    // Wait for some time
    vTaskDelay( time_ms / portTICK_PERIOD_MS ); 
  }
}

// Task L2 - Control LED 2 
// ---------------------------------------------------------
void Task_L2(void *pvParameters)  {
  //(void) pvParameters;

  // Set as Output
  DDRB |= 0x04; 

  // Swtich off
  PORTB &= ~0x04; 

  // A Task shall never return or exit
  for (;;) {
    // Toggle Port Bit
    PORTB ^= 0x04;
    // Wait for some time
    vTaskDelay( 500 / portTICK_PERIOD_MS ); 
  }
}

// Task L3 - Control LED 3 
// ---------------------------------------------------------
void Task_L3(void *pvParameters)  {
  (void) pvParameters;
  
  // Set as Output
  DDRB |= 0x10; 

  // Swtich off
  PORTB &= ~0x10; 

  // A Task shall never return or exit
  for (;;) {
    // Toggle Port Bit
    PORTB ^= 0x10;
    // Wait for some time
    vTaskDelay( 1000 / portTICK_PERIOD_MS ); 
  }
}

// Task Bt - Check Button 
// ---------------------------------------------------------
void Task_Bt(void *pvParameters)  {

  uint16_t data = 500;
  
  for (;;) 
  {
    if (bSigRequest == true) {
      xQueueSend(hQueue, &data, 0);
      if (data == 500) data = 100;
      else             data = 500;
      bSigRequest = false;
    }
    vTaskDelay(500 / portTICK_PERIOD_MS );
  }
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
   hQueue = xQueueCreate(5, sizeof(uint16_t));

   // Create Tasks
   xTaskCreate(Task_L1, "Led 1 Blinking", 128,  NULL, 2, NULL );
   xTaskCreate(Task_L2, "Led 2 Blinking", 128,  NULL, 2, NULL );
   xTaskCreate(Task_L3, "Led 3 Blinking", 128,  NULL, 2, NULL );
   xTaskCreate(Task_Bt, "Button control", 128,  NULL, 1, NULL );
     
   // Start Scheduler
   vTaskStartScheduler();
}

// application idle task hook
void loop(){}
