#include <Arduino.h> 
#define uS_TO_S_FACTOR 1000000  /* Conversion factor for micro seconds to seconds */

#define TIME_TO_SLEEP  30       /* Time ESP32 will go to sleep (in seconds) */
 
void setup() {
  // put your setup code here, to run once:





  Serial.begin(115200);
 

  esp_sleep_enable_timer_wakeup(TIME_TO_SLEEP * uS_TO_S_FACTOR);

  Serial.println("Setup ESP32 to sleep for every " + String(TIME_TO_SLEEP) + " Seconds");
 

  Serial.println("Going to sleep now");

  delay(1000);

  Serial.flush(); 

  esp_deep_sleep_start();  /*sommeil profond ou esp_light_sleep_start(); (sommeil léger) */

  Serial.println("This message will never be printed");

}

void loop() {
  // put your main code here, to run repeatedly:

}
