// -----------------------------------------------------------------------------
//
// In this file you will find methods to control the leds of the led screen.
//
// -----------------------------------------------------------------------------

// screenWidth remembers the width of the led screen
// should normally be 48, but can differ for debbuging reasons

const int screenWidth = 60;

// defines the width of the printed chars
// does not affect the data from chars.ino, only the character distribution on the screen (default = 5)

const int characterWidth = 6;

// this array holds the data of the pixels
// each char corresponds to a column of the screen
// DO NOT access pixels[] outside of this file!

char pixels[screenWidth] = ""; // "" initializes the array with zeros

// %%%%%%%%%%%%%%%%%%%%%

// initializes the screen

void initScreen() {
  clearScreen();
}

// %%%%%%%%%%%%%%%%%%%%%

// writes given char into specified position on screen

void writeChar(char c, int position) {
  if (position < 0) { position = 0; }
  char* pixelData = getPixelsFromChar(c);
  for (int i=0; i<5; i++) {
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
  int i = 0;
  while (text[i] != 0) {
    writeCharIntoSlot(text[i],i);
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
  char pixelMask = 1 << (y-1);
  
  // columnMask is 1 everywhere, except in position y
  char columnMask = 255 - pixelMask;
  
  // pixelMask has to be multiplied with power, so it contains new value of pixel
  pixelMask = pixelMask * power;
  
  // the pixelvalue copied at every bit where pixelMask is 1 and reset at the position where pixelMask is 0 by columnMask
  pixels[x] = (pixels[x] & pixelMask) | columnMask;
}

// %%%%%%%%%%%%%%%%%%%%%

// gets the power mode of the specified pixel

int getPixel(int x,int y) {
  // mask is 0 everywhere, except in position y
  char mask = 1 << (y);

  // the & operator returns an int that is 0 everywhere, except in position y, where it has the value of the pixel
  return pixels[x] & mask;
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
        Serial.print("x");
      }
    }
    Serial.println("");
  }
}

