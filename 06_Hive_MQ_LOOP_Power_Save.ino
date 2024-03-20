#include "Library.h"
RTC_DATA_ATTR int value = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  esp_sleep_enable_ext0_wakeup(GPIO_NUM_33, 1);  //1 = High, 0 = Low

  delay(1000);
  DEBUG_LN("Wake Up Successful...");
  DEBUG_LN("Serial Monitor Begin");
  esp_sleep_wakeup_cause_t wakeup_reason = esp_sleep_get_wakeup_cause();
  DEBUG_NNL("Wake-up reason: ");
  DEBUG_LN(wakeup_reason);
  pinMode(LED, OUTPUT);


  toggle_led();
  delay(500);
  toggle_led();


  softwareSerial.begin(9600);
  if (!player.begin(softwareSerial, /*isACK = */ false, /*doReset = */ false)) {  //Use serial to communicate with mp3.
    DEBUG_LN(F("Unable to begin:"));
    DEBUG_LN(F("1.Please recheck the connection!"));
    DEBUG_LN(F("2.Please insert the SD card!"));
    while (true) {
      delay(0);
    }
  }

  player.volume(30);
  delay(100);

  OLED_init();
  OLED_commands_out();
  display.setCursor(0, 0);
  display.println(F("Smart Gloves Wake Up"));
  display.display();
  delay(2000);
  player.play(KEEP_FS);
  init_smart_gloves();
  display.setCursor(0, 16);
}
void loop() {

  if (null_condition_check > 1) {
    display.setCursor(0, 56);
    display.println(F("Going to Sleep Mode"));
    display.display();
    DEBUG_LN("Going to Sleep Mode");
    delay(3000);
    display.clearDisplay();
    display.display();
    delay(1000);
    esp_deep_sleep_start();
  }
  display.println(F("Ready to Give Commands"));
  display.display();
  player.play(INIT_TRACK);
  get_values_for_motion();
  check_conditions_for_motions();
  delay(3000);
}
