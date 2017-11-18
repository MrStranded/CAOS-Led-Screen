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

  writeText("    ~~~~~~~~~");

  char c[15] = {
    0b01100110,
    0b10011001,
    0b10011001,
    0b10011001,
    0b10011001,
    0b01100110,
    0b00100100,
    0b00100100,
    0b00100100,
    0b00100100,
    0b00100100,
    0b00111100,
    0b00100100,
    0b00100100,
    0b00011000
  };

  putChars(c,15);

  debugScreen();

  // ending the programm
  while(1) {}
}

// %%%%%%%%%%%%%%%%%%%%%
