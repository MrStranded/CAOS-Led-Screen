#include <SPI.h>
#include <Ethernet.h>
#include <stdio.h>

byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
byte ip[] = {192, 168, 178, 42};
byte gateway[] = {192, 186, 178, 1};
byte subnet[] = {255, 255, 255, 0};

EthernetClient requestClient;

char str[1024];

void setupClient() {

  // if you get a connection, report back via serial:
  if (requestClient.connect("www.google.com", 80)) {
    Serial.println("connected");
    // Make a HTTP request:
    requestClient.println("GET /search?q=arduino HTTP/1.1");
    requestClient.println("Connection: close");
    requestClient.println("Host: www.google.com");
    requestClient.println();
  } else {
    // if you didn't get a connection to the server:
    Serial.println("connection failed");
  }
  clientLoop();
}

void clientLoop() {
      char c[2];
      c[1] = '\0';
  // if there are incoming bytes available
  // from the server, read them and print them:
  while (requestClient.connected()) {
    if (requestClient.available()) {
      c[0] = requestClient.read();
      strcat(str, c);
    }
  }
  Serial.print(str);
  requestClient.stop();
}
