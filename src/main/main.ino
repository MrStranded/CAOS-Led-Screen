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
  setupSerial();
  initLedScreen();

  setAll(1);

  //connectToServer("192.168.1.2", 8000, "GET website/pixelinfo_horizontal.txt");
  //readResponse(1);
  //writeText("Penis");

  //setupLEDTest();
}

// %%%%%%%%%%%%%%%%%%%%%

// main loop of the program

void loop() {
  int counter = 0;
  int mode = 1;
  
  //loopLEDTest();
  debugScreen();

  while (1) {
    drawLedScreen();

    delay(LEDFRAMEDELAY);

    /*
    counter++;
    if (counter >= 100) {
      counter -= 100;
      mode = 1 - mode;
      setAll(mode);
    }*/
    
  }
}

// %%%%%%%%%%%%%%%%%%%%%
