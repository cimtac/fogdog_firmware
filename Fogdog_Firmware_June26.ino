/*----------------------------------------------------------------------------------------
  Project: Fogdog Shaving Mirror
  Description: This code controls the lights and heaters of the shaving mirror.
  Version: V0.1
  Author: Illya Omelyanchuk
  Date: July 14 2023

  Hardware Configuration:
  - North LED: LED_N_PIN (Pin 9)
  - East LED: LED_E_PIN (Pin 8)
  - South LED: LED_S_PIN (Pin 7)
  - West LED: LED_W_PIN (Pin 6)
  - Heater: HEATER (Pin 5)
----------------------------------------------------------------------------------------*/

// Pin definitions
#define LED_N_PIN 9  // North LED pin
#define LED_E_PIN 8  // East LED pin
#define LED_S_PIN 7  // South LED pin
#define LED_W_PIN 6  // West LED pin
#define HEATER 5     // Heater pin

int shutoffTime = 30;  // Time in seconds for the heater to shut off

/*----------------------------------------------------------------------------------------
  Function: heatOn

  Description:
  Turns on the heater and prints a status message.

  Parameters:
  None

  Returns:
  None
----------------------------------------------------------------------------------------*/
void heatOn() {
  digitalWrite(HEATER, HIGH);            // Turn on the heater, this could be PWM for temperature control
  Serial.println("[STATUS] Heater on");  // Print status message
}

/*----------------------------------------------------------------------------------------
  Function: heatOff

  Description:
  Turns off the heater and prints a status message.

  Parameters:
  None

  Returns:
  None
----------------------------------------------------------------------------------------*/
void heatOff() {
  digitalWrite(HEATER, LOW);              // Turn off the heater
  Serial.println("[STATUS] Heater off");  // Print status message
}

/*----------------------------------------------------------------------------------------
  Function: lightOn

  Description:
  Turns on all the lights (North, East, South, and West) and prints a status message.

  Parameters:
  None

  Returns:
  None
----------------------------------------------------------------------------------------*/
void lightOn() {
  digitalWrite(LED_N_PIN, HIGH);         // Turn on North LED
  digitalWrite(LED_E_PIN, HIGH);         // Turn on East LED
  digitalWrite(LED_S_PIN, HIGH);         // Turn on South LED
  digitalWrite(LED_W_PIN, HIGH);         // Turn on West LED
  Serial.println("[STATUS] Lights on");  // Print status message
}

/*----------------------------------------------------------------------------------------
  Function: lightOff

  Description:
  Turns off all the lights (North, East, South, and West) and prints a status message.

  Parameters:
  None

  Returns:
  None
----------------------------------------------------------------------------------------*/
void lightOff() {
  digitalWrite(LED_N_PIN, LOW);           // Turn off North LED
  digitalWrite(LED_E_PIN, LOW);           // Turn off East LED
  digitalWrite(LED_S_PIN, LOW);           // Turn off South LED
  digitalWrite(LED_W_PIN, LOW);           // Turn off West LED
  Serial.println("[STATUS] Lights off");  // Print status message
}

/*----------------------------------------------------------------------------------------
  Function: setup

  Description:
  Initializes the shaving mirror by setting pin modes, initializing serial communication,
  printing an initialization message, and turning on the lights and heater.

  Parameters:
  None

  Returns:
  None
----------------------------------------------------------------------------------------*/
void setup() {
  // Set pin modes
  pinMode(LED_N_PIN, OUTPUT);
  pinMode(LED_E_PIN, OUTPUT);
  pinMode(LED_S_PIN, OUTPUT);
  pinMode(LED_W_PIN, OUTPUT);
  pinMode(HEATER, OUTPUT);

  // Set everything to be off initially
  digitalWrite(LED_N_PIN, LOW);
  digitalWrite(LED_E_PIN, LOW);
  digitalWrite(LED_S_PIN, LOW);
  digitalWrite(LED_W_PIN, LOW);
  digitalWrite(HEATER, LOW);

  //Serial.begin(9600);  // Initialize serial communication

  //Serial.println("[STATUS] Initialized");  // Print initialization message

  lightOn();  // Turn on the lights
  heatOn();   // Turn on the heater
}

/*----------------------------------------------------------------------------------------
  Function: loop

  Description:
  The main loop of the shaving mirror. Checks if it's time to shut off the heater
  based on the shutoffTime value. If the time has elapsed, the heater is turned off.

  Parameters:
  None

  Returns:
  None
----------------------------------------------------------------------------------------*/
void loop() {
  // Check if it's time to shut off the heater
  if (millis() > (shutoffTime * 1000)) {
    heatOff();  // Turn off the heater
  }
}
