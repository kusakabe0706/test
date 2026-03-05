#include <stdio.h>

int main(void){
    int a, b, ans;
    char c;

    if(scanf("%d %c %d", &a, &c, &b) != 3){
        printf("エラー\n");
        return 1;
    }

    switch (c){
        case '+':
            ans = a + b;
            break;
        case '-':
            ans = a - b;
            break;
        case '*':
            ans = a * b;
            break;
        case '/':
            if(a == 0 || b == 0){
                printf("エラー\n");
                return 1;
            }
            ans = a / b;
            break;
        default:
            printf("エラー\n");
            return 1;
    }
    printf("%d\n",ans);

    return 0;
}