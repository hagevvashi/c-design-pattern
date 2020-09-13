#include <stdio.h>
#include <stdlib.h>

#define rep(i, n) for (int i = 0; i < n; i = i + 1)
#define array(N, t) (t*)calloc(N, sizeof(t))
#define ll long long
#define INF ((1LL << 62) - (1LL << 31))
#define max(p, q)((p) > (q) ? (p) : (q))
#define min(p, q)((p) < (q) ? (p) : (q))
#define swap(type, a, b) { type temp = a; a = b; b = temp; }

int n, k;
int * P;

void solve1() {
  for (int i = k; i < n; i += 1) {
    printf("%d ", P[i]);
  }
  rep(i, k) {
    printf("%d ", P[i]);
  }
  puts("");
}

void solve2() {
  rep(i, n) printf("%d ", P[(k + i) % n]);
  puts("");
}

void solve3() {
  for (int i = k; i < k + n; i += 1) {
    printf("%d ", P[i % n]);
  }
  puts("");
}

/**
 * 整数型配列 P の内容を
 *   P[k],
 *   P[k + 1],
 *   ...,
 *   P[n - 2],
 *   P[n - 1],
 *   P[0],
 *   P[1],
 *   ...,
 *   P[k - 2],
 *   P[k - 1]
 * の順番で P[k] から始めて一巡するように表示する
 *
 * [意訳]
 * 0 番目から n 番目まである配列を k から始め
 * n に到達した瞬間 0 に fallback して k-1 まで表示
 *
 * [入力例]
 * 6 3
 * 0 1 2 3 4 5
 * [出力例]
 * 3 4 5 0 1 2
 */
int main() {
  // n, k の標準入力
  scanf("%d%d", &n, &k);

  P = array(n, int);

  // P の標準入力
  rep(i, n) scanf("%d", P + i);

  // puts("////// solve1 //////");
  // solve1();
  // puts("////// solve2 //////");
  // solve2();
  // puts("////// solve3 //////");
  solve3();

  free(P);
  return 0;
}
