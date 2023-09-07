#include "MergeList.h"

// 将两个非递减的有序链表La和Lb合并为一个非递增的有序链表Lc
void MergeList(LinkList &La, LinkList &Lb, LinkList &Lc) {
    LNode *pa = La->next;                    // pa是链表La的工作指针,初始化为首元结点
    LNode *pb = Lb->next;                    // pb是链表Lb的工作指针,初始化为首元结点

    Lc = La;
    LNode *pc = La;                          // 用La的头结点作为Lc的头结点
    Lc->next = nullptr;

    LNode *q;

    // 只要有一个表未到达表尾结点，用q指向待摘取的元素
    while (pa || pb)
    {
        if (!pa)                           // La表为空，用q指向pb，pb指针后移
        {
            q = pb;
            pb = pb->next;
        } else if (!pb)                    // Lb表为空，用q指向pa，pa指针后移
        {
            q = pa;
            pa = pa->next;
        } else if (pa->data <= pb->data)   // 取较小者La中的元素，用q指向pa，pa指针后移
        {
            q = pa;
            pa = pa->next;
        } else                            // 取较小者Lb中的元素，用q指向pb，pb指针后移
        {
            q = pb;
            pb = pb->next;
        }
        q->next = Lc->next;
        Lc->next = q;                      // 将q指向的结点插在Lc的表头结点之后
    }
    delete Lb;                             // 释放Lb的头结点
}