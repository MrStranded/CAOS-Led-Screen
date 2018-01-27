// -----------------------------------------------------------------------------
//
// In this file you will find methods to control the hardware related side
// of the screen control.
//
// -----------------------------------------------------------------------------

#include <SPI.h>

// pins 1 to 8 : row 1 to 8
int rowPin[8] = {A5,A4,2,3,A0,5,6,7};

//Pin connected to ST_CP of 74HC595
int latchPin = A1;
//Pin connected to SH_CP of 74HC595
int clockPin = 8;
////Pin connected to DS of 74HC595
int dataPin = 9;

// data array for shiftregisters
byte data[6];

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

  //SPI.begin();

  data[0] = 0b10101010;
  data[1] = 0b01010101;
  data[2] = 0b10101010;
  data[3] = 0b01010101;
  data[4] = 0b10101010;
  data[5] = 0b01010101;
}

// %%%%%%%%%%%%%%%%%%%%%

// draws the screen row by row

void drawLedScreen() {
  // for each row
  for (int r = 0; r < 8; r++) {
    // ground latchPin while transmitting data
    digitalWrite(latchPin, LOW); // disable shift-register output
    // delete registers
    digitalWrite(dataPin, LOW);
    digitalWrite(clockPin, LOW);
    
    // get data
    fillRow(data, r);
    
    // shift out 6 bytes of data
    for (int i = 5; i >= 0; i--) {
      //SPI.transfer(data[i]);
      shiftOut(data[i]);
    }
    
    // set current row to high
    digitalWrite(rowPin[r], HIGH);
    // latchpin no longer needs to listen for information
    digitalWrite(latchPin, HIGH);
    // display current frame [ms]
    delay(1);
    digitalWrite(rowPin[r], LOW);
  }
}



void shiftOut(byte data) {
  // This shifts 8 bits out MSB first, 
  //on the rising edge of the clock,
  //clock idles low

  //internal function setup
  int i=0;
  int pinState;
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);

  //for each bit in the byte myDataOut�
  //NOTICE THAT WE ARE COUNTING DOWN in our for loop
  //This means that %00000001 or "1" will go through such
  //that it will be pin Q0 that lights. 
  for (i=7; i>=0; i--)  {
    digitalWrite(clockPin, 0);

    //if the value passed to myDataOut and a bitmask result 
    // true then... so if we are at i=6 and our value is
    // %11010100 it would the code compares it to %01000000 
    // and proceeds to set pinState to 1.
    if ( data & (1<<i) ) {
      pinState= 1;
    }
    else {  
      pinState= 0;
    }

    //Sets the pin to HIGH or LOW depending on pinState
    digitalWrite(dataPin, pinState);
    //register shifts bits on upstroke of clock pin  
    digitalWrite(clockPin, 1);
    //zero the data pin after shift to prevent bleed through
    digitalWrite(dataPin, 0);
  }

  //stop shifting
  digitalWrite(clockPin, 0);
}
