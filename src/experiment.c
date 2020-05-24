#include <stdio.h>
#include "./lib/mypow.h"

int main() {
  short a, b;
  scanf("%hd %hd", &a, &b);

  int output;
  output = mypow(a, b);
  printf("%d", output);

  return 0;
}
