#include <stdio.h>
#include <pthread.h>

void* add_thread(void* add){
    int* result = (int*) add;
    (*result)++;
    return NULL;
}

int main(void){
    pthread_t thread;
    int ans = 0;
    scanf("%d", &ans);

    pthread_create(&thread, NULL, add_thread, &ans);

    pthread_join(thread, NULL);

    printf("%d\n", ans);

    return 0;
}