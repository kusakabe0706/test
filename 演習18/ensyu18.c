#include <stdio.h>
#include <pthread.h>
#include "header.h"


//表示用コールバック関数
void cb(char* ans){
    printf("result=%s\n", ans);
}


int main(void){
    pthread_t thread;
    //header.hで宣言された関数ポインタにcbを代入
    callback = cb;

    //スレッド作成
    if(pthread_create(&thread, NULL, scan_thread, NULL) != 0){
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


    //スレッドの終了を待機
    pthread_join(thread, NULL);

    //mutexとcondの破棄
    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond);

    return 0;
}