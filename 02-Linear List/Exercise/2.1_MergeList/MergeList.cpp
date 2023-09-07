#include "MergeList.h"

// 将两个递增的有序链表La和Lb合并为一个递增的有序链表Lc
void MergeList(LinkList &La, LinkList &Lb, LinkList &Lc) {
    // pa和pb分别是链表La和Lb的工作指针,初始化为相应链表的首元结点
    LNode *pa = La->next;                // pa是链表La的工作指针,初始化为首元结点
    LNode *pb = Lb->next;                // pb是链表Lb的工作指针,初始化为首元结点

    Lc = La;
    LNode *pc = La;                      // 用La的头结点作为Lc的头结点
    while (pa && pb)                     // 两个链表La和Lb均未到达表尾结点
    {
        // 取较小者La中的元素，将pa链接在pc的后面，pa指针后移
        if (pa->data < pb->data) {
            pc->next = pa;
            pc = pa;
            pa = pa->next;
        } else if (pa->data > pb->data)  // 取较小者Lb中的元素，将pb链接在pc的后面，pb指针后移
        {
            pc->next = pb;
            pc = pb;
            pb = pb->next;
        } else                          // 相等时取La中的元素，删除Lb中的元素
        {
            pc->next = pa;
            pc = pa;
            pa = pa->next;
            LNode *q = pb->next;
            delete pb;
            pb = q;
        }
    }
    pc->next = pa ? pa : pb;                // 将非空表的剩余元素直接链接在Lc表的最后
    delete Lb;                              // 释放Lb的头结点
}