// %%%%%%%%%%%%%%%%%%%%%

// main entry point of the code

void setup() {
  Serial.begin(9600);
  Serial.flush();
  Serial.println("led screen output:");
}

// %%%%%%%%%%%%%%%%%%%%%

// main loop of the program

void loop() {

  initScreen();
  initInternet();

  writeText("HeloWrld");

  debugScreen();

  createConnection("https://www.continentconquest.ch/CAOS/test.txt");

  printInternetResponse();

  // ending the programm
  while(1) {}
}

// %%%%%%%%%%%%%%%%%%%%%
