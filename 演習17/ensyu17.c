#include <stdio.h>
#include <pthread.h>

pthread_mutex_t mutex;

void* add_thread(void* add){
    int* result = (int*) add;
    if(result != NULL){
        //他のスレッドがこの変数に触れないようにロック
        pthread_mutex_lock(&mutex);

        (*result)++;

        //処理が終わったら他のスレッドが使えるようにロック解除
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

int main(void){
    pthread_t thread;
    int input_num = 0;

    //mutexの初期化
    pthread_mutex_init(&mutex, NULL);

    printf("数値を入力\n");
    scanf("%d", &input_num);

    //スレッド作成
    if(pthread_create(&thread, NULL, add_thread, &input_num) != 0){
        return 1;
    };

    //スレッドの終了を待機
    pthread_join(thread, NULL);

    //結果を表示
    printf("%d\n", input_num);

    //mutexの破棄
    pthread_mutex_destroy(&mutex);

    return 0;
}