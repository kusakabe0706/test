#include <stdio.h>

int main(void){
    int asterisk = 0;
    printf("何段？");
    scanf("%d", &asterisk);
    printf("--------------------\n");
    for(int i = 1; i <= asterisk; i++){
        for(int j = 1; j <= i; j++){
            printf("*");
        }
        printf("\n");
    }
    return 0;
}
