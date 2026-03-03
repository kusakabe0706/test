#include <stdio.h>

int main(void){
    int a;
    scanf("%d", &a);

    if (a > 0){
        printf("正の整数\n");
    }else if (a < 0){
        printf("負の整数\n");
    }else{
        printf("ZERO\n");
    }

    if (a == 0){ 
        printf("---------\n");
    }else if (a % 2 != 0){
        printf("奇数\n");
    }else{
        printf("偶数\n");
    }

    if(a < 2){
        printf("素数ではない\n");
        return 0;
    }
    for (int i = 2; i < a; i++){
        if(a % i == 0){ 
             printf("素数ではない\n");
             return 0;
         }
    }
    printf("素数である\n");
    return 0;
}
