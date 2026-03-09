#include <stdio.h>
#include "header13.h"

int main(void) {
    int num1 = 3, num2 = 5, num3 = 7;
    int ans = 0;

    ans = add(&num1, &num2, &num3);
    
    printf("%d\n", ans);

    return 0;
}