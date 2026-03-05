#include <stdio.h>
#include <pthread.h>

void* add_thread(void* a){
    int* c = (int*) a;
    (*c)++;
    return NULL;
}

int main(void){
    pthread_t thread;
    int b;
    scanf("%d", &b);

    pthread_create(&thread, NULL, add_thread, &b);

    pthread_join(thread, NULL);

    printf("%d\n", b);

    return 0;
}