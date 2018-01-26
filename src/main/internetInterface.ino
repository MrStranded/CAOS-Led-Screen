/*// -----------------------------------------------------------------------------
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

char* server;// = "192.168.1.113";
char* request;// = "GET website/pixelinfo_horizontal.txt";
int port = 8000;

// Set the static IP address to use if the DHCP fails to assign
IPAddress ip(192, 168, 1, 3);

// Initialize the Ethernet client library
// with the IP address and port of the server
// that you want to connect to (port 80 is default for HTTP):
EthernetClient client;

// those two are necessary to read in the screen info
int xCounter = 0;
int yCounter = 0;

// %%%%%%%%%%%%%%%%%%%%%

// connects to the given server:port and sends the given request

void connectToServer(char* serverIp, int serverPort, char* serverRequest) {
  server = serverIp;
  port = serverPort;
  request = serverRequest;

  setupInternetConnection();
}

// %%%%%%%%%%%%%%%%%%%%%

// reads data from request into led matrix
// mode defines how the incoming data is handled
// mode = 0 : pixel data read separately (vertical)
// mode = 1 : pixel data read separately (horizontal)
// mode = 2 : characters interpreted as value of led matrix row
// mode = 3 : characters are put into led matrix as whole multi-line letters

void readResponse(int mode) {
  if (mode == 0) {
    Serial.println("Reading pixel data vertically.");
    while (putPixelResponseIntoLedMatrix(0)) {}
  }
  if (mode == 1) {
    Serial.println("Reading pixel data horizontally.");
    while (putPixelResponseIntoLedMatrix(1)) {}
  }
  if (mode == 2) {
    Serial.println("Reading byte data.");
    while (putByteResponseIntoLedMatrix()) {}
  }
  if (mode == 3) {
    Serial.println("Reading text data.");
    while (putTextResponseIntoLedMatrix()) {}
  }
}

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
  if (client.connect(server, port)) {
    Serial.println("connected");
    // Make a HTTP request:
    client.println(request);
    client.print("Host: ");
    client.println(server);
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
// if a '0' is read, then the corresponding pixel is set to low
// if a '1' is read, then the corresponding pixel is set to high
// direction denotes the direction in which the pixel data is oriented in the file
// direction == 0 : vertically
// direction != 0 : horizontally

int putPixelResponseIntoLedMatrix(int direction) {
  if (client.available()) {
    char c = client.read();
    
    // did we encounter a '0' or '1'?
    int found = 0;
    int yPos = 7-yCounter; // 7-yCounter because it would be on the head otherwise in the vertical case
    if (direction != 0) yPos = yCounter;

    // data for low pixel
    if (c == '0') {
      found=1;
      setPixel(xCounter,yPos,0);
    }

    // data for high pixel
    if (c == '1') {
      found=1;
      setPixel(xCounter,yPos,1);
    }

    // we encountered a '0' or '1'
    if (found) {
      // setting the new pixel positions

      if (direction == 0) { // ----- vertical
        yCounter++;
        // getting to the next column
        if (yCounter >= 8) {
          yCounter = 0;
          xCounter++;
        }
      } else { // ------------------ horizontal
        xCounter++;
        // getting to the next column
        if (xCounter >= 48) {
          xCounter = 0;
          yCounter++;
        }
      }
    }
  }
  
  // if the server's disconnected, stop the client:
  if (!client.connected()) {
    closeConnection();
    return 0;
  }
  return 1;
}

// %%%%%%%%%%%%%%%%%%%%%

// puts the read character as byte into the next led matrix column

int putByteResponseIntoLedMatrix() {
  if (client.available()) {
    char c = client.read();
    writeChar(c,xCounter);

    xCounter++;
  }
  
  // if the server's disconnected, stop the client:
  if (!client.connected()) {
    closeConnection();
    return 0;
  }
  return 1;
}

// %%%%%%%%%%%%%%%%%%%%%

// puts the read character asletter into the next led matrix letter slot

int putTextResponseIntoLedMatrix() {
  if (client.available()) {
    char c = client.read();
    writeCharIntoSlot(c,xCounter);

    xCounter++;
  }
  
  // if the server's disconnected, stop the client:
  if (!client.connected()) {
    closeConnection();
    return 0;
  }
  return 1;
}


// %%%%%%%%%%%%%%%%%%%%%

// closes the running connection

void closeConnection() {
    Serial.println("disconnecting.");
    Serial.println();
    client.stop();
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
    closeConnection();

    // do nothing forevermore:
    while (true);
  }
}
*/
