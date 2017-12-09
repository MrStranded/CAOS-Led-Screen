// states for the state machine (if needed)

#define CONNECTIONSTATE 0
#define WAITINGSTATE 1

// %%%%%%%%%%%%%%%%%%%%%

// setup of the Serial port used for debugging

void setupSerial() {
  Serial.begin(9600);
  Serial.flush();
}

// main entry point of the code

void setup() {
  setupSerial();

  connectToServer("192.168.1.113",8000,"GET website/textinfo.txt");
  readResponse(2);
}

// %%%%%%%%%%%%%%%%%%%%%

// main loop of the program

void loop() {
  debugScreen();
  while(1){}
}

// %%%%%%%%%%%%%%%%%%%%%
