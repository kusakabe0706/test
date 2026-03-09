#include <stdio.h>

int main(void){
    //変数宣言と初期化
    int input_num1 = 0, input_num2 = 0, ans = 0;
    char operator = '\0';

    printf("計算式を入力\n");
    //入力 戻り値を確認し、３つが正しく読み込まれているか判定
    if(scanf("%d %c %d", &input_num1, &operator, &input_num2) != 3){
        printf("エラー\n");
        return 1;
    }

    //演算子を読み取り、それに応じて計算する
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
            if(input_num2 == 0){
                printf("0では割れません\n");
                return 1;
            }
            ans = input_num1 / input_num2;
            break;
        default:
            printf("エラー\n");
            return 1;
    }
    //表示
    printf("result = %d\n",ans);

    return 0;
}