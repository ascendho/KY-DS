#include "Intersection.h"

// 求两个递增的有序链表La和Lb的交集，使用头指针Lc指向
void Intersection(LinkList &La, LinkList &Lb, LinkList &Lc) {
    LNode *pa = La->next;                    // pa是链表La的工作指针,初始化为首元结点
    LNode *pb = Lb->next;                    // pb是链表Lb的工作指针,初始化为首元结点

    Lc = La;
    LNode *pc = La;                          // 用La的头结点作为Lc的头结点

    // 两个链表La和Lb均未到达表尾结点
    while (pa && pb) {
        if (pa->data == pb->data)            // 相等，交集并入结果表中
        {
            // 取La中的元素，将pa链接在pc的后面，pa指针后移
            pc->next = pa;
            pc = pa;
            pa = pa->next;

            // 删除Lb中的对应的相等元素
            LNode *u = pb;
            pb = pb->next;
            delete u;

        } else if (pa->data < pb->data)     // 删除较小者La中的元素
        {
            LNode *u = pa;
            pa = pa->next;
            delete u;
        } else                             // 删除较小者Lb中的元素
        {
            LNode *u = pb;
            pb = pb->next;
            delete u;
        }
    }
    while (pa)                             // Lb为空，删除非空表La中的所有元素
    {
        LNode *u = pa;
        pa = pa->next;
        delete u;
    }
    while (pb)                             // La为空，删除非空表Lb中的所有元素
    {
        LNode *u = pb;
        pb = pb->next;
        delete u;
    }
    pc->next = nullptr;                   // 置链表Lc尾标记
    delete Lb;                            // 释放Lb的头结点
}