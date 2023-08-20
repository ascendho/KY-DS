#include "Difference.h"

// 求差集
// La和Lb差集的结果存储于La中，n是结果集合中元素个数，调用时为0

void Difference(LinkList &La, LinkList &Lb, int &n) {
    LNode *pa = La->next;                // pa是链表La的工作指针,初始化为首元结点
    LNode *pb = Lb->next;                // pb是链表Lb的工作指针,初始化为首元结点
    LNode *pre = La;                     // pre为La中pa所指结点的前驱结点的指针
    while (pa && pb)                     // 两个链表La和Lb均未到达表尾结点
    {
        if (pa->data < pb->data)         // A链表中当前结点指针后移
        {
            n++;
            pre = pa;
            pa = pa->next;
        } else if (pa->data > pb->data)
            pb = pb->next;               // B链表中当前结点指针后移
        else                             // 在La表删除La和Lb中元素值相同的结点
        {
            pre->next = pa->next;
            LNode *u = pa;
            pa = pa->next;
            delete u;                    // 删除结点
        }
    }
    while (pa) {
        n++;
        pa = pa->next;
    }
}