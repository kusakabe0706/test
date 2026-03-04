#include <stdio.h>

int func(int a){
    printf("func%d\n", a);
    return 0;
}

int main(void){

    int (*p)(int)=func;
    p(1);
    func(5);
}