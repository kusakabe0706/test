#include <stdio.h>
#include "func9.c"

int main(void){
    int a;
    printf("数値を入力\n");
    scanf("%d", &a);

    dv(&a);

    printf("%d\n", a);

    return 0;
}