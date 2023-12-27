#ifndef INC_02_LINEAR_LIST_LINKLIST_H
#define INC_02_LINEAR_LIST_LINKLIST_H

#include "../../../Status/Status.h"

typedef struct LNode {
    ElemType data;         // 结点的数据域
    struct LNode *next;    // 结点的指针域
} LNode, *LinkList;        // LinkList为指向结构体LNode的指针类型

Status InitLinkList(LinkList &L);

Status GetLinkListElem(LinkList L, int i, ElemType &e);

LNode *LocateLinkListElem(LinkList L, ElemType e);

Status LinkListInsert(LinkList &L, int i, ElemType e);

Status LinkListDelete(LinkList &L, int i);

void CreateList_H(LinkList &L, int n);

void CreateList_R(LinkList &L, int n);

Status ElemIsInLinkList(LinkList L, ElemType e);

#endif //INC_02_LINEAR_LIST_LINKLIST_H