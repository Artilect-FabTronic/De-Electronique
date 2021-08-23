/**
 * FabTronic 2021
 * 
 * Libraries used are the properties of the respective authors.
 * 
 */

// Source :
// - How 74HC595 Shift Register Works & Interface it with Arduino
// https://lastminuteengineers.com/74hc595-shift-register-arduino-tutorial/
// - https://www.programmingelectronics.com/serial-read/

// For splash screen on start :
const String firmwareName = "Demo-regitre-a-decalage.ino";

const int latchPin = 5;		// Latch pin of 74HC595 is connected to Digital pin 5
const int clockPin = 6;		// Clock pin of 74HC595 is connected to Digital pin 6
const int dataPin = 4;		// Data pin of 74HC595 is connected to Digital pin 4
const int outputEnablePin = 3;	// OE pin of 74HC595 is connected to PWM pin 3

byte leds = 0;		// Variable to hold the pattern of which LEDs are currently turned on or off

/*
   setup() - this function runs once when you turn your Arduino on
   We initialize the serial connection with the computer
*/
void setup()
{
  Serial.begin(9600);

  // Set all the pins of 74HC595 as OUTPUT and lower state
  pinMode(latchPin, OUTPUT);
  digitalWrite(latchPin, LOW);
  pinMode(dataPin, OUTPUT);
  digitalWrite(dataPin, LOW);
  pinMode(clockPin, OUTPUT);
  digitalWrite(clockPin, LOW);
  pinMode(outputEnablePin, OUTPUT);
  digitalWrite(outputEnablePin, LOW);
}

/*
   loop() - this function runs over and over again
*/
void loop()
{
  byte incomingByte = 0; // for incoming serial data (or inByte)

  // If anything comes in Serial (USB)
  if (Serial.available() != 0)
  {
    incomingByte =  Serial.read();
    if ( incomingByte == '?')
    {
      // Print the message (or do other things)
      Serial.println(firmwareName);
    }
  }

  setBrightness(255);
  leds = 0;		// Initially turns all the LEDs off, by giving the variable 'leds' the value 0
  updateShiftRegister();
  delay(500);

  for (int i = 0; i < 8; i++)	// Turn all the LEDs ON one by one.
  {
    bitSet(leds, i);		// Set the bit that controls that LED in the variable 'leds'
    updateShiftRegister();
    delay(500);
  }

  for (byte b = 255; b > 0; b--)	// Gradually fade all the LEDs back to off
  {
    setBrightness(b);
    delay(50);
  }
}

/*
   updateShiftRegister() - This function sets the latchPin to low,
   then calls the Arduino function 'shiftOut' to shift out contents of variable 'leds'
   in the shift register before putting the 'latchPin' high again.
*/
void updateShiftRegister()
{
  shiftOut(dataPin, clockPin, LSBFIRST, leds);
  digitalWrite(latchPin, HIGH);
  delay(1); // 1 ms latch timing
  digitalWrite(latchPin, LOW);
}

/*
   setBrightness() - Generates PWM signal and writes it to OE pin.
*/
void setBrightness(byte brightness) // 0 to 255
{
  analogWrite(outputEnablePin, 255 - brightness);
}
