#include "Exchange.h"

// 在双向循环链表，交换p所指向的结点及其前驱结点的顺序
void Exchange(DuLinkList p) {
    DuLNode *q = p->prior;         // 对应图2.20①
    q->prior->next = p;            // 对应图2.20②
    p->prior = q->prior;           // 对应图2.20③
    q->next = p->next;             // 对应图2.20④
    q->prior = p;                  // 对应图2.20⑤
    p->next->prior = q;            // 对应图2.20⑥
    p->next = q;                   // 对应图2.20⑦
}