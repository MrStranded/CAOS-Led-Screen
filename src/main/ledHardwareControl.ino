// -----------------------------------------------------------------------------
//
// In this file you will find methods to control the hardware related side
// of the screen control.
//
// -----------------------------------------------------------------------------

// pins 1 to 8 : column 1 to 8

int rowPin[8] = {0,1,2,3,4,5,6,7};

//Pin connected to ST_CP of 74HC595
int latchPin = 10;
//Pin connected to SH_CP of 74HC595
int clockPin = 13;
////Pin connected to DS of 74HC595
int dataPin = 11;

// data array for shiftregisters
byte data[6];

// column of Led screen that is currently drawn
int currentScreenRow = 0;

// %%%%%%%%%%%%%%%%%%%%%

// initializes led screen pins

void initLedScreen() {
  for (int i=0; i<8; i++) {
    pinMode(rowPin[i], OUTPUT);
    digitalWrite(rowPin[i], LOW); // initialize output for column pins
  }
  pinMode(dataPin, OUTPUT);
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);

  SPI.begin();
}

// %%%%%%%%%%%%%%%%%%%%%

// draws the screen row by row

void drawLedScreen() {
  // for each row
  for (int r = 0; r < 8; r++) {
    
    // ground latchPin while transmitting data
    digitalWrite(latchPin, LOW); // disable shift-register output
    // deactivate last row
    digitalWrite(rowPin[(r-1)%8], LOW); 
    // delete registers
    digitalWrite(dataPin, LOW);
    digitalWrite(clockPin, LOW);
    
    // get data
    fillRow(data, r);
    
    // shift out 6 bytes of data
    for (int i = 5; i >= 0; i--) {
      SPI.transfer(data[i]);
      // shiftOut(dataPin, clockPin, data[i]);
    }
    
    // set current row to high
    digitalWrite(rowPin[r], HIGH);
    // latchpin no longer needs to listen for information
    digitalWrite(latchPin, HIGH);
    
    // hold current state for x ms
    delay(10);
  }
}
