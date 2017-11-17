// -----------------------------------------------------------------------------
//
// In this file you will find the methods that transform a char into a pixel shape.
//
// -----------------------------------------------------------------------------

// returns a char[5] array with the pixel data corresponding to the given char

char* getPixelsFromChar(char cIn) {
  static char c[5] = ""; // "" initializes c with zeros
  switch(cIn) {
    case 'a':
      c[0] = 0b00000000;
      c[1] = 0b00111111;
      c[2] = 0b00010001;
      c[3] = 0b00010001;
      c[4] = 0b00001110;
      break;
    /*
    case 'b':
    v{
      0b00000000,
      0b00001110,
      0b00010001,
      0b00010001,
      0b11111111
    };
    case 'c':
    return {
      0b00000000,
      0b00010001,
      0b00010001,
      0b00010001,
      0b00001110
    };
    case 'd':
    return {
      0b00000000,
      0b11111111,
      0b00010001,
      0b00010001,
      0b00001110
    };
    case 'e':
    return {
      0b00000000,
      0b00001101,
      0b00010101,
      0b00010101,
      0b00001110
    };
    case 'f':
    return {
      0b00000000,
      0b10000000,
      0b10010000,
      0b01111111,
      0b00010000
    };
    case 'g':
    return {
      0b00000000,
      0b00011110,
      0b00100101,
      0b00100101,
      0b00011010
    };
    case 'h':
    return {
      0b00000000,
      0b00001111,
      0b00010000,
      0b00010000,
      0b11111111
    };
    */
    default:
      c[0] = 0b00000110;
      c[1] = 0b01111001;
      c[2] = 0b10100001;
      c[3] = 0b01111001;
      c[4] = 0b00000110;
      break;
  }
  return c;
}

