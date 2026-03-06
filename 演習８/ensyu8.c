#include <stdio.h>

//正負判定用
void print_pos(int a){
    printf("正の整数\n");
}

void print_neg(int a){
    printf("負の整数\n");
}

void print_zero(int a){
    printf("ZERO\n");
}

//奇数偶数判定用
void print_ev(int a){
    printf("偶数\n");
}

void print_od(int a){
    printf("奇数\n");
}

void print_z(int a){
    printf("------------\n");
}

//素数判定用
void prime(int a){
    printf("素数である\n");
}

void non_pri(int a){
    printf("素数ではない\n");
}

int main(void){
    int a;
    printf("数値を入力\n");
    scanf("%d", &a);

    //正負判定テーブル
    void (*table_1[3])(int)={
        print_pos, //0
        print_neg, //1
        print_zero //2
    };

    //奇数偶数判定テーブル
    void (*table_2[3])(int)={
        print_ev, //0
        print_od, //1
        print_z   //2
    };

    //素数判定テーブル
    void (*table_3[2])(int)={
        prime, //0
        non_pri //1
    };
    
    //正負判定
    int hantei_1 = (a > 0) ? 0 : (a < 0) ? 1 : 2;
    table_1[hantei_1](a);

    //奇数偶数判定
    int hantei_2 = (a == 0) ? 2 : (a % 2 != 0) ? 1 : 0;
    table_2[hantei_2](a);

    //素数判定
    if(a < 2){
        table_3[1](a);
        return 0;
    }
    for (int i = 2; i < a; i++){
        if(a % i == 0){ 
            table_3[1](a);
            return 0;
        }
    }
    table_3[0](a);

    return 0;
}