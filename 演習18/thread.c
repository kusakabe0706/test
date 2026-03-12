//ワーカースレッド
#include <stdio.h>
#include "header.h"

//グローバル変数の宣言と初期化
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
char global_arr[256] = {0};
//データ準備完了を知らせるフラグ
bool is_ready = false;
//コールバック関数を保持する変数
void (*callback)(char*) = NULL;

//ワーカースレッド
void* scan_thread(void* arr){
    printf("入力待ち\n");
    //グローバル変数に書き込み
    scanf("%255s", global_arr);

    //他のスレッドがこの変数に触れないようにロック
    pthread_mutex_lock(&mutex);
    //データが準備できたことを示す
    is_ready = true;
    //メイン側で登録された関数があれば実行
    if (callback != NULL) {
        callback(global_arr);
    }
    //待機中のスレッドに通知を送る
    pthread_cond_broadcast(&cond);
    //処理が終わったら他のスレッドが使えるようにロック解除
    pthread_mutex_unlock(&mutex);

    return NULL;
}