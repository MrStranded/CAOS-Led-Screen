// -----------------------------------------------------------------------------
//
// In this file you will find methods to control the hardware related side
// of the screen control.
//
// -----------------------------------------------------------------------------

// %%%%%%%%%%%%%%%%%%%%%

// PIN CONSTANTS FOR LED MATRIX
// 0/1 can't be used due to serial issues
// 4 is used for SD card reader
// 10-14 are used by SPI (ethernet)

// pins connected to rows of LED matrix
int rowPin[8] = {A5,A4,2,3,A0,5,6,7};
// Shift register (74HC595) pins
//Pin connected to ST_CP
int latchPin = A1;
//Pin connected to SH_CP
int clockPin = 8;
////Pin connected to DS
int dataPin = 9;

// data array for shiftregisters
// holds data for led row in 6 bytes in ascending order
byte data[6];

// %%%%%%%%%%%%%%%%%%%%%

// initialize LED matrix
// set all LEDs to LOW
void initLedScreen() {
  for (int i=0; i<8; i++) {
    pinMode(rowPin[i], OUTPUT);
    digitalWrite(rowPin[i], LOW); // initialize output for column pins
  }
  pinMode(dataPin, OUTPUT);
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
}

// %%%%%%%%%%%%%%%%%%%%%

// draws the screen row by row
void drawLedScreen() {
  // for each row
  for (int r = 0; r < 8; r++) {
    // get data
    fillRow(data, r);

    // ground latchPin while transmitting data
    // and disable output
    digitalWrite(latchPin, LOW);
    
    // shift out 6 bytes of data
    for (int i = 5; i >= 0; i--) {
      shiftOut(data[i]);
    }
    
    // latchpin no longer needs to listen for information
    // set shift register output to shifted data
    digitalWrite(latchPin, HIGH);
    // wait for rest charge at register output to go away
    delayMicroseconds(50);
    // set current row to high
    digitalWrite(rowPin[r], HIGH);

    // display current row [ms]
    delay(1);

    // diable rowPin
    digitalWrite(rowPin[r], LOW);
  }
}

// %%%%%%%%%%%%%%%%%%%%%

// shift out 8 bits in register
// clock idles low
void shiftOut(byte data) {

  // shift out each bit in reverse order so the last bit
  // will light the pin Q0 
  for (int i=7; i>=0; i--)  {
    digitalWrite(clockPin, 0);

    // compare data value to bitmap of position
    if ( data & (1<<i) ) {
      digitalWrite(dataPin, 1);
    }
    else {  
      digitalWrite(dataPin, 0);
    }

    //register shifts bits on rising edge of clock pin  
    digitalWrite(clockPin, 1);
    //zero the data pin after shift to prevent bleed through
    digitalWrite(dataPin, 0);
  }

  //stop shifting
  digitalWrite(clockPin, 0);
  digitalWrite(dataPin, 0);
}
