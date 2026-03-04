#include <stdio.h>
#include <math.h>

int main(void){
    float r, ensyu, menseki;
    scanf("%f", &r);
    ensyu = r * 2 * M_PI;
    menseki = r * r * M_PI;
    printf("円周=%f\n 面積=%f\n", ensyu, menseki);
    return 0;
}