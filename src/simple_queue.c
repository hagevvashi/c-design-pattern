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
 * @def QUEUE_SIZE
 * @brief 待ち行列に入るデータの最大数
 */
#define QUEUE_SIZE 10
/**
 * @def SUCESS
 * @brief 成功
 */
#define SUCCESS 1
/**
 * @def FAILURE
 * @brief 失敗
 */
#define FAILURE 0
/**
 * @typedef data_t
 * @brief データ型
 */
typedef int data_t;
/**
 * @var queue_data
 * @breif 待ち行列データ本体
 */
data_t queue_data[QUEUE_SIZE];
/**
 * @var queue_head
 * @brief データ先頭
 */
int queue_head;
/**
 * @var queue_num
 * @brief データ個数
 */
int queue_num;

/**
 * @fn    enqueue
 * @brief  data_t 型の enq_data を引数にとり，それを待ち行列に追加し，戻り値として SUCCESS を返す。
 *         ただし，待ち行列が満杯であるときには追加せずに，戻り値として FAILURE を返す。
 * @param enq_data data_t
 */
int enqueue(data_t enq_data) {
  int current_size = queue_head + queue_num;
  if (current_size < QUEUE_SIZE) {
    queue_data[current_size] = enq_data;
    queue_num += 1;
    return SUCCESS;
  } else {
    return FAILURE;
  }
}

/**
 * @fn dequeue
 * @brief 待ち行列が空でない場合
 *          待ち行列からデータを一つ取り出す
 *          取り出した値を *deq_data に代入する
 *          queue_num を -1 する
 *          queue_head を +1 する
 *          SUCCESS を戻り値として返す
 *        待ち行列が空の場合
 *          FAILURE を戻り値として返す
 * @param deq_data data_t *
 */
int dequeue(data_t * deq_data) {
  if (queue_num > 0) {
    *deq_data = queue_data[queue_head];
    queue_num -= 1;
    queue_head += 1;
    return SUCCESS;
  } else {
    return FAILURE;
  }
}

int main() {
  rep(i, 12) {
    if (!enqueue(i)) {
      printf("%dをenqueueしようとして失敗したみたい\n", i);
    }
  }

  int * deq_data;
  if (dequeue(deq_data)) {
    printf("%dのdeq_dataに成功したみたい\n", *deq_data);
  }
  if (dequeue(deq_data)) {
    printf("%dのdeq_dataに成功したみたい\n", *deq_data);
  }
  if (dequeue(deq_data)) {
    printf("%dのdeq_dataに成功したみたい\n", *deq_data);
  }

  return 0;
}
