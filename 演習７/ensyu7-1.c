#include <stdio.h>

void change(int *t1, int *t2){
    int temp;
    temp=*t1;
    *t1=*t2;
    *t2=temp;
}

int main(void){
    int input_num1, input_num2;
    printf("数値を入力\n");
    scanf("%d %d", &input_num1, &input_num2);
    printf("%d → %d\n", input_num1, input_num2);

    change(&input_num1, &input_num2);

    printf("%d → %d\n", input_num1, input_num2);
    return 0;
}  