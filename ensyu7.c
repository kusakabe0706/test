#include <stdio.h>

//値を倍にして返す関数
void dv(int *ans){
    *ans *= 2;
}

int main(void){
    int a;
    //値入力
    scanf("%d", &a);
    //関数呼び出し
    dv(&a);
    //結果表示
    printf("%d\n", a);
    return 0;
}