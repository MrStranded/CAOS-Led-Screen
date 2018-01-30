// -----------------------------------------------------------------------------
//
// In this file you will find an awesome movie!
//
// -----------------------------------------------------------------------------

void fillNextFrame(char *pixels, int frame) {
  setAll(0);
  int width = 20;
  for (int x=0; x<width; x++) {
    for (int i=0; i<8; i++) {
      setPixel(x+frame+i-width-8, i, 1);
    }
  }

  writeM(12);
  writeL(22);
  writeM(29);
}

// writes an M onto the screen

void writeM(int p) {
  // left pillar
  invertPixel(p,0);
  invertPixel(p,1);
  invertPixel(p,2);
  invertPixel(p,3);
  invertPixel(p,4);
  invertPixel(p,5);
  invertPixel(p,6);
  invertPixel(p+1,1);
  invertPixel(p+1,2);
  invertPixel(p+1,3);
  invertPixel(p+1,4);
  invertPixel(p+1,5);
  invertPixel(p+1,6);
  // middle
  invertPixel(p+2,2);
  invertPixel(p+2,3);
  invertPixel(p+3,3);
  invertPixel(p+3,4);
  invertPixel(p+4,4);
  invertPixel(p+4,5);
  invertPixel(p+5,3);
  invertPixel(p+5,4);
  invertPixel(p+6,2);
  invertPixel(p+6,3);
  // right pillar
  invertPixel(p+7,1);
  invertPixel(p+7,2);
  invertPixel(p+7,3);
  invertPixel(p+7,4);
  invertPixel(p+7,5);
  invertPixel(p+7,6);
  invertPixel(p+8,0);
  invertPixel(p+8,1);
  invertPixel(p+8,2);
  invertPixel(p+8,3);
  invertPixel(p+8,4);
  invertPixel(p+8,5);
  invertPixel(p+8,6);
}

// writes an L onto the screen

void writeL(int p) {
  // pillar
  invertPixel(p,0);
  invertPixel(p,1);
  invertPixel(p,2);
  invertPixel(p,3);
  invertPixel(p,4);
  invertPixel(p,5);
  invertPixel(p,6);
  invertPixel(p+1,0);
  invertPixel(p+1,1);
  invertPixel(p+1,2);
  invertPixel(p+1,3);
  invertPixel(p+1,4);
  invertPixel(p+1,5);
  invertPixel(p+1,6);
  // bottom
  invertPixel(p+2,6);
  invertPixel(p+2,5);
  invertPixel(p+3,6);
  invertPixel(p+3,5);
  invertPixel(p+4,6);
  invertPixel(p+4,5);
  invertPixel(p+5,6);
  invertPixel(p+5,5);
}

// inverts the pixel in the given position

void invertPixel(int x,int y) {
  setPixel(x,y,1-getPixel(x,y));
}

