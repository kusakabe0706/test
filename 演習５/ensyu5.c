#include <stdio.h>

int main(void){
    int input_num = 0;
    printf("何段？");
    scanf("%d", &input_num);
    printf("--------------------\n");
    for(int i = 1; i <= input_num; i++){
        for(int j = 1; j <= i; j++){
            printf("*");
        }
        printf("\n");
    }
    return 0;
}
