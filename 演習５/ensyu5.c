#include <stdio.h>

int main(void){
    int a, i, j;
    printf("何段？");
    scanf("%d", &a);
    printf("-------------\n");
    for(i = 1; i <= a; i++){
        for(j = 1; j <= i; j++){
            printf("*");
        }
        printf("\n");
    }
    return 0;
}
