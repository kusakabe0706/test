#include <stdio.h>

void print_arr(char arr[]){
    printf("result=%s\n", arr);
}

int main(void){
    char input_arr[20];
    input_arr[0] = '\0'
    printf("文字列を入力\n");
    
    fgets(input_arr, sizeof(input_arr), stdin);
    
    print_arr(input_arr);

    return 0;
}