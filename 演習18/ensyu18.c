#include <stdio.h>
#include <pthread.h>
#include <stdbool.h>

//mutexとcondの初期化
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

//グローバル変数の宣言と初期化
char global_arr[256] = {0};
//データ準備完了を知らせるフラグ
bool is_ready = false;


//表示用コールバック関数
void cb(char* ans){
    printf("result=%s\n", ans);
}

//ワーカースレッド
void* scan_thread(void* arr){
    printf("入力待ち\n");
    //グローバル変数に書き込み
    scanf("%255s", global_arr);

    //他のスレッドがこの変数に触れないようにロック
    pthread_mutex_lock(&mutex);
    //データが準備できたことを示す
    is_ready = true;
    //待機中のスレッドに通知を送る
    pthread_cond_broadcast(&cond);
    //処理が終わったら他のスレッドが使えるようにロック解除
    pthread_mutex_unlock(&mutex);

    return NULL;
}

int main(void){
    pthread_t thread;

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

    //スレッドで準備されたデータをコールバック
    cb(global_arr);

    //スレッドの終了を待機
    pthread_join(thread, NULL);

    //mutexとcondの破棄
    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond);

    return 0;
}