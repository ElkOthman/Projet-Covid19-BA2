#include <WiFi.h>;

const char* ssid = "WIFISSI";
const char* password =  "WIFIPASSWORD";

void setup() {
  Serial.begin(9600);
  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");
 
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
 
  Serial.println("\nConnected to the WiFi network");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
}
 
void loop() {
  if ((WiFi.status() == WL_CONNECTED)) //Check the current connection status
  {
    Serial.println("Connected!!!");
    Serial.println(WiFi.localIP());
    delay(5000);
  }
  else
  {
    Serial.println("Connection lost");
  }
}
