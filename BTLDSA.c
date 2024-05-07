#include <stdio.h>
typedef struct node{
    char ten[30];
    int namsinh;
    int *cha;   
    int *pre_chiEm;
    int *next_chiEm;
    int *pre_con;
    int *next_con;
    nguoi *link;
}nguoi;
typedef struct Danhsach{
    nguoi *first;
    nguoi *last;
}list;
void init(list *l){
    l->first = NULL;
    l->last = NULL;
}

int main(){
    
}