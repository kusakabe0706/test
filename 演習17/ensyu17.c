#include <stdio.h>
#include <pthread.h>

void* add_thread(void* add){
    int* result = (int*) add;
    (*result)++;
    return NULL;
}

int main(void){
    pthread_t thread;
    int input_num = 0;
    printf("数値を入力\n");
    scanf("%d", &input_num);

    pthread_create(&thread, NULL, add_thread, &input_num);

    pthread_join(thread, NULL);

    printf("%d\n", input_num);

    return 0;
}