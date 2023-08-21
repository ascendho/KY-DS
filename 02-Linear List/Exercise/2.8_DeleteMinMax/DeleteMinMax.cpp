#include "DeleteMinMax.h"



// 删除递增有序链表L中值大于mink且小于maxk的所有元素

void DeleteMinMax(LinkList &L, int mink, int maxk) {
    LNode *p = L->next;                // p指向首元结点
    LNode *pre = L;                    // pre指向头结点

    // 查找第一个值大于mink的结点
    while (p && p->data <= mink) {
        pre = p;                        // pre指向前驱结点
        p = p->next;
    }

    // 查找第一个值大于等于maxk的结点
    while (p && p->data < maxk)
        p = p->next;

    // 修改待删除结点的指针
    LNode *q = pre->next;
    pre->next = p;

    // 依次释放待删除结点的空间
    while (q != p) {
        LNode *s = q->next;
        delete q;
        q = s;
    }
}