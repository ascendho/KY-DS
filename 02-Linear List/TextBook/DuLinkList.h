#ifndef INC_02_LINEAR_LIST_DULINKLIST_H
#define INC_02_LINEAR_LIST_DULINKLIST_H

#include<iostream>
#include<fstream>

using namespace std;

#include "../../Status/Status.h"

typedef struct DuLNode {
    ElemType data;         //数据域
    struct DuLNode *prior; //直接前驱
    struct DuLNode *next;  //直接后继
} DuLNode, *DuLinkList;

string head_1, head_2, head_3;
int length;

Status InitDuList_L(DuLinkList &L);

DuLNode *GetElemP_DuL(DuLinkList L, int i);

Status ListInsert_DuL(DuLinkList &L, int i, ElemType e);

Status ListDelete_DuL(DuLinkList &L, int i);

void CreateDuList_L(DuLinkList &L) {
    //正位序输入n个元素的值，建立带表头结点的双向链表L，同时建立前驱指针
    DuLinkList r, p;
    L = new DuLNode;
    L->next = nullptr; //先建立一个带头结点的空链表
    r = L;//尾指针r指向头结点
    length = 0;
    fstream file;
    file.open("ElemType.txt");
    if (!file) {
        cout << "未找到相关文件，无法打开！" << endl;
        exit(ERROR);
    }
    file >> head_1 >> head_2 >> head_3;
    while (!file.eof()) {
        p = new DuLNode; //生成新结点
        file >> p->data >> p->data >> p->data; //输入元素值
        p->next = nullptr;
        r->next = p; //插入到表尾
        r = p; //r指向新的尾结点
        p->prior = L->prior; //插入到表头
        L->prior = p;
        length++;
    }
    file.close();
} //CreateDuList_L

Status DeleteNextNode(DuLNode *p);

void DestroyList(DuLinkList &L);

void TravelList(DuLinkList L, void (Visit)(ElemType));


#endif //INC_02_LINEAR_LIST_DULINKLIST_H
