#include <stdio.h>

int main(void){
    int n = 17, i;
    int f1 = 0, f2 = 1, next;
    for(i = 0;i < n; i++){
       printf("%d", f1);

       if(i < n){
        printf(",");
       }
       
       next = f1 + f2;
       f1 = f2;
       f2 = next;
    }
    printf("\n");
    return 0;
}