// -----------------------------------------------------------------------------
//
// In this file you will find methods to control the hardware related side
// of the screen control.
//
// -----------------------------------------------------------------------------

// pins 1 to 8 : column 1 to 8

int columnPin[8] = {0,1,2,3,4,5,6,7};

// pin 9  : shift-register clock
// pin 11 : shift-register data
// pin 10 : shift-register latch

int shiftPinClock = 9;
int shiftPinData = 11;
int shiftPinLatch = 10;

// column of Led screen that is currently drawn

int currentScreenColumn = 0;

// %%%%%%%%%%%%%%%%%%%%%

// initializes led screen pins

void initLedScreen() {
  for (int i=0; i<8; i++) {
    pinMode(columnPin[i], OUTPUT);
    digitalWrite(columnPin[i], LOW); // set output for column pins
  }

  pinMode(shiftPinClock, OUTPUT);
  pinMode(shiftPinData, OUTPUT);
  pinMode(shiftPinLatch, OUTPUT);

  digitalWrite(shiftPinClock, LOW);
  digitalWrite(shiftPinData, LOW);
  digitalWrite(shiftPinLatch, LOW);
}

// %%%%%%%%%%%%%%%%%%%%%

// draws the screen column by column

void drawLedScreen() {
  digitalWrite(shiftPinLatch, LOW); // disable shift-register output
  digitalWrite(shiftPinData, LOW);
  digitalWrite(shiftPinClock, LOW);

  for (int x=0; x<48; x++) {
    digitalWrite(shiftPinClock, LOW); // we want to prepare the next data point

    if (getPixel(x,currentScreenColumn)) {
      digitalWrite(shiftPinData, HIGH); // the current pixel is on
    } else {
      digitalWrite(shiftPinData, LOW); // the current pixel is off
    }
    
    digitalWrite(shiftPinClock, HIGH); // we want to send the data
    //delay(10);
    digitalWrite(shiftPinData, LOW);
  }
  
  digitalWrite(shiftPinClock, LOW); // cleanup

  int previousScreenColumn = currentScreenColumn - 1; // the previous column
  if (previousScreenColumn < 0) previousScreenColumn += 8; // the previous of the lowest column is the highest column
  digitalWrite(columnPin[previousScreenColumn], LOW); // disable previous column
  
  digitalWrite(shiftPinLatch, HIGH); // enable shift-register output
  digitalWrite(columnPin[currentScreenColumn], HIGH); // enable current column
    
  currentScreenColumn = (currentScreenColumn + 1) % 8; // go to the next
}

