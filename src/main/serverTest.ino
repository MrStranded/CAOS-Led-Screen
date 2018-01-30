//#include <SPI.h>
#include <Ethernet.h>

byte mac[] = { 0x1E, 0xE7, 0xC0, 0xDE, 0xBA, 0x5E };
byte ip[] = {192, 168, 178, 42};
byte weather[] = {146, 185, 181, 89};

unsigned int localPort = 8888;       // local port to listen for UDP packets
char timeServer[] = "time.nist.gov"; // time.nist.gov NTP server
const int NTP_PACKET_SIZE = 48; // NTP time stamp is in the first 48 bytes of the message
byte packetBuffer[ NTP_PACKET_SIZE]; //buffer to hold incoming and outgoing packets
// A UDP instance to let us send and receive packets over UDP
EthernetUDP Udp;

String request;

EthernetServer server(80); // Web server
EthernetClient apiClient;

void setupServer() {
  // disable the SD card by switching pin 4 high
  pinMode(4, OUTPUT);
  digitalWrite(4, HIGH);

  // setup internet
  Ethernet.begin(mac, ip);//, gateway, subnet);
  // give the card a second to initialize
  delay(1000);

  server.begin();
  Serial.println("Server set up at");
  Serial.println(Ethernet.localIP());

  Udp.begin(localPort);
}

