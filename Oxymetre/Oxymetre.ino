/**
   BLEClientOxy
   A client for the BT Oxymeter named SP001.
   It retrieves notification values (spo2, bpm and pi)
   
   This code is based on the Arduino BLE client example !
*/

//Uncomment if you want to print a lot of debug output for this code
#define _DBG

#include "BLEDevice.h"
#include "dbgout.h"

//If you know the oxy BLE address, you can replace by it, so it will always connect to a specific one
#define OXYADDRESS "00:00:00:00:00:00"

//Device name of the oxymeter (don't change it)
#define OXYNAME "SP001"

//NULL BLUTOOTH MAC ADDRESS
#define BLENULLADDRESS "00:00:00:00:00:00"

// BLE Address of the oxymeter
static BLEAddress OxyAddr(OXYADDRESS);
// The remote service we wish to connect to (only visible after connection to the device !)
static BLEUUID serviceUUID("f000efe0-0451-4000-0000-00000000b000");
// The characteristic of the remote service we are interested in.
static BLEUUID    charUUID("f000efe3-0451-4000-0000-00000000b000");

static boolean doConnect = false;
static boolean connected = false;
static boolean doScan = false;
static BLERemoteCharacteristic* pRemoteCharacteristic;
static BLEAdvertisedDevice* myDevice;
static int OxyRSSI = 0;
//timestamps when oxymeter was respectively on and off
unsigned long laston = 0, lastoff = 0;

//Oxymeter callbacks that can be changed
//callback with the SpO2 and Pulse intensity values
static void spo2piCallback(int _spo2,float _pi) {
  Serial.print("The current oxymeter value (SpO2) is ");
  Serial.print(_spo2);
  Serial.print("% and the pulse intensity is ");
  Serial.println(_pi);
}

//callback with the Pulse/Hearht Rate (bpm)
static void bpmCallback(int _bpm) {
  Serial.print("The current HR is ");
  Serial.println(_bpm);
}

//callback when the oxymeter is on or off
static void onoffCallback(boolean is_on,long duration) {
  if (is_on) {
    Serial.print("The oxymeter is now on and was off during ");
    Serial.print(-duration/1000);
  } else {
    Serial.print("The oxymeter is now off and was on during ");
    Serial.print(duration/1000);
  }
  Serial.println("sec");
}

//callbacks on connection and disconnection of the oxymeter
class MyClientCallback : public BLEClientCallbacks {
    void onConnect(BLEClient* pclient) {
      Serial.println("Connected to the oxymeter");
    }

    void onDisconnect(BLEClient* pclient) {
      connected = false; //do not remove this !!      
      Serial.println("Disconnected from the oxymeter");
    }
};

//Notification callback from the oxymeter (do not change it !)
static void notifyCallback(
  BLERemoteCharacteristic* pBLERemoteCharacteristic,
  uint8_t* pData,
  size_t length,
  bool isNotify) {
  dbgout("raw data notification : ");
  for (int i = 0; i < length; i++) {
    dbgout(pData[i]);
    dbgout(", ");
  }
  dbgoutln();
  switch (pData[0]) {
    case 18:
      spo2piCallback(pData[12],pData[14] / 10.0);
      break;
    case 10:
      bpmCallback(pData[12]);
      break;
    case 252:
      if (pData[2] == 2) laston = millis();
      else lastoff=millis();
      onoffCallback(pData[2] == 2,lastoff-laston);
      break;    
  }  
}

