#include <SPI.h>
#include <Ethernet.h>

byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
IPAddress ip(192, 168, 1, 130); // Arduino IP Add
byte gateway[] = {192, 186,1,1};
byte subnet[] = {255,255,255,0};


EthernetServer server(80); // Web server

// Http data
String reqData; // Request from Smartphone
String header;
int contentSize = -1;
String CONTENT_LENGTH_TXT = "Content-Length: ";

void setupServer() {
    // put your setup code here, to run once:
    Serial.begin(9600);
    Serial.print("Ready...");
    //
    Ethernet.begin(mac, ip, gateway, subnet);
    server.begin();
    //clearScreen();
    writeText("JAHUIII");
    Serial.println("Server set up at");
    Serial.println(Ethernet.localIP());
}

void serverLoop() {
    EthernetClient client = server.available(); // Is there a client (Our Android smartphone)

    if (client) {
      Serial.println("client request");
      writeText("internet");
      
      /*
        // Let's start reading
        boolean isLastLine = true;
        boolean isBody = false;
        header = "";
        reqData = "";
        int contentLen = 0;

        Serial.print("Client connected!");
        while (client.connected()) {
            if (client.available()) {
                // Read data
                char c = client.read();

                // Serial.print(c);

                if (contentSize == contentLen) {
                    // Serial.println("Body ["+reqData+"]");

                    int idx = reqData.indexOf(":");
                    String status = reqData.substring(idx + 1, idx + 2);
                    Serial.println("Status : " + status);
                    if (status.equals("1")) {
                        digitalWrite(3, HIGH);
                    }
                    else {
                        digitalWrite(3, LOW);
                    }

                    client.println("HTTP/1.1 200 OK");
                    client.println("Content-Type: text/html");
                    client.println("Connection: close");
                    client.println();
                    // send web page
                    client.println("");
                    client.println("");
                    delay(1);
                    break;
                }


                if (c == '\n' && isLastLine) {
                    isBody = true;
                    int pos = header.indexOf(CONTENT_LENGTH_TXT);
                    String tmp = header.substring(pos, header.length());
                    //Serial.println("Tmp ["+tmp+"]");
                    int pos1 = tmp.indexOf("\r\n");
                    String size = tmp.substring(CONTENT_LENGTH_TXT.length(), pos1);
                    Serial.println("Size ["+size+"]");
                    contentSize = size.toInt();

                }

                if (isBody) {
                    reqData += c;
                    contentLen++;
                }
                else {
                    header += c;
                }


                if (c == '\n' ) {
                    isLastLine = true;
                }
                else if (c != '\r' ) {
                    isLastLine = false;
                }



            }
        }*/

        // Close connection
        Serial.println("Stop..");
        client.stop();
    }
}
