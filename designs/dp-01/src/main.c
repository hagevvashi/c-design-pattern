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
 * 最大和問題
 *
 * n 個の整数 a[0], a[1], ..., a[n - 1] が与えられる。
 * これらの整数から何個かの整数を選んで総和をとったときの、総和の最大値を求めよ。
 * また、何も選ばない場合の総和は 0 であるものとする。
 *
 * ## 【制約】
 * * 1 ≤ n ≤ 10000
 * * −1000 ≤ a[i] ≤ 1000
 *
 * ## 【数値例】
 *
 * ### 1)
 * n = 3
 * a = (7, −6 ,9)
 *
 * #### 答え
 * 16 (7 と 9 を選べばよいです)
 *
 * ### 2)
 * n = 2
 * a = (-9, -16)
 *
 * #### 答え
 * 0 (何も選ばないのがよいです)
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
