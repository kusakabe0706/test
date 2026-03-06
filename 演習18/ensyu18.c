#include <stdio.h>
#include <pthread.h>

void cb(char* arr){
    printf("result=%s\n", arr);
}


void* scan_thread(void* a){
    char* b = (char*) a;
    printf("入力待ち\n");

    scanf("%s", b);

    return NULL;
}

int main(void){
    pthread_t thread;
    char c[256];

    void (*callback)(char*) = cb;

    pthread_create(&thread, NULL, scan_thread, c);

    pthread_join(thread, NULL);

    callback(c);

    return 0;
}