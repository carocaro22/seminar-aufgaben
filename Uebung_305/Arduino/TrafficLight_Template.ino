// ----------------------------------------------------------------------------------------
//   Implementation of a State Machine for a traffic light system
//   TrafficLight.ino                                            
//                                                               
//   Hochschule Mittweida, INW                                     
//   Prof. J. Thomanek                                             
//                               
// ----------------------------------------------------------------------------------------                                

// ----------------------------------------------------------------------------------------
//   C O N S T A N T S    D E F I N I T I O N S
// ----------------------------------------------------------------------------------------

//   Light States Mask
// ----------------------------------------------------------------------------------------
#define LIGHTSTATE_RED_MSK    0x01
#define LIGHTSTATE_YELLOW_MSK 0x02
#define LIGHTSTATE_GREEN_MSK  0x04

#define LIGHTSTATE_STOP_MSK   0x01
#define LIGHTSTATE_GO_MSK     0x02


//  Light States 
// ---------------------------------------------------------------------------------------
// Traffic light
#define TL_STATE_OFF          0x00
#define TL_STATE_RED          LIGHTSTATE_RED_MSK
#define TL_STATE_RED_YELLOW   (LIGHTSTATE_RED_MSK | LIGHTSTATE_YELLOW_MSK)
#define TL_STATE_YELLOW       LIGHTSTATE_YELLOW_MSK
#define TL_STATE_GREEN        LIGHTSTATE_GREEN_MSK

// Pedestrian light
#define PL_STATE_OFF          0x00
#define PL_STATE_WAIT         LIGHTSTATE_STOP_MSK
#define PL_STATE_WALK         LIGHTSTATE_GO_MSK


//  Times in 100 ms
// ---------------------------------------------------------------------------------------
#define TIME_OP_OFF_YELLOW       5  // 0.5s - time of flashing yellow (out of order)

#define TIME_OP_ON_RDY_TO_DRV   10  //   1s - time of red/yellow 
#define TIME_OP_ON_RDY_TO_STP   10  //   1s - time of yellow
#define TIME_OP_ON_GO_MIN      100  //  10s - minimum time of green

#define TIME_OP_ON_PEDEST_SAFE  15  // 1.5s - safety time between red and walk
#define TIME_OP_ON_PEDEST_WALK  50 //  5s   - time of pedestrian walking


//  State machine states 
// ---------------------------------------------------------------------------------------- 

// #define ....


//  Port definitions
// ---------------------------------------------------------------------------------------- 
// traffic light
#define PORT_LED_RED      10
#define PORT_LED_YELLOW    9
#define PORT_LED_GREEN     8

// pedestrian light
#define PORT_LED_WAIT     12
#define PORT_LED_WALK     11

// button for pedestrian
#define PORT_BUTTON        2

// operator switch 
#define PORT_SWITCH        1



// ----------------------------------------------------------------------------------------
//   V A R I A B L E S    D E F I N I T I O N S
// ----------------------------------------------------------------------------------------

// Current state of state machine
// timer counter variable
// Button pressed flag
// ....



// ----------------------------------------------------------------------------------------
//   F U N C T I O N S    D E F I N I T I O N S
// ----------------------------------------------------------------------------------------

//  Interrupt Service Routine for Button
// ---------------------------------------------------------------------------------------- 
void MyISR() {
  
}


//  Function to control traffic light
// ---------------------------------------------------------------------------------------- 
void SetTrafficLight(byte u8Mode) {

}


//  Function to control pedestrian light
// ---------------------------------------------------------------------------------------- 
void SetPedestrLight(byte u8Mode) {

}

//  State Machine Function
// ---------------------------------------------------------------------------------------- 
void SM_process() {

  
}


// ----------------------------------------------------------------------------------------
//   A R D U I N O  F U N C T I O N S    D E F I N I T I O N S
// ----------------------------------------------------------------------------------------

//   Initialization function
// ----------------------------------------------------------------------------------------
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

}

//   Cyclic function
// ----------------------------------------------------------------------------------------
void loop() {
  // Process State Machine
  SM_process();
  
  // Wait 100 ms
  delay(100);
}
