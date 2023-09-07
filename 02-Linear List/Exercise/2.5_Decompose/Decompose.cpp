#include "Decompose.h"

// 单链表A分解为两个具有相同结构的链表B和C
void Decompose(LinkList &A, LinkList &B, LinkList &C) {
    B = A;
    LNode *p = A->next;                // p为工作指针
    B->next = nullptr;                 // B表初始化

    C = new LNode;                     // 为C申请结点空间
    C->next = nullptr;                 // C初始化为空表

    // 表A未到达表尾结点
    while (p != nullptr) {
        LNode *r = p->next;             // 暂存p的后继

        if (p->data < 0)                // 将小于0的结点链入B表,前插法
        {
            p->next = B->next;
            B->next = p;
        } else                          // 将大于0的结点链入C表,前插法
        {
            p->next = C->next;
            C->next = p;
        }
        p = r;                          // p指向新的待处理结点
    }
}