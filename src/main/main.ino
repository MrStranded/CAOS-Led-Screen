// %%%%%%%%%%%%%%%%%%%%%

// setup of the Serial port used for debugging

void setupSerial() {
  Serial.begin(9600);
  Serial.flush();
}

// main entry point of the code

void setup() {
  setupINTERNETTest();
}

// %%%%%%%%%%%%%%%%%%%%%

// main loop of the program

void loop() {
  loopINTERNETTest();
}

// %%%%%%%%%%%%%%%%%%%%%
