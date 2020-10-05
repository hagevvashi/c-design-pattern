# knapsack problem ナップザック問題

## 問題文

n 個の品物があり、i 番目の品物のそれぞれ重さと価値が weight[i], value[i] となっている (i = 0, 1, ..., n-1)

これらの品物から重さの総和が W を超えないように選んだときの、価値の総和の最大値を求めよ。

## 【制約】

* 1 <= n <= 100
* weight[i], value[i] は整数
* 1 <= weight[i], value[i] <= 1000
* 1 <= W <= 10000

## 【数値例】

 1)

   n = 6

   (weight,value) = {(2,3), (1,2), (3,6), (2,1), (1,3), (5,85)}

   W = 9

   答え: 94 ((3,6), (1,3), (5,85) を選んだときが最大です)

## 参考

https://qiita.com/drken/items/a5e6fe22863b7992efdb#2-%E3%83%8A%E3%83%83%E3%83%97%E3%82%B5%E3%83%83%E3%82%AF%E5%95%8F%E9%A1%8C

## 解説

* dp[i + 1]: i 番目までの品物の中から「重さが W を超えないように選んだときの、価値の総和の最大値」
* dp[i + 1][w]: i 番目までの品物の中から重さが w を超えないように選んだ時の、価値の総和の最大値 (w: 0~W)

dp[2][3] が 5 であることの理由を深堀りする

0 番目: (2, 3)
1 番目: (1, 2)

dp[1]: 0 番目までの品物の中から(ry
dp[1][2] -> 3: 0 番目までの品物の中から重さが 2 を超えないように選んだ時の、価値の総和の最大値
dp[1][3] -> 3: 0 番目までの品物の中から重さが 3 を超えないように選んだ時の、価値の総和の最大値
dp[1][4] -> 3: 0 番目までの品物の中から重さが 4 を超えないように選んだ時の、価値の総和の最大値

dp[2]: 1 番目までの品物の中から(ry
dp[2][2] -> 3: 1 番目までの品物の中から重さが 2 を超えないように選んだ時の、価値の総和の最大値
dp[2][3] -> 5: 1 番目までの品物の中から重さが 3 を超えないように選んだ時の、価値の総和の最大値
dp[2][4] -> 5: 1 番目までの品物の中から重さが 4 を超えないように選んだ時の、価値の総和の最大値

i: 1, w: 4 ... weight[1]: 1, value[1]: 2

dp[i][w]: dp[1][4]: 3
dp[i][w - weight[i]]: dp[1][4 - 1]: dp[1][3]: 3
value[i]: value[1]: 2
dp[i][w - weight[i]] + value[i]: 5
max(dp[i][w - weight[i]] + value[i], dp[i][w]): max(5, 3): 5




```
dp[0][0]: 0
dp[0][1]: 0
dp[0][2]: 0
dp[0][3]: 0
dp[0][4]: 0
dp[0][5]: 0
dp[0][6]: 0
dp[0][7]: 0
dp[0][8]: 0
dp[0][9]: 0

dp[1][0]: 0
dp[1][1]: 0
dp[1][2]: 3
dp[1][3]: 3
dp[1][4]: 3
dp[1][5]: 3
dp[1][6]: 3
dp[1][7]: 3
dp[1][8]: 3
dp[1][9]: 3

dp[2][0]: 0
dp[2][1]: 2
dp[2][2]: 3
dp[2][3]: 5
dp[2][4]: 5
dp[2][5]: 5
dp[2][6]: 5
dp[2][7]: 5
dp[2][8]: 5
dp[2][9]: 5

dp[3][0]: 0
dp[3][1]: 2
dp[3][2]: 3
dp[3][3]: 6
dp[3][4]: 8
dp[3][5]: 9
dp[3][6]: 11
dp[3][7]: 11
dp[3][8]: 11
dp[3][9]: 11

dp[4][0]: 0
dp[4][1]: 2
dp[4][2]: 3
dp[4][3]: 6
dp[4][4]: 8
dp[4][5]: 9
dp[4][6]: 11
dp[4][7]: 11
dp[4][8]: 12
dp[4][9]: 12

dp[5][0]: 0
dp[5][1]: 3
dp[5][2]: 5
dp[5][3]: 6
dp[5][4]: 9
dp[5][5]: 11
dp[5][6]: 12
dp[5][7]: 14
dp[5][8]: 14
dp[5][9]: 15

dp[6][0]: 0
dp[6][1]: 3
dp[6][2]: 5
dp[6][3]: 6
dp[6][4]: 9
dp[6][5]: 85
dp[6][6]: 88
dp[6][7]: 90
dp[6][8]: 91
dp[6][9]: 94
```

  | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9
-- | -- | -- | -- | -- | -- | -- | -- | -- | -- | --
0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0
1 | 0 | 0 | 3 | 3 | 3 | 3 | 3 | 3 | 3 | 3
2 | 0 | 2 | 3 | 5 |   |   |   |   |   |  
3 |   |   |   |   |   |   |   |   |   |  
4 |   |   |   |   |   |   |   |   |   |  
5 |   |   |   |   |   |   |   |   |   |  
6 |   |   |   |   |   |   |   |   |   |  

