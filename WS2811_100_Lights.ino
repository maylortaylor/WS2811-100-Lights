/***************************************************************************************
****************************************************************************************

Project: WS2811 100 Lights

Description: Controls a WS2811 based strand of LEDs. Accepts input from a Rotary
             Encoder (pattern select) and Potentiometer (brightness). Stores current
             pattern in to memory for recall after power loss. Based on Christmas 2016
                         design and modified for more attention grabbing patterns.

Connections:

  VCC = 5v

  WS2811:
    GND -> GND
    VCC -> VCC
    DAT -> Digital 6

  Rotary Encoder:
    D 3 <-   -> D 4
    GND <- O  |
    D 2 <-   -> GND

  Potentiometer:
    /-> GND (alternative A0)
    Q-> A1
    \-> VCC (alternative A1)

****************************************************************************************
***************************************************************************************/

/* 
*
* INCLUDE LIBRARIES
*
*/

/* Encoder Library - Basic Example
 * http://www.pjrc.com/teensy/td_libs_Encoder.html
 */
#include <Adafruit_NeoPixel.h> // Adafruit_Neopixel
#include <EEPROM.h>            // Persistent memory
#ifdef __AVR__
#include <avr/power.h>
#endif
#include <avr/pgmspace.h>

/* 
!
! !!!! >>>> LOOK HERE <<<< !!!!
!
! S E T U P
!
! !!!! >>>> LOOK HERE <<<< !!!!
!
*/
#define PWM_MaxPixels 108 // number of lights being used
#define PIN 6
#define INVERTED 1

/* 
*
* GENERAL VARIABLES
*
*/
byte currDirection = 0;
byte lastSavedEncoderPosition = 0;
int currBrightness, brightnessRead, counter, ledPosition, encoderButton = 0;
int upperLimit = 18;        // max number of patterns (encoder)
int lowerLimit = 1;         // minimum number of patterns (encoder)
int fadeDirection = 0;      // 1 or 0, positive or negative
int fadeDirection2 = 0;     // 1 or 0, positive or negative
int fadeDirectionHTemp = 0; // 1 or 0, positive or negative
int maxPixels = PWM_MaxPixels;
bool randomMode = false;

/* 
*
* ADAFRUIT_NEOPIXLE SETUP
*
*/
// Parameter 1 = number of pixels in strip
// Parameter 2 = Arduino pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
//   NEO_RGBW    Pixels are wired for RGBW bitstream (NeoPixel RGBW products)
Adafruit_NeoPixel strip = Adafruit_NeoPixel(maxPixels, PIN, NEO_RGB + NEO_KHZ800);

/* 
*
* ENCODER VARIABLES
*
*/
static int pinA = 2; // Our first hardware interrupt pin is digital pin 2

static int pinB = 3; // Our second hardware interrupt pin is digital pin 3

volatile byte aFlag = 0; // let's us know when we're expecting a rising edge on pinA to signal that
                         // the encoder has arrived at a detent

volatile byte bFlag = 0; // let's us know when we're expecting a rising edge on pinB to signal that
                         // the encoder has arrived at a detent (opposite direction to when aFlag is
                         // set)

volatile byte encoderPos = 1; // this variable stores our current value of encoder position. Change
                              // to int or uin16_t instead of byte if you want to record a larger
                              // range than 0-255

volatile byte oldEncPos = 0; // stores the last encoder position value so we can compare to the
                             // current reading and see if it has changed (so we know when to print
                             // to the serial monitor)

volatile byte reading = 0; // somewhere to store the direct values we read from our interrupt pins
                           // before checking to see if we have moved a whole detent

/* 
*
* SIMPLEX NOIES VARIABLE DELCARATION
*
*/
// Define simplex noise node for each LED
const int LEDs_in_strip = PWM_MaxPixels;
const int LEDs_for_simplex = 5;

// Extra fake LED at the end, to avoid fencepost problem.
// It is used by simplex node and interpolation code.
float LED_array_red[LEDs_in_strip / 2 + 1];
float LED_array_green[LEDs_in_strip / 2 + 1];
float LED_array_blue[LEDs_in_strip / 2 + 1];
int node_spacing = LEDs_in_strip / LEDs_for_simplex;

// Math variables
int i, j, k, A[] = {0, 0, 0};
float x1, y1, x2, y2;
float u, v, w, s, h;
static float onethird = 0.333333333;
static float onesixth = 0.166666667;
int T[] = {0x15, 0x38, 0x32, 0x2c, 0x0d, 0x13, 0x07, 0x2a};

// Simplex noise parameters:
float timeinc = 0.0025;
float spaceinc = 0.05;
int intensity_r = 734, intensity_g = 734, intensity_b = 734;
float yoffsetMAX = 15000;
float saturation = 1.0;
float yoffset, xoffset, hTemp, hTemp3;
long tempTimer, randomTimer;
int red, green, blue;
int red2, green2, blue2; // used in HSV color functions
int red3, green3, blue3; // used in HSV color functions

