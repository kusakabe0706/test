#include <stdio.h>

#define MAX 1000

int main(void){
    int f1 = 0, f2 = 1, next = 0;

    while(1){
        if(f1 < MAX){
            printf("%d", f1);
            if(f2 < MAX){
                printf(",");
            }
        }else{
            break;
        }

        

        next = f1 + f2;
        f1 = f2;
        f2 = next;
    }

    printf("\n");
    return 0;
}