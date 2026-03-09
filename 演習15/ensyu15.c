#include <stdio.h>
#include <string.h>

#define NUM 6

//構造体の定義
typedef struct {
    char name[20];
    int score;
}member;

//順番入れ替え
void swap(member *x, member *y){
    member temp = *x;
    *x = *y;
    *y = temp;
}

//名前順に並び替え
void sort_name(menber data[], int n){
    int i = 0, j = 0;
    //順番を確定させる位置をずらす
    for(i = 0; i < n; i++){
        //隣り合う要素を比較
        for(j = n-1; j > i; j--){
            //文字列をstrcmpで比較し、前の人が後ろの人より要素が大きい場合に入れ替え
            if(strcmp(data[j-1].name, data[j].name) > 0){
                swap(&data[j-1], &data[j]);
            }
        }
    }
}

//成績順に並び替え
void sort_score(member data[], int n){
    int i = 0, j = 0;
    //順番を確定させる位置をずらす
    for(i = 0; i < n; i++){
        //隣り合う要素を比較
        for(j = n-1; j > i; j--){
            //前の成績が後ろの成績より低い場合に入れ替え
            if(data[j-1].score < data[j].score){ 
                swap(&data[j-1], &data[j]);
            }
        }
    }
}

int main(void){
    //初期化
    member data[NUM] = {
        {"sara", 88},
        {"gintonic", 12},
        {"aida", 44},
        {"yankoro", 35},
        {"kumazaki", 44},
        {"onizuka", 93},
    };

    int i = 0;

    //名前順にソート
    printf("名前順\n");
    sort_name(data, NUM);
    for(i = 0; i < NUM; i++){
        //表示
        printf("%s:%d\n", data[i].name, data[i].score);
    }

    //成績順にソート
    printf("成績順\n");
    sort_score(data, NUM);
    for(i = 0; i < NUM; i++){
        //表示
        printf("%s:%d\n", data[i].name, data[i].score);
    }

    return 0;
}

