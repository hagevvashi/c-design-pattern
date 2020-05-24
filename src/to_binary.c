#include <stdio.h>
#include "./lib/mypow.h"

int main() {
  const short BASE = 2;
  short input_decimal;
  scanf("%hd", &input_decimal);

  input_decimal = 10;

  // 10 に一番近い pow を探す

  mypow(BASE, 3) * 1 + mypow(BASE, 2) * 0 + mypow(BASE, 1) * 1 + mypow(BASE, 0) * 0

  char output_binary[5] = "1010";
  printf("%s", output_binary);
  printf("%c", '\n');

  return 0;
}
