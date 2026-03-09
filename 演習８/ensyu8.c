#include <stdio.h>

//正負判定用
void print_pos(int id_1) { printf("正の整数\n"); }
void print_neg(int id_1) { printf("負の整数\n"); }
void print_zero(int id_1) { printf("ZERO\n"); }

//奇数偶数判定用
void print_even(int id_2) { printf("偶数\n"); }
void print_odd(int id_2) { printf("奇数\n"); }
void print_z(int id_2) {printf("------------\n"); }

//素数判定用
void prime(int id_3) { printf("素数である\n"); }
void not_prime(int id_3) { printf("素数ではない\n"); }


int main(void){
    int input_num = 0, judge1 = 0, judge2 = 0, is_not_prime = 0;
    printf("数値を入力\n");
    scanf("%d", &input_num);

    //正負判定テーブル
    void (*table_1[3])(int)={
        print_pos, //0
        print_neg, //1
        print_zero //2
    };

    //奇数偶数判定テーブル
    void (*table_2[3])(int)={
        print_even, //0
        print_odd, //1
        print_z   //2
    };

    //素数判定テーブル
    void (*table_3[2])(int)={
        prime, //0
        not_prime //1
    };
    
    //正負判定
    if(input_num > 0){
        judge1 = 0;
    }else if (input_num < 0) {
        judge1 = 1;
    }else {
        judge1 = 2;
    }
    table_1[judge1](input_num);

    //奇数偶数判定
    if (input_num == 0) {
        judge2 = 2;
    }else if (input_num % 2 != 0) {
        judge2 = 1;
    }else {
        judge2 = 0;
    }
    table_2[judge2](input_num);

    //素数判定
    if(input_num < 2){
        is_not_prime = 1;
    }
    for (int i = 2; i < input_num; i++){
        if(input_num % i == 0){ 
            is_not_prime = 1;
        }
    }
    table_3[is_not_prime](input_num);

    return 0;
}