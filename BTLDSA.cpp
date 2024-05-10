#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct data{
    char ten[30];
    int namsinh;
}data;
typedef struct node{
    data thongtin;
    struct node *Cha;
    struct node *anhChiEm;
    struct node *Con;
    struct node *next;
    struct node *prev;
}node;
typedef struct list{
    struct node *first;
    struct node *last;
}Dlist;
void init(Dlist &l){
    l.first = NULL;
    l.last = NULL;
}
node *CreateNode(data x){
    node *newNode = (node*)malloc(sizeof(node));
    if (newNode == NULL){
        printf("Khong du bo nho!\n");
        exit(1);
    }
    newNode->thongtin = x;
    newNode->Cha = NULL;
    newNode->anhChiEm = NULL;
    newNode->Con = NULL;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}
void AddLastNode(Dlist &l, node *newNode){
    if (l.first == NULL){
        l.first = newNode;
        l.last = newNode;
    }else{
        l.last->next = newNode;
        newNode->prev = l.last;
        l.last = newNode;
    }
}
void InsertLast(Dlist &l, data x){//Them vao cuoi danh sach
    node *newNode = CreateNode(x);
    if (newNode == NULL){
        return;
    }else{
        AddLastNode(l, newNode);
    }
}
void themThanhVien(Dlist &l){
    data x;
    printf("Nhap ten thanh vien: ");
    fflush(stdin);
    gets(x.ten);
    printf("Nhap nam sinh: ");
    scanf("%d", &x.namsinh);
    InsertLast(l, x);
}
void themCon(Dlist &l){
    data x;
    printf("Nhap ten con: ");
    fflush(stdin);
    gets(x.ten);
    printf("Nhap nam sinh: ");
    scanf("%d", &x.namsinh);
    printf("Nhap ten cha: ");
    char tenCha[30];
    fflush(stdin);
    gets(tenCha);
    node *p = l.first;
    while (p != NULL){
        if (strcmp(p->thongtin.ten, tenCha) == 0){
            node *newNode = CreateNode(x);
            InsertLast(l, x);
            newNode->Cha = p;
            if (p->Con == NULL){
                p->Con = newNode;
            }
        }
        p = p->next;
    }
}
void Display(Dlist l){
    node *p = l.first;
    while (p != NULL){
        printf("Ten: %s\n", p->thongtin.ten);
        printf("Nam sinh: %d\n", p->thongtin.namsinh);
        node *q = p->Con;
        while(q != NULL){
            printf("Con: %s\n", q->thongtin.ten);
            q = q->next;
        }
        printf("\n");
        p = p->next;
    }
}
int menu(Dlist &l){
    printf("1. Them thanh vien\n");
    printf("2. Them con\n");
    printf("3. Hien thi danh sach\n");
    printf("0. Thoat\n");
    int choice;
    int flag = 0;
    scanf("%d", &choice);
    switch(choice){
        case 1:
            themThanhVien(l);
            flag = 1;
            break;
        case 2:
            themCon(l);
            flag = 1;
            printf("\n");
            break;
        case 3:
            Display(l);
            flag = 1;
            printf("\n");
            break;
        case 0:
            flag = 0;
            break;
        default:
            flag = 1;
            break;
    }
}
int main(){
    Dlist l;
    init(l);
    while(1){
        if(menu(l) == 0) break;
    }
    return 0;
}