#include <stdio.h>
#include <pthread.h>

pthread_mutex_t mutex;

//表示用コールバック関数
void cb(char* ans){
    printf("result=%s\n", ans);
}

//入力
void* scan_thread(void* arr){
    char* scan_arr = (char*) arr;
    printf("入力待ち\n");

    //他のスレッドがこの変数に触れないようにロック
    pthread_mutex_lock(&mutex);

    //%255として配列サイズをこえた入力防止
    scanf("%255s", scan_arr);

    //処理が終わったら他のスレッドが使えるようにロック解除
    pthread_mutex_unlock(&mutex);

    return NULL;
}

int main(void){
    pthread_t thread;
    char arr[256];
    arr[0] = '\0';

    //関数ポインタの宣言と初期化
    void (*callback)(char*) = cb;
    //mutexの初期化
    pthread_mutex_init(&mutex, NULL);

    //スレッド作成
    if(pthread_create(&thread, NULL, scan_thread, arr) != 0){
        return 1;
    };

    //スレッドの終了を待機
    pthread_join(thread, NULL);

    //コールバック
    callback(arr);

    //mutexの破棄
    pthread_mutex_destroy(&mutex);

    return 0;
}