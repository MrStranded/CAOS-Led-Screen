// -----------------------------------------------------------------------------
//
// In this file you will find the methods that transform a char into a pixel shape.
//
// -----------------------------------------------------------------------------

// returns the width of the character in pixels (without empty space to the sides)

int getCharacterWidth(char cIn) {
  switch(cIn) {
    case 'i':
      return 1;
  }
  return 5;
}

// %%%%%%%%%%%%%%%%%%%%%

// returns a char[5] array with the pixel data corresponding to the given char

char* getPixelsFromChar(char cIn) {
  static char c[5] = ""; // "" initializes c with zeros
  switch(cIn) {
    // &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&& lower case letters
    case 'a':
      c[0] = 0b00111000;
      c[1] = 0b00100100;
      c[2] = 0b00010100;
      c[3] = 0b00111100;
      c[4] = 0b00000000;
      break;
    case 'b':
      c[0] = 0b00111111;
      c[1] = 0b00100100;
      c[2] = 0b00100100;
      c[3] = 0b00111000;
      c[4] = 0b00000000;
      break;
    case 'c':
      c[0] = 0b00011000;
      c[1] = 0b00100100;
      c[2] = 0b00100100;
      c[3] = 0b00100100;
      c[4] = 0b00000000;
      break;
    case 'd':
      c[0] = 0b00111000;
      c[1] = 0b00100100;
      c[2] = 0b00100100;
      c[3] = 0b00111111;
      c[4] = 0b00000000;
      break;
    case 'e':
      c[0] = 0b00011100;
      c[1] = 0b00101010;
      c[2] = 0b00101010;
      c[3] = 0b00101100;
      c[4] = 0b00000000;
      break;
    case 'f':
      c[0] = 0b00001000;
      c[1] = 0b11111110;
      c[2] = 0b00001001;
      c[3] = 0b00001001;
      c[4] = 0b00000000;
      break;
    case 'g':
      c[0] = 0b00011000;
      c[1] = 0b10010100;
      c[2] = 0b10010100;
      c[3] = 0b01111100;
      c[4] = 0b00000000;
      break;
    case 'h':
      c[0] = 0b00111111;
      c[1] = 0b00000100;
      c[2] = 0b00000100;
      c[3] = 0b00111000;
      c[4] = 0b00000000;
      break;
    case 'i':
      c[0] = 0b00000000;
      c[1] = 0b00000000;
      c[2] = 0b00111101;
      c[3] = 0b00000000;
      c[4] = 0b00000000;
      break;
    case 'j':
      c[0] = 0b00000000;
      c[1] = 0b10000000;
      c[2] = 0b01111101;
      c[3] = 0b00000000;
      c[4] = 0b00000000;
      break;
    case 'k':
      c[0] = 0b00111111;
      c[1] = 0b00010000;
      c[2] = 0b00011000;
      c[3] = 0b00100100;
      c[4] = 0b00000000;
      break;
    case 'l':
      c[0] = 0b00000000;
      c[1] = 0b00111111;
      c[2] = 0b00100000;
      c[3] = 0b00000000;
      c[4] = 0b00000000;
      break;
    case 'm':
      c[0] = 0b00111100;
      c[1] = 0b00000100;
      c[2] = 0b00111100;
      c[3] = 0b00000100;
      c[4] = 0b00111000;
      break;
    case 'n':
      c[0] = 0b00111100;
      c[1] = 0b00000100;
      c[2] = 0b00000100;
      c[3] = 0b00111000;
      c[4] = 0b00000000;
      break;
    case 'o':
      c[0] = 0b00011000;
      c[1] = 0b00100100;
      c[2] = 0b00100100;
      c[3] = 0b00011000;
      c[4] = 0b00000000;
      break;
    case 'p':
      c[0] = 0b11111100;
      c[1] = 0b00100100;
      c[2] = 0b00100100;
      c[3] = 0b00011000;
      c[4] = 0b00000000;
      break;
    case 'q':
      c[0] = 0b00011000;
      c[1] = 0b00100100;
      c[2] = 0b00100100;
      c[3] = 0b11111100;
      c[4] = 0b00000000;
      break;
    case 'r':
      c[0] = 0b00111100;
      c[1] = 0b00001000;
      c[2] = 0b00000100;
      c[3] = 0b00000000;
      c[4] = 0b00000000;
      break;
    case 's':
      c[0] = 0b00000000;
      c[1] = 0b00100100;
      c[2] = 0b00101010;
      c[3] = 0b00010010;
      c[4] = 0b00000000;
      break;
    case 't':
      c[0] = 0b00000000;
      c[1] = 0b00000100;
      c[2] = 0b00111111;
      c[3] = 0b00000100;
      c[4] = 0b00000000;
      break;
    case 'u':
      c[0] = 0b00011100;
      c[1] = 0b00100000;
      c[2] = 0b00100000;
      c[3] = 0b00111100;
      c[4] = 0b00000000;
      break;
    case 'v':
      c[0] = 0b00000000;
      c[1] = 0b00011100;
      c[2] = 0b00100000;
      c[3] = 0b00011100;
      c[4] = 0b00000000;
      break;
    case 'w':
      c[0] = 0b00011100;
      c[1] = 0b00100000;
      c[2] = 0b00011100;
      c[3] = 0b00100000;
      c[4] = 0b00011100;
      break;
    case 'x':
      c[0] = 0b00100100;
      c[1] = 0b00011000;
      c[2] = 0b00011000;
      c[3] = 0b00100100;
      c[4] = 0b00000000;
      break;
    case 'y':
      c[0] = 0b10001100;
      c[1] = 0b10010000;
      c[2] = 0b10010000;
      c[3] = 0b01111100;
      c[4] = 0b00000000;
      break;
    case 'z':
      c[0] = 0b00100100;
      c[1] = 0b00110100;
      c[2] = 0b00101100;
      c[3] = 0b00100100;
      c[4] = 0b00000000;
      break;
    // &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&& upper case letters
    case 'A':
      c[0] = 0b00111100;
      c[1] = 0b00010010;
      c[2] = 0b00010001;
      c[3] = 0b00010010;
      c[4] = 0b00111100;
      break;
    case 'B':
      c[0] = 0b00111111;
      c[1] = 0b00100101;
      c[2] = 0b00100101;
      c[3] = 0b00011010;
      c[4] = 0b00000000;
      break;
    case 'C':
      c[0] = 0b00011110;
      c[1] = 0b00100001;
      c[2] = 0b00100001;
      c[3] = 0b00100001;
      c[4] = 0b00000000;
      break;
    case 'D':
      c[0] = 0b00111111;
      c[1] = 0b00100001;
      c[2] = 0b00100001;
      c[3] = 0b00011110;
      c[4] = 0b00000000;
      break;
    case 'E':
      c[0] = 0b00111111;
      c[1] = 0b00100101;
      c[2] = 0b00100101;
      c[3] = 0b00100001;
      c[4] = 0b00000000;
      break;
    case 'F':
      c[0] = 0b00111111;
      c[1] = 0b00000101;
      c[2] = 0b00000101;
      c[3] = 0b00000001;
      c[4] = 0b00000000;
      break;
    case 'G':
      c[0] = 0b00011110;
      c[1] = 0b00100001;
      c[2] = 0b00100101;
      c[3] = 0b00011101;
      c[4] = 0b00000000;
      break;
    case 'H':
      c[0] = 0b00111111;
      c[1] = 0b00000100;
      c[2] = 0b00000100;
      c[3] = 0b00111111;
      c[4] = 0b00000000;
      break;
    case 'I':
      c[0] = 0b00000000;
      c[1] = 0b00100001;
      c[2] = 0b00111111;
      c[3] = 0b00100001;
      c[4] = 0b00000000;
      break;
    case 'J':
      c[0] = 0b00110001;
      c[1] = 0b00100001;
      c[2] = 0b00011111;
      c[3] = 0b00000000;
      c[4] = 0b00000000;
      break;
    case 'K':
      c[0] = 0b00111111;
      c[1] = 0b00001100;
      c[2] = 0b00010010;
      c[3] = 0b00100001;
      c[4] = 0b00000000;
      break;
    case 'L':
      c[0] = 0b00111111;
      c[1] = 0b00100000;
      c[2] = 0b00100000;
      c[3] = 0b00100000;
      c[4] = 0b00000000;
      break;
    case 'M':
      c[0] = 0b00111111;
      c[1] = 0b00000010;
      c[2] = 0b00000100;
      c[3] = 0b00000010;
      c[4] = 0b00111111;
      break;
    case 'N':
      c[0] = 0b00111111;
      c[1] = 0b00000100;
      c[2] = 0b00001000;
      c[3] = 0b00111111;
      c[4] = 0b00000000;
      break;
    case 'O':
      c[0] = 0b00011110;
      c[1] = 0b00100001;
      c[2] = 0b00100001;
      c[3] = 0b00011110;
      c[4] = 0b00000000;
      break;
    case 'P':
      c[0] = 0b00111111;
      c[1] = 0b00001001;
      c[2] = 0b00001001;
      c[3] = 0b00000110;
      c[4] = 0b00000000;
      break;
    case 'Q':
      c[0] = 0b00011110;
      c[1] = 0b00100001;
      c[2] = 0b00101001;
      c[3] = 0b00011110;
      c[4] = 0b00100000;
      break;
    case 'R':
      c[0] = 0b00111111;
      c[1] = 0b00001101;
      c[2] = 0b00010101;
      c[3] = 0b00100010;
      c[4] = 0b00000000;
      break;
    case 'S':
      c[0] = 0b00100010;
      c[1] = 0b00100101;
      c[2] = 0b00100101;
      c[3] = 0b00011001;
      c[4] = 0b00000000;
      break;
    case 'T':
      c[0] = 0b00000001;
      c[1] = 0b00000001;
      c[2] = 0b00111111;
      c[3] = 0b00000001;
      c[4] = 0b00000001;
      break;
    case 'U':
      c[0] = 0b00011111;
      c[1] = 0b00100000;
      c[2] = 0b00010000;
      c[3] = 0b00111111;
      c[4] = 0b00000000;
      break;
    case 'V':
      c[0] = 0b00000011;
      c[1] = 0b00001100;
      c[2] = 0b00110000;
      c[3] = 0b00001100;
      c[4] = 0b00000011;
      break;
    case 'W':
      c[0] = 0b00001111;
      c[1] = 0b00110000;
      c[2] = 0b00001111;
      c[3] = 0b00110000;
      c[4] = 0b00001111;
      break;
    case 'X':
      c[0] = 0b00100001;
      c[1] = 0b00010010;
      c[2] = 0b00001100;
      c[3] = 0b00010010;
      c[4] = 0b00100001;
      break;
    case 'Y':
      c[0] = 0b00000001;
      c[1] = 0b00000010;
      c[2] = 0b00111100;
      c[3] = 0b00000010;
      c[4] = 0b00000001;
      break;
    case 'Z':
      c[0] = 0b00110001;
      c[1] = 0b00101001;
      c[2] = 0b00100101;
      c[3] = 0b00100011;
      c[4] = 0b00000000;
      break;
    // &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&& numbers
    case '0':
      c[0] = 0b00011110;
      c[1] = 0b00101001;
      c[2] = 0b00100101;
      c[3] = 0b00011110;
      c[4] = 0b00000000;
      break;
    case '1':
      c[0] = 0b00000000;
      c[1] = 0b00100010;
      c[2] = 0b00111111;
      c[3] = 0b00100000;
      c[4] = 0b00000000;
      break;
    case '2':
      c[0] = 0b00100110;
      c[1] = 0b00110001;
      c[2] = 0b00101001;
      c[3] = 0b00100110;
      c[4] = 0b00000000;
      break;
    case '3':
      c[0] = 0b00100101;
      c[1] = 0b00100101;
      c[2] = 0b00100101;
      c[3] = 0b00011010;
      c[4] = 0b00000000;
      break;
    case '4':
      c[0] = 0b00001100;
      c[1] = 0b00001010;
      c[2] = 0b00111111;
      c[3] = 0b00001000;
      c[4] = 0b00000000;
      break;
    case '5':
      c[0] = 0b00100111;
      c[1] = 0b00100101;
      c[2] = 0b00100101;
      c[3] = 0b00011001;
      c[4] = 0b00000000;
      break;
    case '6':
      c[0] = 0b00011100;
      c[1] = 0b00101010;
      c[2] = 0b00101001;
      c[3] = 0b00010000;
      c[4] = 0b00000000;
      break;
    case '7':
      c[0] = 0b00000001;
      c[1] = 0b00110001;
      c[2] = 0b00001101;
      c[3] = 0b00000011;
      c[4] = 0b00000000;
      break;
    case '8':
      c[0] = 0b00011010;
      c[1] = 0b00100101;
      c[2] = 0b00100101;
      c[3] = 0b00011010;
      c[4] = 0b00000000;
      break;
    case '9':
      c[0] = 0b00100110;
      c[1] = 0b00101001;
      c[2] = 0b00101001;
      c[3] = 0b00011110;
      c[4] = 0b00000000;
      break;
    // &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&& special characters
    case ' ':
      c[0] = 0b00000000;
      c[1] = 0b00000000;
      c[2] = 0b00000000;
      c[3] = 0b00000000;
      c[4] = 0b00000000;
      break;
    // &&&&&&&&&&&&&&&&&&& sentence structure
    case '.':
      c[0] = 0b00000000;
      c[1] = 0b00110000;
      c[2] = 0b00110000;
      c[3] = 0b00000000;
      c[4] = 0b00000000;
      break;
    case '!':
      c[0] = 0b00000000;
      c[1] = 0b11011111;
      c[2] = 0b11011111;
      c[3] = 0b00000000;
      c[4] = 0b00000000;
      break;
    case '?':
      c[0] = 0b00000010;
      c[1] = 0b00000001;
      c[2] = 0b11011001;
      c[3] = 0b00000110;
      c[4] = 0b00000000;
      break;
    case ':':
      c[0] = 0b00000000;
      c[1] = 0b00110110;
      c[2] = 0b00110110;
      c[3] = 0b00000000;
      c[4] = 0b00000000;
      break;
    case ',':
      c[0] = 0b00000000;
      c[1] = 0b01010000;
      c[2] = 0b00110000;
      c[3] = 0b00000000;
      c[4] = 0b00000000;
      break;
    case ';':
      c[0] = 0b00000000;
      c[1] = 0b01010110;
      c[2] = 0b00110110;
      c[3] = 0b00000000;
      c[4] = 0b00000000;
      break;
    case '-':
      c[0] = 0b00001000;
      c[1] = 0b00001000;
      c[2] = 0b00001000;
      c[3] = 0b00001000;
      c[4] = 0b00000000;
      break;
    case '_':
      c[0] = 0b01000000;
      c[1] = 0b01000000;
      c[2] = 0b01000000;
      c[3] = 0b01000000;
      c[4] = 0b01000000;
      break;
    // &&&&&&&&&&&&&&&&&&& brackets
    case '(':
      c[0] = 0b00000000;
      c[1] = 0b00111100;
      c[2] = 0b01000010;
      c[3] = 0b10000001;
      c[4] = 0b00000000;
      break;
    case ')':
      c[0] = 0b00000000;
      c[1] = 0b10000001;
      c[2] = 0b01000010;
      c[3] = 0b00111100;
      c[4] = 0b00000000;
      break;
    case '{':
      c[0] = 0b00000000;
      c[1] = 0b00011000;
      c[2] = 0b01111110;
      c[3] = 0b10000001;
      c[4] = 0b00000000;
      break;
    case '}':
      c[0] = 0b00000000;
      c[1] = 0b10000001;
      c[2] = 0b01111110;
      c[3] = 0b00011000;
      c[4] = 0b00000000;
      break;
    case '[':
      c[0] = 0b00000000;
      c[1] = 0b11111111;
      c[2] = 0b10000001;
      c[3] = 0b10000001;
      c[4] = 0b00000000;
      break;
    case ']':
      c[0] = 0b00000000;
      c[1] = 0b10000001;
      c[2] = 0b10000001;
      c[3] = 0b11111111;
      c[4] = 0b00000000;
      break;
    // &&&&&&&&&&&&&&&&&&& math
    case '+':
      c[0] = 0b00001000;
      c[1] = 0b00001000;
      c[2] = 0b00111110;
      c[3] = 0b00001000;
      c[4] = 0b00001000;
      break;
    case '*':
      c[0] = 0b00000000;
      c[1] = 0b00010100;
      c[2] = 0b00001000;
      c[3] = 0b00010100;
      c[4] = 0b00000000;
      break;
    case '/':
      c[0] = 0b11000000;
      c[1] = 0b00110000;
      c[2] = 0b00001100;
      c[3] = 0b00000011;
      c[4] = 0b00000000;
      break;
    case '=':
      c[0] = 0b00010100;
      c[1] = 0b00010100;
      c[2] = 0b00010100;
      c[3] = 0b00010100;
      c[4] = 0b00000000;
      break;
    case '>':
      c[0] = 0b00000000;
      c[1] = 0b00100010;
      c[2] = 0b00010100;
      c[3] = 0b00001000;
      c[4] = 0b00000000;
      break;
    case '<':
      c[0] = 0b00000000;
      c[1] = 0b00001000;
      c[2] = 0b00010100;
      c[3] = 0b00100010;
      c[4] = 0b00000000;
      break;
    // &&&&&&&&&&&&&&&&&&& other
    case '\\':
      c[0] = 0b00000011;
      c[1] = 0b00001100;
      c[2] = 0b00110000;
      c[3] = 0b11000000;
      c[4] = 0b00000000;
      break;
    case '~':
      c[0] = 0b00010000;
      c[1] = 0b00001000;
      c[2] = 0b00010000;
      c[3] = 0b00001000;
      c[4] = 0b00000000;
      break;
    case '#':
      c[0] = 0b00100100;
      c[1] = 0b01111110;
      c[2] = 0b00100100;
      c[3] = 0b01111110;
      c[4] = 0b00100100;
      break;
    // &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&& default
    default:
      c[0] = 0b11111111;
      c[1] = 0b10000001;
      c[2] = 0b10000001;
      c[3] = 0b10000001;
      c[4] = 0b11111111;
      break;
  }
  return c;
}

