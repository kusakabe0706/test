//ワーカースレッド
#include <stdio.h>
#include "thread.h"

//ワーカースレッド
void* scan_thread(void* arr){
    //受け取った引数を復元
    void (*callback)(char*) = (void (*)(char*))arr;

    //変数の宣言と初期化
    char local_arr[256] = {0};

    printf("入力待ち\n");
    //変数に書き込み
    scanf("%255s", local_arr);
    //データが準備できたことを示す
    //メイン側で登録された関数があれば実行
    if (callback != NULL) {
        callback(local_arr);
    }

    return NULL;
}