#include <stdio.h>

int main(void){
    int input_num = 0;
    scanf("%d", &input_num);

    if (input_num > 0){
        printf("正の整数\n");
    }else if (input_num < 0){
        printf("負の整数\n");
    }else{
        printf("ZERO\n");
    }

    if (input_num == 0){ 
        printf("----------\n");
    }else if (input_num % 2 != 0){
        printf("奇数\n");
    }else{
        printf("偶数\n");
    }

    if(input_num < 2){
        printf("素数ではない\n");
        return 0;
    }
    for (int i = 2; i < input_num; i++){
        if(input_num % i == 0){ 
             printf("素数ではない\n");
             return 0;
         }
    }
    printf("素数である\n");
    return 0;
}
