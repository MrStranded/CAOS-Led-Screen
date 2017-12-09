// -----------------------------------------------------------------------------
//
// In this file you will find methods to control the internet connection of the arduino
// and to get data from the internet conveniantly.
//
// If you have trouble with the library files go to:
// Sketch -> Include Library -> Manage Libraries
// and look for the Arduino Http Client and install it.
//
// -----------------------------------------------------------------------------

#include <SPI.h>
#include <Ethernet.h>

// Enter a MAC address for your controller below.
// Newer Ethernet shields have a MAC address printed on a sticker on the shield
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };

// if you don't want to use DNS (and reduce your sketch size)
// use the numeric IP instead of the name for the server:

IPAddress server(192,168,1,113);  // numeric IP
//char server[] = "http://info.cern.ch"; // textographic IP
char site[] = "website/pixelinfo.txt";

// Set the static IP address to use if the DHCP fails to assign
IPAddress ip(192, 168, 0, 177);

// Initialize the Ethernet client library
// with the IP address and port of the server
// that you want to connect to (port 80 is default for HTTP):
EthernetClient client;

// those two are necessary to read in the screen info
int xCounter = 0;
int yCounter = 0;

// %%%%%%%%%%%%%%%%%%%%%

// this method sets up a connection to the given url
// you may read the result with printInternetResponse()

void setupInternetConnection() {
  
  // start the Ethernet connection:
  if (Ethernet.begin(mac) == 0) {
    Serial.println("Failed to configure Ethernet using DHCP");
    // try to congifure using IP address instead of DHCP:
    Ethernet.begin(mac, ip);
  }
  
  // give the Ethernet shield a second to initialize:
  delay(1000);
  Serial.println("connecting...");

  // if you get a connection, report back via serial:
  if (client.connect(server, 8000)) {
    Serial.println("connected");
    // Make a HTTP request:
    client.print("GET ");
    client.println(site);
    client.println("Host: 192.168.1.113");
    client.println("Accept: text/html");
    client.println("Connection: close");
    client.println();
  } else {
    // if you didn't get a connection to the server:
    Serial.println("connection failed");
  }
}

// %%%%%%%%%%%%%%%%%%%%%

// puts the server response into the led matrix

void putResponseIntoLedMatrix() {
  if (client.available()) {
    char c = client.read();
    Serial.print(c);
    int found = 0;
    if (c == '0') {
      found=1;
      setPixel(xCounter,7-yCounter,0);
    } else if (c == '1') {
      //Serial.println("FOUND!");
      //Serial.println(xCounter);
      //Serial.println(yCounter);
      found=1;
      setPixel(xCounter,7-yCounter,1);
    }
    if (found) {
      yCounter++;
      if (yCounter >= 8) {
        yCounter = 0;
        xCounter++;
      }
    }
  }
  
  // if the server's disconnected, stop the client:
  if (!client.connected()) {
    Serial.println();
    Serial.println("disconnecting.");
    client.stop();

    // do nothing forevermore:
    debugScreen();
    while (true);
  }
}

// %%%%%%%%%%%%%%%%%%%%%

// prints the response from setupInternetConnection onto the Serial output

void printInternetResponse() {
  // if there are incoming bytes available
  // from the server, read them and print them:
  if (client.available()) {
    char c = client.read();
    Serial.print(c);
  }

  // if the server's disconnected, stop the client:
  if (!client.connected()) {
    Serial.println();
    Serial.println("disconnecting.");
    client.stop();

    // do nothing forevermore:
    while (true);
  }
}

