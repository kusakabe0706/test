#include <stdio.h>

void dv(int *ans){
    *ans *= 2;
}

int main(void){
    int a;
    scanf("%d", &a);

    dv(&a);

    printf("%d\n", a);
    return 0;
}