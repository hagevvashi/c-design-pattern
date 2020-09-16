#include <stdio.h>
#include <stdlib.h>

#define rep(i, n) for (int i = 0; i < n; i = i + 1)
#define array(N, t) (t*)calloc(N, sizeof(t))
#define ll long long
#define INF ((1LL << 62) - (1LL << 31))
#define max(p, q)((p) > (q) ? (p) : (q))
#define min(p, q)((p) < (q) ? (p) : (q))
#define swap(type, a, b) { type temp = a; a = b; b = temp; }

/**
 * ナップザック問題
 * **$n$ 個の品物があり、$i$ 番目の品物のそれぞれ重さと価値が $\rm{weight}[i], \rm{value}[i]$ となっている ($i = 0, 1, ..., n-1$)。
 * これらの品物から重さの総和が $W$ を超えないように選んだときの、価値の総和の最大値を求めよ。**
 * **【制約】**
 * **・$1 \le n \le 100$**
 * **・$\rm{weight}[i], \rm{value}[i]$ は整数**
 * **・$1 \le \rm{weight}[i], \rm{value}[i] \le 1000$**
 * **・$1 \le W \le 10000$**
 *
 * **【数値例】**
 * **1)**
 * ** $n = 6$**
 * ** $(\rm{weight},\rm{value}) = {(2,3), (1,2), (3,6), (2,1), (1,3), (5,85)}$**
 * ** $W = 9$**
 * ** 答え: 94 ((3,6), (1,3), (5,85) を選んだときが最大です)**
 */
int main() {
  int n;
  scanf("%d", &n);
  int * a;
  a = array(n, int);
  rep(i, n) {
    scanf("%d", a + i);
  }
  int * dp;
  dp = array(n + 1, int);
  dp[0] = 0;
  rep(i, n) {
    dp[i + 1] = max(dp[i], dp[i] + a[i]);
  }
  printf("%d\n", dp[n]);
  free(a);
  free(dp);
  return 0;
}
