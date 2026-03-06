#include <stdio.h>

void print_arr(char arr[]){
    printf("result=%s\n", arr);
}

int main(void){
    char input_arr[20];
    printf("文字列を入力\n");
    scanf("%s", input_arr);
    
    print_arr(input_arr);

    return 0;
}