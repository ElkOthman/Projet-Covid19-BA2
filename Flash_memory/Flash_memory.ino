#include <Arduino.h> 
#define uS_TO_S_FACTOR 1000000  /* Conversion factor for micro seconds to seconds */

//#define TIME_TO_SLEEP  4 
/************************************/
#include <EEPROM.h>
#define EEPROM_SIZE 3


int state = 1;

void setup() {
  // put your setup code here, to run once:
//delay(5000);
Serial.begin(115200);
EEPROM.begin(EEPROM_SIZE);
//state = 253;
//EEPROM.write(1,state);



//EEPROM.commit();
//Serial.println(state);


}


void loop() {
  // put your main code here, to run repeatedly:
//state = 2;
//EEPROM.write(1,state);
//EEPROM.commit();//state = EEPROM.read(1);
state = EEPROM.read(1);
Serial.println(state);


delay(2000);

int TIME_TO_SLEEP = 4;
esp_sleep_enable_timer_wakeup(TIME_TO_SLEEP * uS_TO_S_FACTOR);

Serial.println("Setup ESP32 to sleep for every " + String(TIME_TO_SLEEP) + " Seconds");


Serial.println("Going to sleep now");

delay(1000);

Serial.flush(); 

esp_deep_sleep_start();  /*sommeil profond ou esp_light_sleep_start(); (sommeil léger) */

Serial.println("This message will never be printed");

}
