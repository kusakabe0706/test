#include <stdio.h>

void txt(char t[]){
    printf("%s\n", t);
}

int main(void){
    char text[20];
    scanf("%s", text);
    
    txt(text);

    return 0;
}