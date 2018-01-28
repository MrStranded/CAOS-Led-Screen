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
          client.println("<body>"); 
          client.println("fuck yes, im the server");
          client.print("<br/><br/>");
          //client.println("<input>Enter text here</input>");
          client.println("<a href=\"http://192.168.178.42?penis\">");
          client.println("<input type=\"button\" value=\"Send text\"/>");
          client.println("</a>");
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
    Serial.println("client disconnected");
  }
}
