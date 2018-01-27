// states for the state machine (if needed)

#define CONNECTIONSTATE 0
#define WAITINGSTATE 1

// delay between frames in miliseconds

#define LEDFRAMEDELAY 10

// %%%%%%%%%%%%%%%%%%%%%

// setup of the Serial port used for debugging

void setupSerial() {
  Serial.begin(9600);
  Serial.flush();
}

// main entry point of the code

void setup() {
  writeText("Sroogeee!");
  //setupSerial();
  setupServer();
  initLedScreen();

  //setAll(1);

  //connectToServer("192.168.1.2", 8000, "GET website/pixelinfo_horizontal.txt");
  //readResponse(1);

  //setupLEDTest();
}

// %%%%%%%%%%%%%%%%%%%%%

// main loop of the program

int counter = 0;

void loop() {
  //serverLoop();
  drawLedScreen();
  counter++;
  if (counter >= 50) {
    shiftTextLeft();
    counter -= 50;
  }
  
}

// %%%%%%%%%%%%%%%%%%%%%
