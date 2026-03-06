#include <stdio.h>
#include <string.h>

void hanten(char txt[]){
    for(int i = strlen(txt); i >= 0; i--){
        printf("%c", txt[i]);
    }
    printf("\n");
}

int main(void){
    char *text;
    printf("文字列を入力\n");
    scanf("%s", text);

    hanten(text);

    return 0;
}