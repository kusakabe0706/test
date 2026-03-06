#include <stdio.h>

int main(void){
    float a, b = 0, ave = 0, count = 0;
    printf("数値を入力 0で終了\n");
    while (1)
    {
        scanf("%f", &a);
        if(a != 0){
            b += a;
            count++;
        }else if (a == 0){
            ave = b / count;
            printf("平均=%f\n", ave);
            return 0;
        }
        
    }
    
}