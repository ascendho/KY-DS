#include "Max.h"

/*
 * 设计一个算法，通过一趟遍历确定长度为n的单链表中值最大的结点
 */

// 求最大值
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

/*
 * 此题的关键点在千：在遍历的时候利用指针pmax 记录值最大的结点的位置。
*/

/* 算法思想是：初始时指针pmax指向首元结点，然后在遍历过程中，用pmax依次和后面的结
   点进行比较，发现大者则用pmax指向该结点。这样将链表从头到尾遍历一遍时，pmax所指向的
   结点中的数据即为最大值。
*/