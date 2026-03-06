#include <stdio.h>

int main(void){
    int input_num1 = 0, input_num2 = 0, ans = 0;
    char operator;

    if(scanf("%d %c %d", &input_num1, &operator, &input_num2) != 3){
        printf("エラー\n");
        return 1;
    }

    switch (operator){
        case '+':
            ans = input_num1 + input_num2;
            break;
        case '-':
            ans = input_num1 - input_num2;
            break;
        case '*':
            ans = input_num1 * input_num2;
            break;
        case '/':
            if(input_num1 == 0 || input_num2 == 0){
                printf("0では割れません\n");
                return 1;
            }
            ans = input_num1 / input_num2;
            break;
        default:
            printf("エラー\n");
            return 1;
    }
    printf("%d\n",ans);

    return 0;
}