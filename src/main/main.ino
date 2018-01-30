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

  // show movie as setup
  int frameLength = 3;
  int frames = 20+8+48;
  for (int i = 0; i < frames*frameLength; i++) {
    if (i % frameLength == 0) {
      loadNextMovieFrame();
    }
    drawLedScreen();  
  }
  //writeText("Howdy");
  setLongText("hi");
}

// %%%%%%%%%%%%%%%%%%%%%

// main loop of the program

int counter = 0;

void loop() {
  drawLedScreen();
  counter++;
  if (counter % 200 == 0) {
    serverLoop();
  }
  if (counter % 15 == 0) {
    shiftLongTextLeft();
  }
}

// %%%%%%%%%%%%%%%%%%%%%
