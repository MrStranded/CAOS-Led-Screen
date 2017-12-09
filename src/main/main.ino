// %%%%%%%%%%%%%%%%%%%%%

// setup of the Serial port used for debugging

void setupSerial() {
  Serial.begin(9600);
  Serial.flush();
}

// main entry point of the code

void setup() {
  setupSerial();
  setupInternetConnection();
}

// %%%%%%%%%%%%%%%%%%%%%

// main loop of the program

void loop() {
  putResponseIntoLedMatrix();
  //printInternetResponse();
  
  //debugScreen();
  //while(1){}
}

// %%%%%%%%%%%%%%%%%%%%%
