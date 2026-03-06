#include <stdio.h>
#include <pthread.h>

void cb(char* ans){
    printf("result=%s\n", ans);
}


void* scan_thread(void* arr){
    char* scan_arr = (char*) arr;
    printf("入力待ち\n");

    scanf("%s", scan_arr);

    return NULL;
}

int main(void){
    pthread_t thread;
    char arr[256];

    void (*callback)(char*) = cb;

    pthread_create(&thread, NULL, scan_thread, arr);

    pthread_join(thread, NULL);

    callback(arr);

    return 0;
}