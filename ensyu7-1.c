#include <stdio.h>

void change(int *c, int *d){
    int tmp;
    tmp=*c;
    *c=*d;
    *d=tmp;
}

int main(void){
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d → %d\n", a, b);

    change(&a, &b);

    printf("%d → %d\n", a, b);
    return 0;
}  