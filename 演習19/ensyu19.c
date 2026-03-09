#include <stdio.h>
#include <pthread.h>
#include <stdbool.h>
#include <unistd.h>

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

int w_id = 0;
bool end = false;

void* worker1(void* key1){
    int myid = *(int*) key1;
    while(1){
        pthread_mutex_lock(&mutex);

        while(w_id != myid && !end){
            pthread_cond_wait(&cond, &mutex);
        }

        if(end){
            pthread_mutex_unlock(&mutex);
            break;
        }

        printf("スレッド1動作中\n");
        pthread_mutex_unlock(&mutex);

        sleep(2); 
    }
    return NULL;
}

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

        sleep(2);
    }
    return NULL;
}

int main(void){
    pthread_t w1, w2; 
    int input_num = 0, id1 = 1, id2 = 2;

    pthread_create(&w1, NULL, worker1, &id1);
    pthread_create(&w2, NULL, worker2, &id2);

    printf("スレッド1を動かす:1, スレッド2を動かす:2, 終了:3\n");
    
    while(1){
        scanf("%d" ,&input_num);

        if(input_num == 1){
            w_id = 1;
        }else if(input_num == 2){
            w_id = 2;
        }else if(input_num == 3){
            end = true;
        }else{
            printf("error\n");
            w_id = 0;
        }

        pthread_cond_broadcast(&cond);
        pthread_mutex_unlock(&mutex);

        if(input_num == 3){
            break;
        }
    }

    pthread_join(w1, NULL);
    pthread_join(w2, NULL);

    printf("終了\n");
    return 0;
}