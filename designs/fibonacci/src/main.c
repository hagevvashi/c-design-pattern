#include <stdio.h>
#include <stdlib.h>

#define rep(i, n) for (int i = 0; i < n; i = i + 1)
#define array(N, t) (t*)calloc(N, sizeof(t))
#define ll long long
#define INF ((1LL << 62) - (1LL << 31))
#define max(p, q)((p) > (q) ? (p) : (q))
#define min(p, q)((p) < (q) ? (p) : (q))
#define swap(type, a, b) { type temp = a; a = b; b = temp; }

int N;
int * f;

void fibo(int i) {
  if (i == N) {
    return;
  }
  f[i] = f[i - 1] + f[i - 2];
  fibo(i + 1);
}

/**
 * フィボナッチ数列を求める
 * 1,1,2,3,5,8,13
 * N: いくつ表示するか
 */
int main() {
  scanf("%d", &N);
  f = array(N, int);
  f[0] = 1;
  f[1] = 1;
  fibo(2);
  rep(i, N) {
    printf("%d,", f[i]);
  }
  puts("");
  free(f);
  return 0;
}
