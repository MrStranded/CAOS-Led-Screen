// -----------------------------------------------------------------------------
//
// In this file you will find methods to control the leds of the led screen.
//
// -----------------------------------------------------------------------------

// %%%%%%%%%%%%%%%%%%%%%

// writes given char into specified position on screen

void writeChar(char c, int position) {
  // TODO
}

// %%%%%%%%%%%%%%%%%%%%%

// sets specified pixel of the screen to given power level
// power = 1 <=> led is on
// power = 0 <=> led is off

void setPixel(int x,int y,int power) {
  // TODO
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
  for (int x=0; x<48; x++) {
    for (int y=0; y<8; y++) {
      setPixel(x,y,power);
    }
  }
}

// %%%%%%%%%%%%%%%%%%%%%
