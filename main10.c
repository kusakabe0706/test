#include <stdio.h>
#include "func10.c"

extern int global;

int main(void){
    printf("%d\n", global);
    return 0;
}