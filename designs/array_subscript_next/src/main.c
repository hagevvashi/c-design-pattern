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
int * ans;

/**
 * d >= 0 の場合は有効
 * d < 0 の場合、P の添字は負になってしまう
 */
void solve1() {
  rep(i, e) {
    ans[i] = P[(k + (d * i)) % n];
  }
}

/**
 * d が負の場合の対応パターン 1
 * if で負かどうかの分岐をいれるだけ
 */
void solve2() {
  rep(i, e) {
    int index = (k + (d * i)) % n;
    if (index < 0) {
      index += n;
    }
    ans[i] = P[index];
  }
}

/**
 * d が負の場合の対応パターン 2
 */
void solve3() {
  rep(i, e) {
    int index = (k + (d * i)) % n;
    index += n;
    index %= n;
    ans[i] = P[index];
  }
}

/**
 * d が負の場合の対応パターン 3
 * -n <= d であるときに限る(n > d)
 */
void solve4() {
  rep(i, e) {
    int index = (k + (d + n) * i) % n;
    ans[i] = P[index];
  }
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
  ans = array(e, int);

  // P の標準入力
  rep(i, n) scanf("%d", P + i);

  solve4();

  rep(i, e) {
    printf("%d ", ans[i]);
  }
  puts("");

  free(P);
  free(ans);
  return 0;
}
