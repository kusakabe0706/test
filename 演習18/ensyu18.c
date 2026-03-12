#include <stdio.h>
#include <pthread.h>
#include <stdbool.h>
#include <string.h>
#include "thread.h"

//mutexとcondの宣言と初期化
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
//データ準備用フラグ
bool is_ready = false;
//コールバックが受け取った文字列の保存用
char res_arr[256] = {0};

//表示用コールバック関数
void cb(char* ans){
    //変数を触られないようにロック
    pthread_mutex_lock(&mutex);
    //thread.cから送られてきた文字列を配列にコピー
    strncpy(res_arr, ans, 255);
    //準備完了フラグ
    is_ready = true;
    //待機しているスレッドに通知
    pthread_cond_broadcast(&cond);
    //ロック解除
    pthread_mutex_unlock(&mutex);
}


int main(void){
    pthread_t thread;

    //スレッド作成
    if(pthread_create(&thread, NULL, scan_thread, (void*)cb) != 0){
        return 1;
    };

    //フラグを確認するためにロック
    pthread_mutex_lock(&mutex);

    while (!is_ready) {
        //通知が来るまで待機。待機中はmutexを一時的に解放
        pthread_cond_wait(&cond, &mutex);
    }
    //条件を満たしたらロック解除
    pthread_mutex_unlock(&mutex);
    //結果を表示
    printf("result = %s\n", res_arr);

    //スレッドの終了を待機
    pthread_join(thread, NULL);

    //mutexとcondの破棄
    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond);

    return 0;
}