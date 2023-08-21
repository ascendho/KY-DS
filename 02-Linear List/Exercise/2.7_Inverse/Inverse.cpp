#include "Inverse.h"

// 逆置带头结点的单链表L

void Inverse(LinkList &L) {
    LNode *p = L->next;                // p指向首元结点
    L->next = nullptr;                 // 头结点的指针域置为空

    while (p != nullptr)               // 遍历链表，如果下一个结点存在
    {
        LNode *q = p->next;            // q指向*p的后继
        p->next = L->next;
        L->next = p;                   // *p插入在头结点之后
        p = q;
    }
}