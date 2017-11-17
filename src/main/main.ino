// %%%%%%%%%%%%%%%%%%%%%

// main entry point of the code

void setup() {
  Serial.begin(9600);
  Serial.println("hallo velo.");
}

// %%%%%%%%%%%%%%%%%%%%%

// main loop of the program

void loop() {
  for (int i = 0; i< 20000; i++) {
    Serial.print("Semira liebt Michael soooooooo fest ");
    Serial.println(i);
  }
  // ending the programm
  while(1) {}
}

// %%%%%%%%%%%%%%%%%%%%%
