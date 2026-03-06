#include <stdio.h>
#include <math.h>

int main(void){
    float r = 0, circumference = 0, area = 0;
    printf("円の半径を入力\n");
    scanf("%f", &r);
    circumference = r * 2 * M_PI;
    area = r * r * M_PI;
    printf("円周=%f\n 面積=%f\n", circumference, area);
    return 0;
}