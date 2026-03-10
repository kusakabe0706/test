#include <stdio.h>
#include <pthread.h>
#include <stdbool.h>

//mutexとcondを初期化
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

//ワーカースレッドのid
int w_id = 0;
//終了フラグ
bool end = false;

//ワーカースレッド1
void* worker1(void* key1){
    //id取得
    int myid = *(int*) key1;
    while(1){
        //w_idを確認するためにロック
        pthread_mutex_lock(&mutex);

        //idが同じではなく、かつ終了フラグも立ってない間は待機
        while(w_id != myid && !end){
            //condを待つ。待機中は一時的にmutexを解放
            pthread_cond_wait(&cond, &mutex);
        }

        //終了フラグが立っている場合はループ抜ける
        if(end){
            pthread_mutex_unlock(&mutex);
            break;
        }

        printf("スレッド1動作中\n");
        
        //処理が終了したらロック解除
        pthread_mutex_unlock(&mutex);

        //w_idを0にして再度待ちに入る
        w_id = 0;
    }
    return NULL;
}

//ワーカースレッド2（worker1と同様）
void* worker2(void* key2){
    int myid = *(int*) key2;
    while(1){
        pthread_mutex_lock(&mutex);

        while(w_id != myid && !end){
            pthread_cond_wait(&cond, &mutex);
        }

        if(end){
            pthread_mutex_unlock(&mutex);
            break;
        }
        
        printf("スレッド2動作中\n");

        pthread_mutex_unlock(&mutex);

        w_id = 0;

    }
    return NULL;
}

int main(void){
    pthread_t w1, w2; 
    int input_num = 0, id1 = 1, id2 = 2;

    //2つのスレッド作成
    if(pthread_create(&w1, NULL, worker1, &id1) != 0){
        return 1;
    };
    if(pthread_create(&w2, NULL, worker2, &id2) != 0){
        return 1;
    };

    printf("スレッド1を動かす:1, スレッド2を動かす:2, 終了:3\n");
    
    while(1){
        scanf("%d" ,&input_num);
        //w_idを書き換える前にロック
        pthread_mutex_lock(&mutex);

        if(input_num == 1){
            w_id = 1; //ワーカースレッド1を起動
        }else if(input_num == 2){
            w_id = 2; //ワーカースレッド2を起動
        }else if(input_num == 3){
            end = true; //終了フラグを立てる
        }else{
            printf("error\n");
            w_id = 0;//該当なし
        }

        //待機中のスレッドに通知を送る
        pthread_cond_broadcast(&cond);
        //更新完了後ロック解除
        pthread_mutex_unlock(&mutex);
        //3ならメインループ終了
        if(input_num == 3){
            break;
        }
    }

    //スレッドの終了を待機
    pthread_join(w1, NULL);
    pthread_join(w2, NULL);

    //mutexとcondの破棄
    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond);

    printf("終了\n");
    return 0;
}