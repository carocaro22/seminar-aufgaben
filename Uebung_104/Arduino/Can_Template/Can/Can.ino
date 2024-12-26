// ------------------------------------------------------------------------------
// 
// Modul "Steuergeraete/Software/Vernetzung - Embedded Systems II"
// Uebung 1-04: Uebermitteln von CAN-Daten
//
// Prof. J. Thomanek, Hochschule Mittweida
//
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
//  I N C L U D E S 
// -----------------------------------------------------------------------------
#include "mcp2515.h"

// -----------------------------------------------------------------------------
//  C O N S T A N T S  D E F I N I T I O N S
// -----------------------------------------------------------------------------
// Analog input pin
#define TEMPSENS_PIN A5
#define MCP2515_CS   10

// Kelvin offset
const float Kelvin_offset = 273.15;

// B value
const float B_val = 0.0; // <-- To do

// .. to do


// -----------------------------------------------------------------------------
//  G L O B A L  V A R I A B L E S
// -----------------------------------------------------------------------------
// CAN messages (Type: can_frame) that contains the temperature
// .. to do

// Create an object of the MCP2515 driver - set CS (chip select) pin number
// .. to do

// -----------------------------------------------------------------------------
//  I N I T I A L I Z A T I O N  F U N C T I O N
// -----------------------------------------------------------------------------
void setup() {
  // Initialize Analog pin as input
  // ---------------------------------------------------------------------------
  // .. to do 
    
  // Initialize UART driver (Serial) for debug and to display the temperature
  // ---------------------------------------------------------------------------
  Serial.begin(9600);

  // Initialize CAN message
  // ---------------------------------------------------------------------------
  // 1.) Set CAN Identifier - Use Test place number + 100 hex
  // 2.) Set CAN data payload length
  // 3.) Initialize payload by zeros
  
  // .. to do
  

  // Initialize the MCP2515 CAN driver
  // ---------------------------------------------------------------------------
  // 1.) Reset the MCP2515
  // 2.) Set Bitrate to 500 kBit/s and 8 MHz oscillator
  // 3.) Set CAN Controller into normal mode
  // Notice: 
  //   Check the result of each function call. In cas of any error (!= ERROR_OK)
  //   output the error code via the serial console and prevent the execution of 
  //   the following code (while(1);).
  
  // .. to do
   
  // If this line of code is reached, everything seems to be fine.
  Serial.println("MCP2515 initialization ok");
}


// -----------------------------------------------------------------------------
//  C Y C L I C   F U N C T I O N
// -----------------------------------------------------------------------------
void loop() {

  // Get temperature value
  // ---------------------------------------------------------------------------
  // 1.) Get analog input value on Pin A5 and calculate the measured voltage
  // 2.) Calculate resistance of the thermistor
  // 3.) Calculate temperature and display it on serial console

  // .. to do
  


  // Copy temperature into CAN message and send it
  // ---------------------------------------------------------------------------
  // Use IEEE float format (4 Bytes) (Little Endian)

  // .. to do


  // Wait a second
  // ---------------------------------------------------------------------------
  // .. to do
}
