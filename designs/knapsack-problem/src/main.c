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
 * n 個の品物があり、i 番目の品物のそれぞれ重さと価値が weight[i], value[i] となっている (i = 0, 1, ..., n-1)
 * これらの品物から重さの総和が W を超えないように選んだときの、価値の総和の最大値を求めよ。
 *
 * 【制約】
 * * 1 <= n <= 100
 * * weight[i], value[i] は整数
 * * 1 <= weight[i], value[i] <= 1000
 * * 1 <= W <= 10000
 *
 * 【数値例】
 * 1)
 *   n = 6
 *   (weight,value) = {(2,3), (1,2), (3,6), (2,1), (1,3), (5,85)}
 *   W = 9
 *   答え: 94 ((3,6), (1,3), (5,85) を選んだときが最大です)
 */
int main() {
  // 入力
  int n, W;
  int *weight, *value;
  scanf("%d%d", &n, &W);
  weight = array(n, int);
  value = array(n, int);
  rep(i, n) scanf("%d%d", weight + i, value + i);

  // dp テーブルの用意
  int **dp;
  dp = (int **)malloc(n + 1);
  rep(i, n + 1) {
    int w[10010] = {0};
    dp[i] = w;
  }
  /* int mw = 0; */
  /* rep(i, n) mw += weight[i]; */
  /* rep(i, n + 1) { */
  /*   int * f; */
  /*   f = array(mw, int); */
  /*   rep(i, mw) { */
  /*     printf("i: %d, ", i); */
  /*     printf("f[i]: %d\n", f[i]); */
  /*   } */
  /*   dp[i] = f; */
  /* } */
  /* rep(i, n + 1) rep(j, mw) { */
  /*   printf("i: %d, ", i); */
  /*   printf("j: %d, ", j); */
  /*   printf("dp[i][j]: %d\n", dp[i][j]); */
  /* } */

  // rep(i, n) {printf("value[i]: %d\n", value[i]); printf("weight[i]: %d\n", weight[i]);}

  // 処理
  rep(i, n) rep(w, W + 1) {
    int current = dp[i][w];
    int next;

    if (w >= weight[i]) {
      int j = w - weight[i];
      next = max(dp[i][j] + value[i], current);
    } else {
      next = current;
    }
    dp[i + 1][w] = next;
  }

  /* rep(i, n) rep(w, W + 1) { */
  /*   printf("i: %d, ", i); */
  /*   printf("w: %d, ", w); */
  /*   printf("dp[i][w]: %d\n", dp[i][w]); */
  /* } */

  // 出力
  printf("%d\n", dp[n][W]);

  // 後処理
  free(weight);
  free(value);
  /* rep(i, n + 1) { */
  /*   free(dp[i]); */
  /* } */
  free(dp);
  return 0;
}
