#include "Union.h"

// 算法2.15 线性表的并集（链表）
// 将所有在线性表LB中但不在LA中的数据元素插入到LA中

void UnionList(LinkList &LA, LinkList LB) {
    LNode *p = LB->next;
    int e;

    while (p != nullptr) {
        e = p->data;
        if (!ElemIsInLinkList(LA, e))        // LA中不存在和e相同的数据元素，则插入之
            LinkListInsert(LA, 1, e);     // 插入到开头，提高效率

        p = p->next;
    }
}

// 算法2.15 线性表的并集（顺序表）
// 将所有在线性表LB中但不在LA中的数据元素插入到LA中

void UnionList(SqList &LA, SqList LB) {
    // 求线性表的长度
    int LA_len = SqListLength(LA);
    int LB_len = SqListLength(LB);

    int e;

    for (int i = 1; i <= LB_len; i++) {
        GetSqListElem(LB, i, e);                //取LB中第i个数据元素赋给e
        if (!ElemIsInSqList(LA, e))                //LA中不存在和e相同的数据元素，则插入之
            SqListInsert(LA, ++LA_len, e);      //将e插在LA的最后
    }
}