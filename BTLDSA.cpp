#include <stdio.h>
#include <stdlib.h>
typedef struct data{
    char ten[30];
    int namsinh;
}data;
typedef struct node{
    data thongtin;
    struct node *cha;   
    struct node *anhChiEm;
    struct node *con;
}node;
typedef struct Danhsach{
    node *first;
    node *last;
}DList;
void init(DList *l){
    l->first = NULL;
    l->last = NULL;
}
node *createNode(data thongtin){
    node *newnode = (node*)malloc(sizeof(node));
    if(newnode == NULL){
        printf("Khong du bo nho!\n");
        exit(1);
    }
    newnode->thongtin = thongtin;
    newnode->cha = NULL;
    newnode->anhChiEm = NULL;
    newnode->con = NULL;
    return newnode;
}
void addThanhvienfirst(DList &list, node* new_node){
    if(list.first == NULL){
        list.first = new_node;
        list.last = new_node;
    }else{
        new_node->con = list.first;
        list.first->cha = new_node;
        list.first = new_node;
    }
}
void insertTVfirst(DList &list, data thongtin){//Them thanh vien vao dau danh sach lien ket
    node *new_node = createNode(thongtin);
    if(new_node == NULL) return;
    else{
        addThanhvienfirst(list, new_node);
    }
}
void themThanhvien(DList &list){
    data thongtin;
    printf("Nhap ten: ");
    fflush(stdin);
    gets(thongtin.ten);
    printf("Nhap nam sinh: ");
    scanf("%d", &thongtin.namsinh);
    if(&list == NULL){
        printf("Chua co danh sach thanh vien\n");
        printf("Them thanh vien dau tien\n");
        insertTVfirst(list, thongtin);
    }else{
        insertTVfirst(list, thongtin);
    }
}
// void duyet(list *l){
//     node *temp = l->first;
//     while(temp != NULL){
//         printf("Ten: %s\n", temp->thongtin.ten);
//         printf("Nam sinh: %d\n", temp->thongtin.namsinh);
//         temp = temp->con;
//     }
// }
int main(){
    DList list;
    init(&list);
    data thongtin;
    int n;
    int choice;
    while(1){
        printf("1. Them thanh vien\n");
        printf("2. Tim va hien thi thong tin thanh vien\n");
        printf("3. Hien Danh sach thanh vien\n");
        printf("0. Thoat\n");
        int choice = 0;
        printf("Chon: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:

        }
    }
}