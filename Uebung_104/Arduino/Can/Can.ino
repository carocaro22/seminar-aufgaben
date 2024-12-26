// ------------------------------------------------------------------------------
// 
// Modul "Steuergeraete/Software/Vernetzung - Embedded Systems II"
// Uebung 1-04: CAN-Nachricht versenden
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

// Voltage supply
const float U_max = 5.0;

// Max value of the ADC
const int   Inp_max = 1023;

// Series resistor 10k
const float R_vor = 10000.0;

// B value
const float B_val = 3435;

// resistor value of the thermistor on 25 °C
const float R_therm25  = 10000.0;

// Temperature in Kelvin of the thermistor
const float T_therm25 = 25 + Kelvin_offset;

// -----------------------------------------------------------------------------
//  G L O B A L  V A R I A B L E S
// -----------------------------------------------------------------------------
// CAN messages that contains the temperature
can_frame canMsg;
can_frame canMsg2;
// Create an object of the MCP2515 driver - set CS (chip select) pin number
MCP2515 mcp2515(MCP2515_CS);

// -----------------------------------------------------------------------------
//  I N I T I A L I Z A T I O N  F U N C T I O N
// -----------------------------------------------------------------------------
void setup() {
  // Initialize Analog pin as input
  // ---------------------------------------------------------------------------
  pinMode(TEMPSENS_PIN, INPUT); 
    
  // Initialize UART driver (Serial) for debug and to display the temperature
  // ---------------------------------------------------------------------------
  Serial.begin(9600);

  // Initialize CAN message
  // ---------------------------------------------------------------------------
  // CAN Identifier - Use Test place number + 100 hex
  canMsg.can_id  = 0x106;
  
  // CAN data length
  canMsg.can_dlc = 4;
  
  // Initialize payload by zeros
  canMsg.data[0] = 0x00;
  canMsg.data[1] = 0x00;
  canMsg.data[2] = 0x00;
  canMsg.data[3] = 0x00;
  

  // Initialize the MCP2515 CAN driver
  // ---------------------------------------------------------------------------
  // Reset the MCP2515
  MCP2515::ERROR err = mcp2515.reset();

  // Check for SUCCESS
  if (err != MCP2515::ERROR_OK) {
    // Printout error code
    Serial.print("Initialization Error: ");
    Serial.println(err);
    while (1);
  }
  // Set Bitrate to 500 kBit/s and 8 MHz oscillator
  err = mcp2515.setBitrate(CAN_500KBPS, MCP_8MHZ);
  
  // Check for SUCCESS
  if (err != MCP2515::ERROR_OK) {
    // Printout error code
    Serial.print("Bitrate could not be set: ");
    Serial.println(err);
    while (1);
  }

  // Set CAN Controller into normal mode
  err = mcp2515.setNormalMode();

  // Check for SUCCESS
  if (err != MCP2515::ERROR_OK) {
    // Printout error code
    Serial.print("Normal mode coud not be activated: ");
    Serial.println(err);
    while (1);
  }
   
  // It seems everything okay 
  Serial.println("MCP2515 initialization ok");
}


// -----------------------------------------------------------------------------
//  C Y C L I C   F U N C T I O N
// -----------------------------------------------------------------------------
void loop() {

  // Get temperature value
  // ---------------------------------------------------------------------------

  // 1.) Get analog input value on Pin A5
  int input = analogRead(TEMPSENS_PIN);

  // 2.) Calculate measured voltage
  float U_inp = input * (U_max/Inp_max);

  // 3.) Calculate resistance based on voltage devider rule 
  float R = R_vor / (U_max/U_inp - 1);

  // 4.) Calculate temperature
  float T = 1/((1/B_val) * log(R/R_therm25) + (1/T_therm25)) - Kelvin_offset;
  
  // 5.) Display temperature on serial console
  Serial.println(T);

  // Copy temperature into CAN message and send it
  // ---------------------------------------------------------------------------
  // Use IEEE float format (4 Bytes)
  canMsg.data[0] = ((byte*)&T)[0];
  canMsg.data[1] = ((byte*)&T)[1];
  canMsg.data[2] = ((byte*)&T)[2];
  canMsg.data[3] = ((byte*)&T)[3];

  // Send message
  mcp2515.sendMessage(&canMsg);
 
  // Wait a second
  // ---------------------------------------------------------------------------
  delay(1000);
}
