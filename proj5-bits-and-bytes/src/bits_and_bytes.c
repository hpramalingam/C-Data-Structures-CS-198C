#include <stdio.h>

void print_it() {
  // TODO
  printf("Bit operations are fun!\n");
}

void print_int() {
  // TODO
  signed int x = 10;
  signed int y = 13;
  printf("x = %d\n", x);
  printf("y = %d\n", y);
  printf("size of signed int in bytes is %d.\n", sizeof(x));
  printf("size of signed int in bites is %d.\n", sizeof(y)*8);
  printf("%d + %d = %d.\n", x, y, x+y);
}

void print_float() {
  // TODO
  float x = 10.000000;
  float y = 13.000000;
  printf("x = %f\n", x);
  printf("y = %f\n", y);
  printf("size of single float in bytes is %d.\n", sizeof(x));
  printf("size of single float in bits is %d.\n", sizeof(y)*8);
  printf("%f + %f = %f.\n", x, y, x+y);
  printf("%f + %f = %i.\n", x, y,(int) x+y); 
}

void print_char() {
  // TODO
  char c = 'C';
  char a = 65;
  char f = 'F';
  char b = 'B';
  char e = 'E'; 
  printf("c = %c\n", c);
  printf("a = %c\n", a);
  printf("%c%c%c%c%c%c%c%c\n",c,a,f,e,b,a,b,e);
  printf("number of bytes: %zu.\n", sizeof(char) * 9);
}

void packing_bytes() {
  // TODO
  unsigned char b0 = 190; 
  unsigned char b1 = 186;
  unsigned char b2 = 254;
  unsigned char b3 = 202;
  unsigned int u = 0; 

  u = b3 << 8 | b2;
  u = u << 8 | b1;
  u = u << 8 | b0;
  printf("%X\n", u); 
}

void unpacking_bytes() {
  // TODO
  unsigned int i1 = 1835098984u;
  unsigned int i2 = 1768842611u;

  char c,c1,c2,c3,c4,c5,c6,c7;

  c3 = i1;
  c2 = i1 >> 8;
  c1 = i1 >> 16;
  c = i1 >> 24;

  c7 = i2;
  c6 = i2 >> 8;
  c5 = i2 >> 16;
  c4 = i2 >> 24;
  printf("%c%c%c%c%c%c%c%c\n",c,c1,c2,c3,c4,c5,c6,c7); 
}

void print_bits() {
  // TODO
  printf("TODO\n");
}

void extracting_fields() {
  unsigned int num = 0xCAFEBABE;
  unsigned int f,f1,f2,f3,f4,f5,f6,f7,f8,f9;
  f = num >> 29;
  f1 = (num << 3) >> 28;
  f2 = (num << 7) >> 28;
  f3 = (num << 11) >> 29;
  f4 = (num << 14) >> 29;
  f5 = (num << 17) >> 28;
  f6 = (num << 21) >> 28;
  f7 = (num << 25) >> 29;
  f8 = (num << 28) >> 30;
  f9 = (num << 30) >> 30;
  printf("%d %d %d %d %d %d %d %d %d %d\n",f,f1,f2,f3,f4,f5,f6,f7,f8,f9);
}

void updating_fields() {
  unsigned int num = 17512807u;
  unsigned int num1 = 8;
  unsigned int nnum1 = 7;
  num1 = num1 << 18;
  nnum1 = ~(nnum1 << 18);

  unsigned int num2 = 17;
  unsigned int nnum2 = 14;
  num2 = num2 << 10;
  nnum2 = ~(nnum2 << 10);

  num = (num | num1) & nnum1;
  num = (num | num2) & nnum2;

  printf("%08X\n", num);
}