/* 
*
* SETUP
*
*/
void setup()
{
  /***************************************************************************************
      General Arduino Setup
    ***************************************************************************************/
  Serial.begin(115200); // start the serial monitor link

  // encoder button
  pinMode(4, INPUT);
  digitalWrite(4, HIGH);
  // for lazy GRND problem solving
  pinMode(5, OUTPUT);
  digitalWrite(5, LOW);
  // encoder 1
  pinMode(A0, OUTPUT);   // set Analog_0 to OUTPUT
  digitalWrite(A0, LOW); // set Analog_0 to LOW
  // encoder 2
  pinMode(A2, OUTPUT);    // set Analog_1 to OUTPUT
  digitalWrite(A2, HIGH); // set Analog_1 to HIGH
  // brightness
  pinMode(A1, INPUT); // set Analog_2 to INPUT

  /* 
  *
  * ENCODER SETUP
  *
  */
  pinMode(pinA, INPUT_PULLUP); // set pinA as an input, pulled HIGH to the logic voltage (5V or
                               // 3.3V for most cases)

  pinMode(pinB, INPUT_PULLUP); // set pinB as an input, pulled HIGH to the logic voltage (5V or
                               // 3.3V for most cases)

  attachInterrupt(0, PinA, RISING); // set an interrupt on PinA, looking for a rising edge signal
                                    // and executing the "PinA" Interrupt Service Routine (below)

  attachInterrupt(1, PinB, RISING); // set an interrupt on PinB, looking for a rising edge signal
                                    // and executing the "PinB" Interrupt Service Routine (below)

  // Start up the LED strip
  strip.begin();
  // Update the strip, to start they are all 'off'
  strip.show();

  // read last pattern setting from EEPROM
  // lastSavedEncoderPosition = EEPROM.read(128);
  //encoderPos = lastSavedEncoderPosition;
  encoderPos = 1;
}

/* 
*
* MAIN LOOP
*
*/
void loop()
{
  // * Read Potentiometer & Encoder
  GetBrightness();

  // * Get encoder button value
  GetEncoderButtonValue();

  // * keep encoder knob within upper && lower limits
  CheckEncoderKnobLimits();

  // ? currBrightness knob reads 0-1024,
  // ? divide by 4 to get a number between 0-255
  // * REDUCE MAX BRIGHTNESS, BATTERY SAVER, HIPPIE EYE SAVER
  currBrightness = currBrightness / 4;

  // * determine fade direction
  DetermineFadeDirection();

  // * if random mode is on && has been some random amount of time
  if ((randomMode == 1) && (millis() > randomTimer))
  {
    // * set random encoderPos every minute or so
    randomTimer = millis() + random(60000);
    encoderPos = random(upperLimit);
  }

  // ? uncomment to show test/debug code
  TestCode();

  // * call color main function
  // ? large switch-case statement determined by encoderPos
  CallColorFunction();

  // * increment counter
  counter++;
  // * if counter is greater than 10, reset counter to 0
  if (counter > 10)
  {
    counter = 0;
  }

  // ? Adjuge Frame Rate
  // delay(100);

  // ? if user changes encoderPosition
  if (oldEncPos != encoderPos)
  {
    //StorePattern();
    // randomMode = 0; // turn off Random Mode when encoder is turned
  }
}

void CallColorFunction()
{
  switch (encoderPos)
  {
  case 0:
    // ! random!
    //            encoderPos = random(upperLimit);
    //            CallColorFunction();
    break;
  case 1:
    MovingTrail(.005, 100, 1.3, true);
    break;
  case 2:
    RainbowHsv(.000009); // ? ~25 minutes for full cycle
    break;
  case 3:
    LargeGroupColorFlowBounce(12, .00007, .3, .82, .35);
    break;
  case 4:
    RainbowFlow(.00025, .01);
    break;
  case 5:
    DualColorFlow(.00009, .5);
    break;
  case 6:
    LargeGroupColorFlowBounce(12, .00007, 1.5, .45, .05);
    break;
  case 7:
    MovingTrailWithPurpleTail(.05, 300, 8);
    break;
  case 8:
    RainbowFlow(.00007, .002);
    break;
  case 9:
    RainbowFlow(.00025, .1);
    break;
  case 10:
    LargeGroupColorFlowBounce(12, .00008, .1, .42, .05);
    break;
  case 11:
    MovingTrailWithTail(.05, 200, 8);
    break;
  case 12:
    LargeGroupColorFlowBounce(12, .00008, .1, .92, .65);
    break;
  case 13:
    DualColorFlowBounce(2, .00009, .1, .85, .58);
    break;
  case 14:
    DualColorFlowBounce(2, .00009, .1, .17, .02);
    break;
  case 15:
    DualColorFlow(.00005, .1);
    break;
  case 16:
    LargeGroupRedGreen(12);
    break;
  case 17:
    MovingTrailWithBlueTail(.05, 300, 8);
    break;
  case 18:
    LargeGroupBlueWhite(12);
    break;
  }
}
