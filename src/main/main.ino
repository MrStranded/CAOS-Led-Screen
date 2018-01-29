// states for the state machine (if needed)

#define CONNECTIONSTATE 0
#define WAITINGSTATE 1

// delay between frames in miliseconds

#define LEDFRAMEDELAY 10

// %%%%%%%%%%%%%%%%%%%%%

// setup of the Serial port used for debugging

void setupSerial() {
  Serial.begin(9600);
  delay(1);
  Serial.flush();
}

// main entry point of the code

void setup() {
  setupSerial();
  setupServer();
  initLedScreen();

  //setAll(1);

  //connectToServer("192.168.1.2", 8000, "GET website/pixelinfo_horizontal.txt");
  //readResponse(1);

  //setupLEDTest();

  // show movie as setup
  int frameLength = 25;
  int frames = 10;
  for (int i = 0; i < frames*frameLength; i++) {
    if (i % frameLength == 0) {
      loadNextMovieFrame();
    }
    if ((i+1) % frameLength*4 == 0) {
      writeText("Penis",0);
    }
    drawLedScreen();  
  }
  //writeText("Howdy");
  setLongText("01234567890107012345678901070123456789010701234567890107012345678901070123456789010701234567890107012345678901070123456789010701234567890107lollollol");
}

// %%%%%%%%%%%%%%%%%%%%%

// main loop of the program

int counter = 0;

void loop() {
  drawLedScreen();
  counter++;
  if (counter % 25 == 0) {
    shiftLongTextLeft();
  }
  if (counter % 200 == 0) {
    serverLoop();
  }
  
}

// %%%%%%%%%%%%%%%%%%%%%
