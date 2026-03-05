#include <stdio.h>
#include "header13.h"

int main(void) {
    int a = 3, b = 5, c = 7;
    int ans;

    ans = add(&a, &b, &c);
    
    printf("%d\n", ans);

    return 0;
}