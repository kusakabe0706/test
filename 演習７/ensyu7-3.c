#include <stdio.h>
#include <string.h>

void reverse(char arr[]){
    for(int i = strlen(arr); i >= 0; i--){
        printf("%c", arr[i]);
    }
    printf("\n");
}

int main(void){
    char input_arr[20];
    printf("文字列を入力\n");
    fgets(input_arr, sizeof(input_arr), stdin);

    reverse(input_arr);

    return 0;
}