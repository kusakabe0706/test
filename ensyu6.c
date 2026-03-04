#include <stdio.h>

int main(void){
    int a[17], i;
    a[0] = 0;
    a[1] = 1;
    for(i=0;i<2;i++){
        printf("%d, ", a[i]);
    }
    for(i = 2; i < 17; i++){
        a[i] = a[i-1] + a[i-2];
        printf("%d, ", a[i]);
    }
    printf("\n");
    return 0;
}