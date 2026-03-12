#ifndef HEADER_H
#define HEADER_H

#include <pthread.h>
#include <stdbool.h>
//グローバル変数の宣言
extern pthread_mutex_t mutex;
extern pthread_cond_t cond;
extern char global_arr[256];
extern bool is_ready;
//関数ポインタの宣言
extern void (*callback)(char*);
//スレッドのプロトタイプ宣言
void* scan_thread(void* arr);

#endif