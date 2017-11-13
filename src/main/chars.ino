// -----------------------------------------------------------------------------
//
// In this file you will find the methods that transform a char into a pixel shape.
//
// -----------------------------------------------------------------------------

// returns a char[5] array with the pixel data corresponding to the given char

char[] getPixelsFromChar(char c) {
  switch(c) {
    case 'a':
    return {
      0b00000000,
      0b00111111,
      0b00010001,
      0b00010001,
      0b00001110
    };
    case 'b':
    return {
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
    default:
    return {
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000
    };
  }
}

