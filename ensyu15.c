#include <stdio.h>
#include <string.h>

#define NUM 6

typedef struct {
    char name[20];
    int score;
}menber;

void swap(menber *x, menber *y){
    menber temp = *x;
    *x = *y;
    *y = temp;
}

void sort_name(menber data[], int n){
    int i, j;
    for(i = 0; i < n; i++){
        for(j = n-i; j > i; j--){
            if(strcmp(data[j-1].name, data[j].name) > 0){
                swap(&data[j-1], &data[j]);
            }
        }
    }
}

void sort_score(menber data[], int n){
    int i, j;
    for(i = 0; i < n; i++){
        for(j = n-i; j > i; j--){
            if(data[j-1].score > data[j].score){
                swap(&data[j-1], &data[j]);
            }
        }
    }
}

int main(void){
    menber data[NUM] = {
        {"sara", 88},
        {"gintonic", 12},
        {"aida", 44},
        {"yankoro", 35},
        {"kumazaki", 44},
        {"onizuka", 93},
    };

    int i;

    sort_name(data, NUM);
    for(i = 0; i < NUM; i++){
        printf("%s:%d\n", data[i].name, data[i].score);
    }

    return 0;
}

