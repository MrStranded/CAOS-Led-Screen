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

  int p;
  
  // M
  p = 14;
  // left pillar
  invertPixel(p,1);
  invertPixel(p,2);
  invertPixel(p,3);
  invertPixel(p,4);
  invertPixel(p,5);
  invertPixel(p,6);
  // middle
  invertPixel(p+1,2);
  invertPixel(p+2,3);
  invertPixel(p+3,2);
  // right pillar
  invertPixel(p+4,1);
  invertPixel(p+4,2);
  invertPixel(p+4,3);
  invertPixel(p+4,4);
  invertPixel(p+4,5);
  invertPixel(p+4,6);
  
  // L
  p = 20;
  // pillar
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
  // bottom
  invertPixel(p+2,6);
  invertPixel(p+3,6);
  invertPixel(p+4,6);
  invertPixel(p+2,5);
  invertPixel(p+3,5);
  invertPixel(p+4,5);
  
  // M
  p = 26;
  // left pillar
  invertPixel(p,1);
  invertPixel(p,2);
  invertPixel(p,3);
  invertPixel(p,4);
  invertPixel(p,5);
  invertPixel(p,6);
  // middle
  invertPixel(p+1,2);
  invertPixel(p+2,3);
  invertPixel(p+3,2);
  // right pillar
  invertPixel(p+4,1);
  invertPixel(p+4,2);
  invertPixel(p+4,3);
  invertPixel(p+4,4);
  invertPixel(p+4,5);
  invertPixel(p+4,6);
  
}

void invertPixel(int x,int y) {
  setPixel(x,y,1-getPixel(x,y));
}

