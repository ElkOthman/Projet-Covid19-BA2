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
<input type="text"name="fname"><br>
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
// -- doLoop should be called as frequently as possible.
iotWebConf.doLoop();

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

Serial.println(name_);

String s = R"=====(
<!DOCTYPE html><html lang=\"en\"><head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1, user-scalable=no\"/>
<title>IotWebConf 01 Minimal</title></head><body> Go to <a href='config'>configure page</a> to change settings.
</body></html>\n)=====";

server.send(200, "text/html", s);

}

/*String m = R"=====(

<!DOCTYPE html>
<html>
<body>
<h2>HTML Forms</h2>
<form action="/test">
<label for="fname">First name:</label><br>
<input type="text"name="fname"><br>
<input type="submit" value="Submit">
</form>
</body>
</html>

)=====";*/
