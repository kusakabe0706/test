#include <stdio.h>
#include "func9.c"

int main(void){
    int a;
    scanf("%d", &a);

    dv(&a);

    printf("%d\n", a);
}