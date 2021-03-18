// Mode veille
#include <Arduino.h> 
#define uS_TO_S_FACTOR 1000000  /* Conversion factor for micro seconds to seconds */

//#define TIME_TO_SLEEP  4        /* Time ESP32 will go to sleep (in seconds) */

#include <math.h>

//Access to pin33 on esp32
const int vout = 33;
//*********************************************************************************

#include <Wire.h>
#include <Adafruit_MLX90614.h>

Adafruit_MLX90614 mlx = Adafruit_MLX90614();


//********************************************************************************
/**
* Basic Write Example code for InfluxDBClient library for Arduino
* Data can be immediately seen in a InfluxDB UI: wifi_status measurement
* Enter WiFi and InfluxDB parameters below
*
* Measures signal level of the actually connected WiFi network
* This example supports only InfluxDB running from unsecure (http://...)
* For secure (https://...) or Influx Cloud 2 use SecureWrite example
**/

#if defined(ESP32)
#include <WiFiMulti.h>
WiFiMulti wifiMulti;
#define DEVICE "ESP32"
#elif defined(ESP8266)
#include <ESP8266WiFiMulti.h>
ESP8266WiFiMulti wifiMulti;
#define DEVICE "ESP8266"
#endif

#include <InfluxDbClient.h>

// WiFi AP SSID
//#define WIFI_SSID "WIFISSID"
// WiFi password
//#define WIFI_PASSWORD "WIFIPASSWORD"
// InfluxDB server url. Don't use localhost, always server name or ip address.
// E.g. http://192.168.1.48:8086 (In InfluxDB 2 UI -> Load Data -> Client Libraries),
#define INFLUXDB_URL "INFLUX_URL"
// InfluxDB v1 database name
#define INFLUXDB_DB_NAME "DB_name"
#define INFLUXDB_USER "DB_USER"
#define INFLUXDB_PASSWORD "DB_PASSWORD"

// InfluxDB client instance for InfluxDB 1
InfluxDBClient client(INFLUXDB_URL, INFLUXDB_DB_NAME);

// Data point
Point sensor("Experience 2");

int count = 1;
String patientID_ = "887755";
String patientAge = "20";
//********************************************************************************
#include <IotWebConf.h>


const char thingName[] = "testThing";
const char wifiInitialApPassword[] = "smrtTHNG8266";

String m = R"=====(

<!DOCTYPE html>
<html>
<body>
<h2>HTML Forms</h2>
<form action="/test">
<label for="fname">First name:</label><br>
<input type="text"name="fname"><br><br>

<label for="PatientID">PatientID:</label><br>
<input type="text"name="PatientID"><br><br>

<input type="submit" value="Submit">


</form>
</body>
</html>

)=====";

// -- Method declarations.
void handleRoot();
void handleTest();

DNSServer dnsServer;
WebServer server(80);
IotWebConf iotWebConf(thingName, &dnsServer, &server, wifiInitialApPassword);


void setup()
{
Serial.begin(115200);

pinMode(23, OUTPUT); //*****************************
pinMode(19, INPUT_PULLUP); //*****************************

mlx.begin(); //*****************************

Serial.println();
Serial.println("Starting up...");


iotWebConf.init();

// -- Set up required URL handlers on the web server.
server.on("/", handleRoot);
server.on("/test", handleTest);
server.on("/config", []{ iotWebConf.handleConfig(); });
server.onNotFound([](){ iotWebConf.handleNotFound(); });

Serial.println("Ready.");

}



void loop()
{
if (WiFi.RSSI()==0) {
// -- doLoop should be called as frequently as possible.
iotWebConf.doLoop();
}

if (WiFi.RSSI()!=0 && count==1) {

Serial.println();
delay(3000);
// Set InfluxDB 1 authentication params
client.setConnectionParamsV1(INFLUXDB_URL, INFLUXDB_DB_NAME, INFLUXDB_USER, INFLUXDB_PASSWORD);

// Add constant tags - only once
//sensor.addTag("device", DEVICE);
//sensor.addTag("SSID", WiFi.SSID());
sensor.addTag("PatientID",patientID_);
sensor.addTag("Age", patientAge);

  

// Check server connection
if (client.validateConnection()) {
Serial.print("Connected to InfluxDB: ");
Serial.println(client.getServerUrl());
} else {
Serial.print("InfluxDB connection failed: ");
Serial.println(client.getLastErrorMessage());
}
count = 2;
}


if (WiFi.RSSI()!=0 && count==2) {

// Store measured value into point
sensor.clearFields();
// Report RSSI of currently connected network
// sensor.addField("Rssi",WiFi.RSSI());
sensor.addField("Temperature",mlx.readObjectTempC());
sensor.addField("Niveau_de_batterie", (3.3/4095)*analogRead(vout)*13/10 );
sensor.addField("Temperature_ambiante", mlx.readAmbientTempC());
// Print what are we exactly writing
Serial.print("Writing: ");
Serial.println(client.pointToLineProtocol(sensor));
// If no Wifi signal, try to reconnect it
if ((WiFi.RSSI() == 0) && (wifiMulti.run() != WL_CONNECTED))
Serial.println("Wifi connection lost");
// Write point
if (!client.writePoint(sensor)) {
Serial.print("InfluxDB write failed: ");
Serial.println(client.getLastErrorMessage());
}

delay(2000);

if (mlx.readObjectTempC() < 30 ){
    int TIME_TO_SLEEP = 300;
    esp_sleep_enable_timer_wakeup(TIME_TO_SLEEP * uS_TO_S_FACTOR);

    Serial.println("Setup ESP32 to sleep for every " + String(TIME_TO_SLEEP) + " Seconds");
 

    Serial.println("Going to sleep now");

    delay(1000);

    Serial.flush(); 

    esp_deep_sleep_start();  /*sommeil profond ou esp_light_sleep_start(); (sommeil léger) */

    Serial.println("This message will never be printed");
    
    }
if (mlx.readObjectTempC() > 30 ){
    int TIME_TO_SLEEP = 240;
    esp_sleep_enable_timer_wakeup(TIME_TO_SLEEP * uS_TO_S_FACTOR);

    Serial.println("Setup ESP32 to sleep for every " + String(TIME_TO_SLEEP) + " Seconds");
 

    Serial.println("Going to sleep now");

    delay(1000);

    Serial.flush(); 

    esp_deep_sleep_start();  /*sommeil profond ou esp_light_sleep_start(); (sommeil léger) */

    Serial.println("This message will never be printed");
    
    }
}



}


void handleRoot()
{
// -- Let IotWebConf test and handle captive portal requests.
if (iotWebConf.handleCaptivePortal())
{
// -- Captive portal request were already served.
return;
}
server.send(200, "text/html", m);
}


void handleTest()
{

String name_ = String(server.arg("fname"));
String patientID_ = String(server.arg("PatientID"));
Serial.println(name_);
Serial.println(patientID_);



String s = R"=====(
<!DOCTYPE html><html lang=\"en\"><head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1, user-scalable=no\"/>
<title>IotWebConf 01 Minimal</title></head><body> Go to <a href='config'>configure page</a> to change settings.
</body></html>\n)=====";


server.send(200, "text/html", s);

}
