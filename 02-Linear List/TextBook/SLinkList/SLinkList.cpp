#include "SLinkList.h"

/* 注: 在人民邮电出版的双色版中, 没有静态链表的内容, 但在基数排序中又用到了这个数据结构, 故补充
   清华大学出版社出版的原版紫书中关于静态链表的内容 */

// 算法2.13
// 在静态单链线性表L中查找第1个值为e的元素
// 若找到, 则返回它在L中的位序，否则返回0

int LocateElem_SL(SLinkList S, ElemType e) {
    int index = S[0].cur;                              // i指示表中第一个结点
    while (index && S[index].data != e)
        index = S[index].cur;                          // 在表中顺链查找
    return index;
}

// 算法2.14
// 将一维数组space中各分量链成一个备用链表，space[0].cur为头指针, "0"表示空指针

void InitSpace_SL(SLinkList space) {
    for (int i = 0; i < MAXSIZE - 1; ++i)
        space[i].cur = i + 1;
    space[MAXSIZE - 1].cur = 0;
}

// 算法2.15
// 若备用空间链表非空，则返回分配的结点下标，否则返回0

int Malloc_SL(SLinkList &space) {
    int index = space[0].cur;
    if (space[0].cur)
        space[0].cur = space[space[0].cur].cur;
    return index;
}

// 算法2.16
// 将下标为k的空闲结点回收到备用链表

void Free_SL(SLinkList &space, int k) {
    space[k].cur = space[0].cur;
    space[0].cur = k;
}