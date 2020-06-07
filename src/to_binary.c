#include <stdio.h>

#define ARR_MAX 1047749

/**
 * n桁目のbitが0か1か知りたい
 * 1桁目のbitは1
 *
 * count: 4だとすると 5桁
 * remainder[0]: count + 1 桁目: 5桁目 -> 1
 * remainder[1]: count 桁目    : 4桁目 -> 0
 * remainder[2]: count - 1 桁目: 3桁目 -> 1
 * remainder[3]: count - 2 桁目: 2桁目 -> 0
 *                               1桁目は必ず1
 **/
int main() {
  const short BASE = 2;
  long input_decimal;
  scanf("%ld", &input_decimal);

  // count + 1桁となる
  long count = 0;
  // count + 1桁目から2桁目までのbit(0 or 1)が入っている
  long remainder[ARR_MAX];
  long quotient = input_decimal;
  while(quotient != 1) {
    // 2^nは2で割ると2^n-1となる。
    // n回目の商を2で割った余りが1(2^0)ということは、
    // n回割り算を耐えているので、元々2^nがあったということになる
    // n回目の商を2で割った余りが0ということは、2^nはなかった
    remainder[count] = quotient % BASE;
    quotient /= BASE;
    count += 1;
  }

  char output[count + 1];

  // 1桁目は必ず1
  output[0] = '1';
  for (long i = 1; i <= count; i += 1) {
    // 2桁目から順にbit値をchar型にcastしている
    // remainder[count - 1]: 2桁目、remainder[count - 2]: 3桁目、、、
    output[i] = '0' + remainder[count - i];
  }
  output[count + 1] = '\0';

  // printf("%c\n", output[0]); // ここのコメント外すと下でも正常に'1'が出力される
  // printf("%c", output[1]);
  // printf("%c\n", output[2]);
  // for (long i = 0; i <= count; i += 1) {
  //   printf("%ld\n", i);
  //   printf("%c\n", output[count]); // 上でコメントはずさないとここではなぜか'0'が出力されてしまう
  // }
  printf("%s\n", output);

  return 0;
}
