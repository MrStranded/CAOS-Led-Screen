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

#include <Bridge.h>
#include <HttpClient.h>

// the pin to communicate with the ethernet board

const int ethernetPin = 13;

// the client that connects to the internet

HttpClient client;

// %%%%%%%%%%%%%%%%%%%%%

// set up bridge, pins and ethernet shield

void initInternet() {
  pinMode(ethernetPin, OUTPUT);
  digitalWrite(ethernetPin, LOW);
}

// %%%%%%%%%%%%%%%%%%%%%

// create a connection to the given url

void createConnection(String url) {
  client.get(url);
}

// %%%%%%%%%%%%%%%%%%%%%

// read out internet data

void printInternetResponse() {
  while (client.available()) {
    char c = client.read();
    Serial.print(c);
  }
  Serial.println("not available anymore");
}

// %%%%%%%%%%%%%%%%%%%%%

// closes the active connection

void closeConnection() {
  // TODO
}

// %%%%%%%%%%%%%%%%%%%%%

// returns the data from the site with the given name

String getData(String name) {
  // TODO
}

// %%%%%%%%%%%%%%%%%%%%%

