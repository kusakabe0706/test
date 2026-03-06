#include <stdio.h>
#include "func9.c"

int main(void){
    int input_num;
    printf("数値を入力\n");
    scanf("%d", &input_num);

    double_value(&input_num);

    printf("%d\n", input_num);

    return 0;
}