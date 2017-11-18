// %%%%%%%%%%%%%%%%%%%%%

// main entry point of the code

void setup() {
  Serial.begin(9600);
  Serial.println("led screen output:");
}

// %%%%%%%%%%%%%%%%%%%%%

// main loop of the program

void loop() {

  initScreen();

  writeText("HALLO WELT");

  debugScreen();

  // ending the programm
  while(1) {}
}

// %%%%%%%%%%%%%%%%%%%%%
