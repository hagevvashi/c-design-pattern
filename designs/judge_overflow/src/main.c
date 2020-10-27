#include <stdio.h>
#include <stdlib.h>

int judge_overflow(long long * result, long long a, long long b, long long(* calc)(const long long x, const long long y)) {
  *result = calc(a, b);
  if (a > 0 && b > 0 && *result < 0) {
    return -1;
  }
  if (a < 0 && b < 0 && *result > 0) {
    return -1;
  }
  return 0;
}

long long add(long long y, long long x) {
  return x + y;
};

long long multiple(long long y, long long x) {
  return x * y;
};

int add_overflow(long long * result, int a, int b) {
  return judge_overflow(result, a, b, add);
}

int multiple_overflow(long long * result, long long a, long long b) {
  return judge_overflow(result, a, b, multiple);
}

long long pw(int a, int b) {
  long long * res = (long long *)malloc(sizeof(long long));
  *res = 1;
  for (int i = 0; i < b; i += 1) {
    int r = multiple_overflow(res, *res, a);
    if (r == -1) {
      return -1;
    }
  }
  return * res;
  free(res);
}

int main() {
  long long * res = (long long *)malloc(sizeof(long long));
  int x = 2147483640;
  int y = 10;

  int r = 0;
  r = add_overflow(res, x, y);
  puts("---- add ----");
  printf("r: %d\n", r);
  printf("res: %lld\n", *res);

  r = multiple_overflow(res, x, y);
  puts("---- multiple ----");
  printf("r: %d\n", r);
  printf("res: %lld\n", *res);

  long long pwres = 0;
  pwres = pw(3, 3);
  puts("---- power ----");
  printf("pwres: %lld\n", pwres);

  free(res);

  return 0;
}
