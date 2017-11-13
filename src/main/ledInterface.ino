// -----------------------------------------------------------------------------
//
// In this file you will find methods to control the leds of the led screen.
//
// -----------------------------------------------------------------------------

#include "chars.ino"

// this array holds the data of the pixels
// each char corresponds to a column of the screen
// DO NOT access pixels[] outside of this file!

char[] pixels = new char[48];

// %%%%%%%%%%%%%%%%%%%%%

// initializes the screen

void initScreen() {
  clear();
}

// %%%%%%%%%%%%%%%%%%%%%

// writes given char into specified position on screen

void writeChar(char c, int position) {
  if (position < 0) { position = 0; }
  char[] pixelData = getPixelsFromChar(c);
  for (int i=0; i<length(pixelData); i++) {
    if (i+position < 48) {
      pixels[i + position] = pixelData[length(pixelData) - i]; // the flip is because the definition in chars.ino is backwards
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
  char mask = 1 << (y-1);

  // the & operator returns an int that is 0 everywhere, except in position y, where it has the value of the pixel
  return pixels[x] & mask;
}

// %%%%%%%%%%%%%%%%%%%%%

// clears all the pixels on the screen

void clear() {
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
  
  for (int x=0; x<48; x++) {
    pixels[x] = c;
  }
}

// %%%%%%%%%%%%%%%%%%%%%
