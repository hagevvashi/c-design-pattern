#include <stdio.h>
#include "./lib/mypow.h"

int main() {
  const short ZERO = 48;
  const short BASE = 2;

  short digit;
  scanf("%hd", &digit);

  char input[digit];
  scanf("%s", input);

  int output = 0;

  for (short i = 0; i < digit; i += 1) {
    short int_input = (short)input[i] - ZERO;
    short exponent = digit - i - 1;

    output = output + (int_input * mypow(BASE, exponent));
  }

  printf("%d", output);
  printf("%c", '\n');

  return 0;
}
