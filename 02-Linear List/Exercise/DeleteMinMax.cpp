#include "DeleteMinMax.h"

/*
 * 设计一个算法，删除递增有序链表中值大于mink且小于maxk的所有元素（mink和
 * maxk是给定的两个参数，其值可以和表中的元素相同，也可以不同）
 */

// 删除最大值和最小值之间的元素
// 删除递增有序链表L中值大于mink且小于maxk的所有元素

void DeleteMinMax(LinkList &L, int mink, int maxk) {
    LNode *p = L->next;                // p指向首元结点
    LNode *pre = L;                    // pre指向头结点

    // 查找第一个值大于mink的结点
    while (p && p->data <= mink)
    {
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
    while (q != p)
    {
        LNode *s = q->next;
        delete q;
        q = s;
    }
}

/*
 * 此题的关键点在于：通过遍历链表能够定位待删除元素的下边界和上边界，即可找到第一个
   值大于mink的结点和第一个值大于等于maxk的结点，分别如图2.13所示指针q和p指向的两
   个结点。
 */

/*
 * 算法思想是：1)查找第一个值大于mink的结点，用q指向该结点，pre指向该结点的前驱
 *  结点； 2)继续向下遍历链表，查找第一个值大千等于maxk的结点，用p指向该结点； 3）修
 *  改下边界前驱结点的指针域，使其指向上边界（pre->next=p); (4) 依次释放待删除结点的空间（图
 * 中介于pre和p之间所有的结点）。
 */