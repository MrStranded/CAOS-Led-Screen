// -----------------------------------------------------------------------------
//
// In this file you will find methods to control the leds of the led screen.
//
// -----------------------------------------------------------------------------

// screenWidth remembers the width of the led screen
// should normally be 48, but can differ for debbuging reasons

const int screenWidth = 48;

// defines the width of the printed chars
// does not affect the data from chars.ino, only the character distribution on the screen (default = 5)

const int characterWidth = 5; // should not be necessary anymore (see chars.ino getCharacterWidth)

// this array holds the data of the pixels
// each char corresponds to a column of the screen
// DO NOT access pixels[] outside of this file!

char pixels[screenWidth] = ""; // "" initializes the array with zeros

// remembers the current frame in the movie

int movieFrame = 0;

// %%%%%%%%%%%%%%%%%%%%%

// initializes the screen

void initScreen() {
  clearScreen();
}

// %%%%%%%%%%%%%%%%%%%%%

// loads next frame into pixels array

void loadNextMovieFrame() {
  fillNextFrame(pixels,movieFrame);
  movieFrame++;
}

// %%%%%%%%%%%%%%%%%%%%%

// this method requires the pointer to a byte array with length 6 and the number of the row that's being requested
// it then fills the array with the bits from the requested row

byte fillRow(byte *rowBytes, int row) {
  for (int b=0; b<6; b++) { // b counts in which byte we want to put the pixel data
    rowBytes[b] = 0; // clear byte
    
  
    for (int i=0; i<8; i++) { // i counts the current bit that we're interested in
      int x = b*8 + i; // x is the coordinate of the pixel we want

      int power = getPixel(x,7-row);
      power = power<<(7-i); // we have to shift the data

      rowBytes[b] = rowBytes[b] | power; // this adds a 1 or 0 into the current slot
    }
  }
}

// %%%%%%%%%%%%%%%%%%%%%

// shifts the data of the whole screen to the left

void shiftTextLeft() {
  char firstRow = pixels[0];
  
  for (int x=0; x<screenWidth-1; x++) {
    pixels[x] = pixels[x+1];
  }

  pixels[screenWidth-1] = firstRow; // feed the data from the front back in in the back
}

// %%%%%%%%%%%%%%%%%%%%%

// writes given char into specified position on screen

void writeChar(char c, int position) {
  if (position < 0) { position = 0; }
  char* pixelData = getPixelsFromChar(c);
  int width = getCharacterWidth(c);
  
  for (int i=0; i<width; i++) {
    if (i+position < screenWidth) {
      pixels[i + position] = pixelData[i]; // the flip is because the definition in chars.ino is backwards
    }
  }
}

// %%%%%%%%%%%%%%%%%%%%%

// writes given char into specified slot. Every characterWidth columns represent one slot

void writeCharIntoSlot(char c, int slot) {
  writeChar(c,slot * characterWidth);
}

// %%%%%%%%%%%%%%%%%%%%%

// writes text into the led screen, beginning from the left

void writeText(char* text) {
  //setAll(0);
  int pos = 0;
  int i = 0;
  while (text[i] != 0) {
    writeChar(text[i],pos);
    pos += getCharacterWidth(text[i]) + 1; // + 1 is for the space between letters
    i++;
  }
}

// %%%%%%%%%%%%%%%%%%%%%

// puts the given data into the screen exactly as it is

void putChars(char* data, int length) {
  for (int i=0; i<length; i++) {
    if (i < screenWidth) {
      pixels[i] = data[i];
    }
  }
}

// %%%%%%%%%%%%%%%%%%%%%

// sets specified pixel of the screen to given power level
// power = 1 <=> led is on
// power = 0 <=> led is off

void setPixel(int x,int y,int power) {
  // pixelMask is 0 everywhere, except in position y
  char pixelMask = 1 << (y);
  
  // columnMask is 1 everywhere, except in position y
  char columnMask = 255 - pixelMask;
  
  // pixelMask has to be multiplied with power, so it contains new value of pixel
  pixelMask = pixelMask * power;

  // the pixelvalue copied at every bit where pixelMask is 1 and reset at the position where pixelMask is 0 by columnMask
  pixels[x] = pixelMask | (pixels[x] & columnMask);
}

// %%%%%%%%%%%%%%%%%%%%%

// gets the power mode of the specified pixel

int getPixel(int x,int y) {
  // mask is 0 everywhere, except in position y
  char mask = 1 << (y);

  // the & operator returns an int that is 0 everywhere, except in position y, where it has the value of the pixel
  return (pixels[x] & mask) != 0;
}

// %%%%%%%%%%%%%%%%%%%%%

// clears all the pixels on the screen

void clearScreen() {
  setAll(0);
}

// %%%%%%%%%%%%%%%%%%%%%

// sets all pixels of the screen to given power level
// power = 1 <=> leds are on
// power = 0 <=> leds are off

void setAll(int power) {
  // c = 0000 0000
  char c = 0;
  
  // c = 1111 1111
  if (power == 1) { c = 255; }
  
  for (int x=0; x<screenWidth; x++) {
    pixels[x] = c;
  }
}

// %%%%%%%%%%%%%%%%%%%%%

// used to debug the char array information

void debugScreen() {
  for (int y=0; y<8; y++) {
    for (int x=0; x<screenWidth; x++) {
      int power = getPixel(x,y);
      if (power == 0) {
        Serial.print(".");
      } else {
        Serial.print("#");
      }
    }
    Serial.println("");
  }
}

