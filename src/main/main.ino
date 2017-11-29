// %%%%%%%%%%%%%%%%%%%%%

// main entry point of the code

void setup() {
  Serial.begin(9600);
  Serial.flush();
}

// %%%%%%%%%%%%%%%%%%%%%

// main loop of the program

void loop() {

  initInternet();

  char* url = (char *) "https://www.continentconquest.ch/CAOS/test.txt";
  Serial.println("connecting to:");
  Serial.println(url);
  createConnection(url);

  printInternetResponse();

  // ending the programm
  while(1) {}
}

// %%%%%%%%%%%%%%%%%%%%%
