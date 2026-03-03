#include <stdio.h>
#include <string.h>

void hanten(char txt[]){
    for(int i=strlen(txt);i>=0;i--){
        printf("%c", txt[i]);
    }
    printf("\n");
}

int main(void){
    char *text;
    scanf("%s",text);

    hanten(text);
}