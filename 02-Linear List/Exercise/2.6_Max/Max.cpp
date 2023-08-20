#include "Max.h"

// 确定单链表中值最大的结点

LNode *Max(LinkList L) {
    if (L->next == nullptr) return nullptr;

    LNode *pmax = L->next;               // pmax指向首元结点
    LNode *p = L->next->next;            // p指向第二个结点

    // 遍历链表，如果下一个结点存在
    while (p != nullptr) {
        if (p->data > pmax->data)
            pmax = p;                    // pmax指向数值大的结点
        p = p->next;                     // p指向下一个结点，继续遍历
    }

    return pmax;
}