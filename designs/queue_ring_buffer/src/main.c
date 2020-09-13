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
 * @brief enq_data を待ち行列 queue_data に追加し
 *          (queue_num を１つ増やし)
 *        戻り値 SUCCESS を返す。
 *        ただし，待ち行列が満杯であるときには追加せずに，戻り値として FAILURE を返す。
 * @param enq_data data_t
 * @return int
 */
int enqueue(data_t enq_data) {
  int new_queue_tail = queue_head + queue_num;
  new_queue_tail %= QUEUE_SIZE;
  if (queue_num < QUEUE_SIZE) {
    queue_data[new_queue_tail] = enq_data;
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
 * @return int
 */
int dequeue(data_t * deq_data) {
  if (queue_num > 0) {
    *deq_data = queue_data[queue_head];
    queue_head += 1;
    queue_head %= QUEUE_SIZE;
    queue_num -= 1;
    return SUCCESS;
  } else {
    return FAILURE;
  }
}

/**
 * @fn print_queue
 * @brief 待ち行列の動きを見るための内容を表示する関数
 * @return void
 */
void print_queue() {
  printf("queue [");
  int queue_tail = queue_head + queue_num;
  rep(i, QUEUE_SIZE) {
    if (
        (queue_tail <= QUEUE_SIZE &&
         queue_head <= i &&
         i < queue_tail) ||
        (queue_tail > QUEUE_SIZE &&
         (queue_head <= i ||
          i < queue_tail % QUEUE_SIZE))) {
      printf("%3d", queue_data[i]);
    } else {
      printf("%3c", '.'); // queue に入っていないデータは表示しない
    }
  }
  printf("]\n");
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
