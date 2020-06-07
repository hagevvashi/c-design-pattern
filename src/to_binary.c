#include <stdio.h>

#define ARR_MAX 10010// 1047749

int main() {
  const short BASE = 2;
  long input_decimal;
  scanf("%ld", &input_decimal);

  long count = 0;
  long remainder[ARR_MAX];
  long quotient = input_decimal;
  while(quotient != 1) {
    remainder[count] = quotient % BASE;
    quotient /= BASE;
    count += 1;
  }

  char output[count + 1];

  output[0] = '1';
  for (long i = 1; i <= count; i += 1) {
    output[i] = '0' + remainder[count - i];
  }

  // printf("%c\n", output[0]); // ここのコメント外すと下でも正常に'1'が出力される
  // printf("%c", output[1]);
  // printf("%c\n", output[2]);
  /* for (long i = 0; i <= count; i += 1) { */
  /*   printf("%ld\n", i); */
  /*   printf("%c\n", output[count]); */ // 上でコメントはずさないとここではなぜか'0'が出力されてしまう
  /* } */
  printf("%s\n", output);

  return 0;
}
