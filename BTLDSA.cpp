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
        l.last->next = newNode;//Lien ket node cuoi voi node moi
        newNode->prev = l.last;//Lien ket node moi voi node cuoi
        l.last = newNode;//Cap nhat lai node cuoi
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
void link_anhChiEm(Dlist &l);//Khai bao truoc
void themThanhVien(Dlist &l){//Them thanh vien
    data x;
    printf("Nhap ten thanh vien: ");
    fflush(stdin);
    gets(x.ten);
    printf("Nhap nam sinh: ");
    scanf("%d", &x.namsinh);
    InsertLast(l, x);
    // link_anhChiEm(l);
}
void themCon(Dlist &l){//Them con
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
        if (strcmp(p->thongtin.ten, tenCha) == 0){//Neu tim thay ten cha
            InsertLast(l, x);
            l.last->Cha = p;//Lien ket con voi cha
            if(p->Con == NULL){//Neu cha chua co con
                p->Con = l.last;//Lien ket cha voi con
                break;
            }
            break;
        }
        p = p->next;
    }
    link_anhChiEm(l);
}
void link_anhChiEm(Dlist &l){//liên kết vòng anh chị em khi cùng cha
    if(l.first == l.last) return;
    node *p = l.first;
    while (p != NULL){//Duyet qua tat ca cac thanh vien
        node *q = p->next;
        while (q != NULL){
            if (p->Cha == q->Cha && p->anhChiEm == NULL && p != q && p->Cha != NULL && q->Cha != NULL){//Neu cung cha
                p->anhChiEm = q;
                break;
            }
            q = q->next;
        }
        p = p->next;
    }
    //////////////////////////////////////////////
    p = l.last;
    while(p != NULL){//Link vong anh chi em
        node *q = l.first;
        while(q != NULL){
            if(p->Cha == q->Cha && p->anhChiEm == NULL && p != q && p->Cha != NULL && q->Cha != NULL){
                p->anhChiEm = q;//Lien ket anh chi em
                break;
            }
            q = q->next;
        }
        p = p->prev;
    }
}
void in_dia_chi_anhchiem(Dlist l){
    node *p = l.first;
    int i = 0;
    while (p != NULL){
        i++;
        printf("Dia chi cua thanh vien %d: %p\n", i, p);
        printf("Ten: %s\n", p->thongtin.ten);
        printf("Nam sinh: %d\n", p->thongtin.namsinh);
        printf("in dia chi cua cha: %p\n", p->Cha);
        printf("in dia chi cua con: %p\n", p->Con);
        printf("in dia chi cua anh chi em: %p\n", p->anhChiEm);
        printf("\n");
        p = p->next;
    }
}
void Display(Dlist l){
    node *p = l.first;
    printf("Danh sach thanh vien:\n");
    printf("|Ten\t\t      | Nam sinh      | Cha   \t\t   | Con\t\t  |\n");
    printf("----------------------------------------------------------------------------------------\n");
    while (p != NULL){//In ra danh sach thanh vien
        printf("|%-20s ", p->thongtin.ten);
        printf("|%-15d", p->thongtin.namsinh);
        printf("|%-20s|", p->Cha->thongtin.ten);//In ra ten cha
        node *q = p->next;
        //////////////////////////////////////////////
        int socon = 0;
        while(q != NULL){//In ra danh sach con cua thanh vien
            if(q->Cha == p){//Neu la con cua thanh vien
                if(socon == 0){
                    printf("%-20s  |\n", q->thongtin.ten);//In ra ten con  
                    socon++;
                }else{
                    printf("\t\t\t\t\t\t\t   |%-20s  |\n", q->thongtin.ten);//In ra ten con
                    socon++;
                }
            }
            q = q->next;//Chuyen sang con ke tiep
        }
        printf("\n----------------------------------------------------------------------------------------\n");
        p = p->next;
    }
}
void Find_tv(Dlist l){
    char ten[30];
    printf("Nhap ten thanh vien can tim: ");
    fflush(stdin);
    gets(ten);
    node *p = l.first;
    while (p != NULL){
        if(strcmp(p->thongtin.ten, ten) == 0){
            printf("Ten: %s\n", p->thongtin.ten);
            printf("Nam sinh: %d\n", p->thongtin.namsinh);
            node *q = p->next;
            int socon = 0;
            while(q != NULL){
                if(q->Cha == p){
                    socon++;
                    printf("Con: %s\n", q->thongtin.ten);
                }
                q = q->next;
            }
            if(socon == 0){
                printf("Khong co con!\n");
            }
            break;
        }
        p = p->next;
    }
}
int menu(Dlist &l){
    printf("1. Them thanh vien\n");
    printf("2. Them con\n");
    printf("3. Tim va hien thi thong tin + con cua thanh vien do\n");
    printf("4. Hien thi danh sach\n");
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
            Find_tv(l);
            flag = 1;
            printf("\n");
            break;
        case 4:
            Display(l);
            flag = 1;
            printf("\n");
            break;
        case 9: //In dia chi thanh vien
            in_dia_chi_anhchiem(l);
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