void serverLoop() {
  // listen for incoming clients
  EthernetClient client = server.available();
  if (client) {

    request = "";

    // an http request ends with a blank line
    boolean currentLineIsBlank = true;
    int i = 0;
    while (client.connected()) {
      if (client.available()) {
        char c = client.read();
        Serial.write(c);
        if (i < 160) request += c;
        i++;

        // if you've gotten to the end of the line (received a newline
        // character) and the line is blank, the http request has ended,
        // so you can send a reply
        if (c == '\n' && currentLineIsBlank) {
          //if (request.startsWith("GET /?text=")) break;
          // SEND HTTP RESPONSE HEADER
          //client.println("HTTP/1.1 200 OK");
          //client.println("Connection: close");  // the connection will be closed after completion of the response
          //client.println("Refresh: 10"); // refresh the page automatically every 5 sec
          //client.println();
          // CSS
          client.println("<style>");
          client.println("body { background-color: #a6a6a6;}");
          client.println("input[type=text], select {");
          client.println("box-sizing: border-box;");
          client.println("width: 100%;");
          client.println("font-size: 150%;}");
          client.println("input[type=submit], select {");
          client.println("width: 100%;");
          client.println("background-color: #5381ac;");
          client.println("color: white;}");
          client.println("div {");
          client.println("width: 50%;");
          client.println("padding: 20px;}");
          client.println("</style>");
          // END OF CSS
          // BODY
          client.println("<body><div>");
          client.println("<h1>Welcome to the LED-Matrix webserver</h1>");
          // INPUT FORM
          client.println("<div><form action=\"http://192.168.178.42\" method=\"GET\">");
          client.println("<input type=\"text\" id=\"led\" name=\"text\">");
          client.println("<input type=\"submit\" value=\"Submit\"/><hr/>");
          client.println("<input type=\"submit\" name=\"time\" value=\"Time\">");
          client.println("<input type=\"submit\" name=\"weather\" value=\"Weather\"></form></div>");
          // END OF INPUT FORM
          client.println("</div></body></html>");
          // END OF BODY
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
    parseRequest(&request);
  }
}

// --------------------------

// PARSER

void parseRequest(String *request) {
  int startIndex = request->indexOf("/"); // 'GET /?text=jahui HTTP/1.1\n'
  if (!(request->charAt(startIndex + 1) == '?')) {
    // no get request, nothing to parse
    return;
  }
  startIndex += 7; // 'GET /?text=jahui HTTP/1.1\n'
  int endIndex = request->indexOf("\n") - 10; // 'GET /?text=jahui HTTP/1.1\n'
  char message[endIndex - startIndex + 1] = "";
  if (request->charAt(startIndex) == '&') {
    // time request
    if (request->charAt(startIndex + 1) == 't') {
      // CALL TIME API HERE
      //printTime();
      getCurrentTime();
      return;
    }
    // weather request
    if (request->charAt(startIndex + 1) == 'w') {
      // CALL WEATHER API HERE
      //setLongText("kalt");
      printWeather();
      return;
    }
  }
  // print text
  // substring doesn't work
  for (int i = 0; i < endIndex - startIndex; i++) {
    message[i] = request->charAt(startIndex + i);
    if (request->charAt(startIndex + i) == '+') message[i] = ' ';
    if (request->charAt(startIndex + i) == '%' ||
        request->charAt(startIndex + i + 1) == '3' ||
        request->charAt(startIndex + i + 2) == 'F') {
      message[i] = '?';
      message[i + 1] = 0;
      message[i + 2] = 0;
      i += 2;
    }
  }
  message[endIndex - startIndex] = 0; // last character has to be zero, or the string won't "end" there
  // black magic (it removes some weird characters, we don't know why either)
  String str(message);
  Serial.println("------------");
  Serial.println(message);
  Serial.println("------------");
  setLongText(message);
}

// ---------------------

// WEATHER REQUEST

void printWeather() {
  //String searchTags[2] = {"temp:\"","description:\""};

  if (apiClient.connect(weather, 80)) {
    apiClient.println("GET /data/2.5/weather?q=Basel&APPID=3410a8375afbfb13baeeff03f2472b6b");
    apiClient.println();

    // converting the string into a char array and printing it onto the screen
    char *answer = searchStreamForKeyWord("temp", 4, 2, 6);

    // set to celsius
    float kelvin = 0.f;
    kelvin += (answer[0] - 48) * 100;
    kelvin += (answer[1] - 48) * 10;
    kelvin += answer[2] - 48;
    kelvin += (answer[4] - 48) * 0.1;
    kelvin += (answer[5] - 48) * 0.01;
    float cel = kelvin - 273.15;

    char celsius[6];
    dtostrf(cel, 6, 2, celsius);
    char temp[8];
    for (int i = 0; i < 6; i++) {
      temp[i] = celsius[i];
    }
    temp[6] = '@';
    temp[7] = 'C';

    // converting the string into a char array and printing it onto the screen
    //setLongText(temperature.c_str());
    //setLongText(celsius.c_str());
    setLongText(temp);
    apiClient.stop();

  } else {
    setLongText("Nuclear winter");
  }
}

// *******************

// returns a char array which immediatly trails the keyword of length

char *searchStreamForKeyWord(char *search, int listenerSize, int gapLength, int searchLength) {
  char listener[listenerSize] = ""; // listens for search
  int listenerPos = 0;

  int found = 0;

  // first we want to find where the temperature lies
  while (apiClient.connected()) {
    if (apiClient.available()) {
      char c = apiClient.read();
      Serial.print(c);

      // we fill the listener buffer
      if (listenerPos >= listenerSize) { // buffer is full - we have to shift the data to the left
        for (int i = 0; i < listenerSize - 1; i++) {
          listener[i] = listener[i + 1];
        }
        listener[listenerSize - 1] = c;
      } else { // buffer not yet full, we continue to fill it where we left the last time
        listener[listenerPos] = c;
        listenerPos++;
      }

      // here we check wheter we encountered the string we need
      found = 1;
      for (int i = 0; i < listenerSize; i++) {
        if (listener[i] != search[i]) { // not all characters match the search mask -> found = 0
          found = 0;
          //break;
        }
      }
      if (found == 1) { // all characters match -> leave loop
        break;
      }
    }
  }

  // now that we know where the temperature is, we want to extract it
  if (found == 1) {
    char answer[searchLength + 1] = ""; // here we build the answer
    int i = -gapLength;

    while (apiClient.connected()) {
      if (apiClient.available()) {
        char c = apiClient.read();
        Serial.print(c);

        if (i >= 0) {
          answer[i] = c;
        }
        i++;
        if (i >= searchLength) {
          answer[searchLength] = 0;
          return answer;
        }
      }
    }
  } else {
    return "-";
  }
}

// ------------

// Time request

void getCurrentTime() {
  sendNTPpacket(timeServer); // send an NTP packet to a time server

  // wait to see if a reply is available
  delay(1000);
  if (Udp.parsePacket()) {
    // We've received a packet, read the data from it
    Udp.read(packetBuffer, NTP_PACKET_SIZE); // read the packet into the buffer

    // the timestamp starts at byte 40 of the received packet and is four bytes,
    // or two words, long. First, extract the two words:

    unsigned long highWord = word(packetBuffer[40], packetBuffer[41]);
    unsigned long lowWord = word(packetBuffer[42], packetBuffer[43]);
    // combine the four bytes (two words) into a long integer
    // this is NTP time (seconds since Jan 1 1900):
    unsigned long secsSince1900 = highWord << 16 | lowWord;
    // Unix time starts on Jan 1 1970. In seconds, that's 2208988800:
    const unsigned long seventyYears = 2208988800UL;
    // subtract seventy years:
    unsigned long epoch = secsSince1900 - seventyYears;
    epoch += 3600; // UTC + 1 University of Basel, Switzerland

    int hour = (epoch  % 86400L) / 3600;
    int minute = (epoch  % 3600) / 60;
    int second = epoch % 60;

    char currentTime[6];
    
    currentTime[0] = (char) ((((hour - (hour % 10))/10) % 10) + 48);
    currentTime[1] = (char) ((hour % 10) + 48);
    currentTime[2] = ':';
    currentTime[3] = (char) ((((minute - (minute % 10))/10) % 10) + 48);
    currentTime[4] = (char) ((minute % 10) + 48);
    //currentTime[5] = ':';
    //currentTime[6] = (char) ((((second - (second % 10))/10) % 10) + 48);
    //currentTime[7] = (char) ((second % 10) + 48);
    currentTime[5] = '\0';
    
    //Serial.println(currentTime);
    setLongText(currentTime);
  }
  Ethernet.maintain();
}

// UDP STUFF

// send an NTP request to the time server at the given address
void sendNTPpacket(char* address) {
  // set all bytes in the buffer to 0
  memset(packetBuffer, 0, NTP_PACKET_SIZE);
  // Initialize values needed to form NTP request
  // (see URL above for details on the packets)
  packetBuffer[0] = 0b11100011;   // LI, Version, Mode
  packetBuffer[1] = 0;     // Stratum, or type of clock
  packetBuffer[2] = 6;     // Polling Interval
  packetBuffer[3] = 0xEC;  // Peer Clock Precision
  // 8 bytes of zero for Root Delay & Root Dispersion
  packetBuffer[12]  = 49;
  packetBuffer[13]  = 0x4E;
  packetBuffer[14]  = 49;
  packetBuffer[15]  = 52;

  // all NTP fields have been given values, now
  // you can send a packet requesting a timestamp:
  Udp.beginPacket(address, 123); //NTP requests are to port 123
  Udp.write(packetBuffer, NTP_PACKET_SIZE);
  Udp.endPacket();
}