//Connection to the oxymeter
bool connectToServer() {
  dbgout("Forming a connection to ");
  dbgoutln(myDevice->getAddress().toString().c_str());

  BLEClient*  pClient  = BLEDevice::createClient();
  dbgoutln(" - Created client");

  pClient->setClientCallbacks(new MyClientCallback());

  // Connect to the remove BLE Server.
  pClient->connect(myDevice);  // if you pass BLEAdvertisedDevice instead of address, it will be recognized type of peer device address (public or private)
  dbgoutln(" - Connected to server");

  // Obtain a reference to the service we are after in the remote BLE server.
  BLERemoteService* pRemoteService = pClient->getService(serviceUUID);
  if (pRemoteService == nullptr) {
    dbgout("Failed to find our service UUID: ");
    dbgoutln(serviceUUID.toString().c_str());
    pClient->disconnect();
    return false;
  }
  dbgoutln(" - Found our service");

  // Obtain a reference to the characteristic in the service of the remote BLE server.
  pRemoteCharacteristic = pRemoteService->getCharacteristic(charUUID);
  if (pRemoteCharacteristic == nullptr) {
    dbgout("Failed to find our characteristic UUID: ");
    dbgoutln(charUUID.toString().c_str());
    pClient->disconnect();
    return false;
  }
  dbgoutln(" - Found our characteristic");

  // Read the value of the characteristic.
  if (pRemoteCharacteristic->canRead()) {
    std::string value = pRemoteCharacteristic->readValue();
    dbgout("The characteristic value was: ");
    dbgoutln(value.c_str());
  }

  if (pRemoteCharacteristic->canNotify())
    pRemoteCharacteristic->registerForNotify(notifyCallback);

  connected = true;
  return true;
}
/**
   Scan for BLE servers and find the first one that advertises the service we are looking for.
*/
class MyAdvertisedDeviceCallbacks: public BLEAdvertisedDeviceCallbacks {
    /**
        Called for each advertising BLE server.
    */
    void onResult(BLEAdvertisedDevice advertisedDevice) {
      dbgout("BLE Advertised Device found: ");
      dbgoutln(advertisedDevice.toString().c_str());

      // We have found a device, let us now see if it is the oxymeter we are looking for
      // If the ble address is specified, it has priority vs. the oxy name and also, in case of disconnection, reconnect to the same one
      if ((OxyAddr.toString()==BLENULLADDRESS && advertisedDevice.getName() == OXYNAME) || OxyAddr.equals(advertisedDevice.getAddress())) {
        BLEDevice::getScan()->stop();
        myDevice = new BLEAdvertisedDevice(advertisedDevice);
        doConnect = true;
        doScan = true;
        OxyAddr =  advertisedDevice.getAddress(); 
        OxyRSSI =  advertisedDevice.getRSSI();      
      } // Found our server
    } // onResult
}; // MyAdvertisedDeviceCallbacks


void setup() {
  Serial.begin(115200);  
  dbgoutln("Starting Arduino BLE Client application...");
  BLEDevice::init("");
  // Retrieve a Scanner and set the callback we want to use to be informed when we
  // have detected a new device.  Specify that we want active scanning and start the
  // scan to run for 10 seconds.
  BLEScan* pBLEScan = BLEDevice::getScan();
  pBLEScan->setAdvertisedDeviceCallbacks(new MyAdvertisedDeviceCallbacks());
  pBLEScan->setInterval(1349);
  pBLEScan->setWindow(449);
  pBLEScan->setActiveScan(true);
  dbgoutln("BLE 10sec scan");
  pBLEScan->start(10, false);
} // End of setup.


// This is the Arduino main loop function.
void loop() {

  // If the flag "doConnect" is true then we have scanned for and found the desired
  // BLE Server (i.e. Oxymeter) with which we wish to connect.  Now we connect to it.  Once we are
  // connected we set the connected flag to be true.
  if (doConnect == true) {
    if (connectToServer()) {
      dbgoutln("We are now connected to the BLE Server.");
    } else {
      dbgoutln("We have failed to connect to the server; there is nothin more we will do.");
    }
    doConnect = false;
  }

  // If we are connected to a peer BLE Server, update the characteristic each time we are reached
  // with the current time since boot.
  if (connected) {    
    //we may do something here since we know we are connected to the oxymeter
  } else if (doScan) {
    //not connected anymore --> infinite scan 
    BLEDevice::getScan()->start(0);  // this is just eample to start scan after disconnect (infinite scan !), most likely there is better way to do it in arduino
  }  
  
  delay(500); // Delay half a second between loops/this delay can probably be removed 
} // End of loop
