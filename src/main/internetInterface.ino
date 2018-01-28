#include <SPI.h>
#include <Ethernet.h>

byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
byte ip[] = {192, 168, 178, 42};
byte gateway[] = {192, 186,178,1};
byte subnet[] = {255,255,255,0};

String request;


EthernetServer server(80); // Web server

// Http data
String reqData; // Request from Smartphone
String header;
int contentSize = -1;
String CONTENT_LENGTH_TXT = "Content-Length: ";

void setupServer() {
    // disable the SD card by switching pin 4 high 
    pinMode(4, OUTPUT); 
    digitalWrite(4, HIGH); 

    // setup internet
    Serial.println("Initiaizing ethernet...");

    Ethernet.begin(mac, ip);//, gateway, subnet);
    // give the card a second to initialize 
    delay(1000);
    
    server.begin();
    Serial.println("Server set up at");
    Serial.println(Ethernet.localIP());
}

void serverLoop() {
  // listen for incoming clients 
  EthernetClient client = server.available(); 
  if (client) { 
    Serial.println("new client"); 

    request = "";
    
    // an http request ends with a blank line 
    boolean currentLineIsBlank = true; 
    while (client.connected()) { 
      if (client.available()) { 
        char c = client.read(); 
        Serial.write(c); 
        request += c;
        
        
        // if you've gotten to the end of the line (received a newline 
        // character) and the line is blank, the http request has ended, 
        // so you can send a reply 
        if (c == '\n' && currentLineIsBlank) { 
          if (request.startsWith("GET /?text=")) break;
          // send a standard http response header 
          client.println("HTTP/1.1 200 OK"); 
          client.println("Content-Type: text/html"); 
          client.println("Connection: close"); 
          // the connection will be closed after completion of the response 
          //client.println("Refresh: 10"); // refresh the page automatically every 5 sec 
          client.println(); 
          client.println("<!DOCTYPE HTML>"); 
          client.println("<html lang=\"en\">"); 
          client.println("<head>"); 
          client.println("<meta charset=\"utf-8\">");
          client.println("</head>");
          // css
          client.println("<style>");
          client.println("body { background-color: #d3d3d3;}");
          client.println("input[type=text], select {");
          client.println("width: 100%;");
          client.println("padding: 12px 20px;");
          client.println("margin: 8px 0;");
          client.println("display: inline-block");
          client.println("border: 1px solid #ccc");
          client.println("border-radius: 4px;");
          client.println("box-sizing: border-box;");
          client.println("font-size: 150%;}");
          client.println("input[type=submit], select {");
          client.println("width: 100%;");
          client.println("background-color: #4CAF50;");
          client.println("color: white;");
          client.println("padding: 14px 0;");
          client.println("margin: 8px 0;");
          client.println("border: none;");
          client.println("border-radius: 4px;}");
          client.println("input[type=submit]:hover {");
          client.println("background-color: #45a049;}");
          client.println("div {");
          client.println("width: 50%;");
          client.println("margin: auto;");
          client.println("border-radius: 5px;");
          client.println("background-color: #a2cd5a;");
          client.println("padding: 20px;}");
          client.println("</style>");
          
          // end of css
          client.println("<body>"); 
          client.println("<br/><br/><div>");
          client.println("<h1>Welcome to the LED-Matrix webserver</h1>");
          // input form
          client.println("<div>");
          client.println("<form>");
          client.println("<label for=\"led\">Enter Text</label>");
          client.println("<input type=\"text\" id=\"led\" name=\"text\">");
          client.println("<a href=\"http://192.168.178.42\"><br/>");
          client.println("<input type=\"submit\" value=\"Submit\"/>");
          client.println("</a></form></div></div>");
          // end of input form
          client.println("</body>"); 
          client.println("</html>"); 
          break; 
        } 
        if (c == '\n') { 
          // you're starting a new line 
          currentLineIsBlank = true; 
        } else if (c != '\r') { 
          // you've gotten a character on the current line 
          currentLineIsBlank = false; 
        } 
      } 
    } 
    // give the web browser time to receive the data 
    delay(1); 
    // close the connection: 
    client.stop(); 
    Serial.println("client request:");
    Serial.println(request);
    parseRequest(&request);
    Serial.println("client disconnected");
  }
}

void parseRequest(String *request) {
  int startIndex = request->indexOf("/"); // 'GET /?text=jahui HTTP/1.1\n'
  if (!(request->charAt(startIndex + 1) == '?')) {
    return;
  }
  startIndex += 7; // 'GET /?text=jahui HTTP/1.1\n'
  int endIndex = request->indexOf("\n") - 10; // 'GET /?text=jahui HTTP/1.1\n'
  char message[endIndex - startIndex];
  // substring doesn't work
  for(int i = 0; i < endIndex - startIndex; i++) {
    message[i] = request->charAt(startIndex + i);
  }
  // black magic (it removes some weird characters, we don't
  // know why either)
  String str(message);
  Serial.println("------------");
  Serial.println(message);
  Serial.println("------------");
  writeText(message);
}



// OLD INTERNETINTERFACE (Micha)




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
