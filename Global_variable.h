#include <sys/types.h>

// No. of text count to get min values from sensor
#define test_count 4

// Threshold values for ADC testcount
#define Sense_MAX 3500 

// Max mapping threshold 
#define MAX_MAPPED 100


#define THRESHOLD 40
#define MAX_VOLUME 20
// Pin 33 for Wake-Up
#define BUTTON_PIN_BITMASK 0x200000000  // 2^33 in hex

// Global variable to store min values to initialize sensors
int MIN_1 = 0;
int MIN_2 = 0;
int MIN_3 = 0;

// Global variable to check whether to get min values or to get values for commands check
uint8_t flag_for_min_max = 0;

// TO store values of sensor to check the commands
int value_1, value_2, value_3;

// Track number going to play
int track_number = 1;

// LED State
int s = 0;

// To Check whether the esp should have to go to sleep mode or not
uint8_t null_condition_check = 0;

// Create an array to store messages and initialize globally
String messages[] = {
  "",
  "Gloves Initialised",
  "Plese Give Correct Command",
  "Medicine Required",
  "Thanks For Food",
  "Thanks For Water",
  "Water Request",
  "Food Request",
  "I need Help",
  "Keep your finger straight to initialised Hand Gloves",
};