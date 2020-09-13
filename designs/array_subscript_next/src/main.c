#include <stdio.h>
#include <stdlib.h>

#define rep(i, n) for (int i = 0; i < n; i = i + 1)
#define array(N, t) (t*)calloc(N, sizeof(t))
#define ll long long
#define INF ((1LL << 62) - (1LL << 31))
#define max(p, q)((p) > (q) ? (p) : (q))
#define min(p, q)((p) < (q) ? (p) : (q))
#define swap(type, a, b) { type temp = a; a = b; b = temp; }

int n, k, d, e;
int * P;

void solve() {
  rep(i, e) {
    printf("%d ", P[(k + (d * i)) % n]);
  }
  puts("");
}


/**
 * 長さ n の整数型配列 P の
 *   P[k] から始めて
 *     d ごとの要素を e 個
 *       すなわち
 *         P[k + d * 0],
 *         P[k + d * 1],
 *         P[k + d * 2],
 *         P[k + d * 3],
 *         ...,
 *         P[k + d * (e - 1)]
 * を表示する
 * ただし添字は巡回的であるとする
 */
int main() {
  // n, k の標準入力
  scanf("%d%d%d%d", &n, &k, &d, &e);

  P = array(n, int);

  // P の標準入力
  rep(i, n) scanf("%d", P + i);

  solve();

  free(P);
  return 0;
}
