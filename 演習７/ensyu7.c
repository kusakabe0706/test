/**
* @file ensyu7.c
* @brief 数値を2倍にするプログラム
*/

#include <stdio.h>

/**
* @brief 引数で受け取ったポインタの値を2倍にする
* @param[in,out] ans 2倍にしたい数値へのポインタ
*/

void dv(int *ans){
    *ans *= 2;
}

/**
* @brief メイン関数
* @details 標準入力から値を受け取り、dv関数を呼び出して結果を表示
* @return 終了ステータス
*/

int main(void){
    int a;

    scanf("%d", &a);

    dv(&a);

    printf("%d\n", a);
    return 0;
}