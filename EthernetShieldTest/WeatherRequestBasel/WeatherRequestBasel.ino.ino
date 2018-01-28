/*
  Web client

  This sketch connects to a website (http://www.google.com)
  using an Arduino Wiznet Ethernet shield.

  Circuit:
   Ethernet shield attached to pins 10, 11, 12, 13

  created 18 Dec 2009
  by David A. Mellis
  modified 9 Apr 2012
  by Tom Igoe, based on work by Adrian McEwen

*/

#include <SPI.h>
#include <Ethernet.h>
#include <ArduinoJson.h>

// Enter a MAC address for your controller below.
// Newer Ethernet shields have a MAC address printed on a sticker on the shield
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
// if you don't want to use DNS (and reduce your sketch size)
// use the numeric IP instead of the name for the server:
//IPAddress server(74,125,232,128);  // numeric IP for Google (no DNS)
char server[] = "api.openweathermap.org";    // name address for Google (using DNS)

// Set the static IP address to use if the DHCP fails to assign
IPAddress ip(192, 168, 0, 177);

// Initialize the Ethernet client library
// with the IP address and port of the server
// that you want to connect to (port 80 is default for HTTP):
EthernetClient client;

String jsonData;

void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

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
  if (client.connect("www.jsontest.com", 80)) {
    Serial.println("connected");
    // Make a HTTP request:
//    client.println("GET /data/2.5/weather?q=Basel&APPID=3410a8375afbfb13baeeff03f2472b6b");
//    client.println("Host: http://api.openweathermap.org");
client.println("Host: http://ip.jsontest.com");
    client.println("Connection: close");
    client.println();
  } else {
    // if you didn't get a connection to the server:
    Serial.println("connection failed");
  }


  /*
    char json[] = "{\"sensor\":\"gps\",\"time\":1351824120,\"data\":[48.756080,2.302038]}";

    StaticJsonBuffer<200> jsonBuffer;

    JsonObject& root = jsonBuffer.parseObject(json);

    const char* sensor = root["sensor"];
    long time          = root["time"];
    double latitude    = root["data"][0];
    double longitude   = root["data"][1];
  */
}

void loop() {

  // if there are incoming bytes available
  // from the server, read them and print them:
  if (client.available()) {
    char c = client.read();
    jsonData.concat(c);
  }
  if (!client.connected()) {
    // if the server's disconnected, stop the client:

    Serial.println();
    Serial.println("disconnecting.");

    String jj = "{\"lol\":[\"bitches\", \"snitches\"]}";

    //Serial.println(jsonData);
    Serial.print(jsonData);


    StaticJsonBuffer<11000> jsonBuffer;
    JsonObject& root = jsonBuffer.parseObject(jsonData, 10);
    Serial.println("testtest");

    if (root.success()) {
      Serial.println("yeah boy!");
      const char* s = root["ip"];
      Serial.println(s);
    } else {
      Serial.println("fuuuuu");
    }


    // do nothing forevermore:
    while (true){};
  }
}

