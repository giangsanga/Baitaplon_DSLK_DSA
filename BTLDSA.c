#include <stdio.h>
#include <stdlib.h>
typedef struct data{
    char ten[30];
    int namsinh;
}data;
struct node{
    data thongtin;
    struct node *cha;   
    struct node *chiEm;
    struct node *con;
};
typedef struct node node;
typedef struct Danhsach{
    node *first;
    node *last;
}list;
void init(list *l){
    l->first = NULL;
    l->last = NULL;
}
node *createNode(data thongtin){
    node *newnode = (node*)malloc(sizeof(node));
    if(newnode == NULL){
        printf("Khong du bo nho!\n");
        exit(EXIT_FAILURE);
    }
    newnode->thongtin = thongtin;
    newnode->cha = NULL;
    newnode->chiEm = NULL;
    newnode->con = NULL;
    return newnode;
}
void addNode(list *l, data thongtin){
    node* newnode = createNode(thongtin);//tao node moi
    if(l->first == NULL){
        l->first = newnode;
        l->last = newnode;
    }else{
        l->last->con = newnode;
        l->last = newnode;
    }
}
void duyet(list *l){
    node *temp = l->first;
    while(temp != NULL){
        printf("Ten: %s\n", temp->thongtin.ten);
        printf("Nam sinh: %d\n", temp->thongtin.namsinh);
        temp = temp->con;
    }
}
int main(){
    list giadinh;
    init(&giadinh);
    printf("Nhap so thanh vien trong gia dinh: ");
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        data thongtin;
        printf("Nhap ten thanh vien thu %d: ", i+1);
        fflush(stdin);
        gets(thongtin.ten);
        printf("Nhap nam sinh: ");
        scanf("%d", &thongtin.namsinh);
        printf("Cha cua thanh vien %s: ", thongtin.ten);
        addNode(&giadinh, thongtin);
    }
    printf("Danh sach thanh vien trong gia dinh: \n");
    duyet(&giadinh);
    return 0;    
}