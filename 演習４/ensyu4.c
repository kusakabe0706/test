#include <stdio.h>

int main(void){
    float a, b = 0, ave, count = 0;
    scanf("%f", &a);
    while (1)
    {
        if(a != 0){
            b += a;
            count++;
        }else if (a == 0){
            ave = b / count;
            printf("平均=%f\n", ave);
            return 0;
        }
        scanf("%f", &a);
    }
    
}