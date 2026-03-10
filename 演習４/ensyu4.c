#include <stdio.h>

int main(void){
    int count = 0;
    float input_num = 0, total = 0, ave = 0;
    printf("数値を入力 0で終了\n");

    scanf("%f", &input_num);

    if(input_num == 0){
        printf("終了\n");
        return 0;
    }

    while (1)
    {
        if(input_num != 0){
            total += input_num;
            count++;
        }else if (input_num == 0){

            

            ave = total / count;
            printf("平均=%f\n", ave);
            return 0;
        }
        scanf("%f", &input_num);
        
    }
    
}