#include <stdio.h>

void txt(char t[]){
    printf("%s\n", t);
}

int main(void){
    char text[20];
    printf("文字列を入力\n");
    scanf("%s", text);
    
    txt(text);

    return 0;
}