#include "MergeList.h"

// 算法2.16 顺序有序表的合并
// 已知顺序有序表LA和LB的元素按值非递减排序, 归并LA和LB得到新的顺序有序表LC的元素也按值非递减排序

// 时间复杂度：O(m+n)
// 空间复杂度：O(m+n)

void MergeList_Sq(SqList LA, SqList LB, SqList &LC) {
    // 新表长度为待合并两表的长度之和
    LC.elem = new ElemType[LA.length + LB.length];

    ElemType *pa = LA.elem;
    ElemType *pa_last = LA.elem + LA.length - 1;
    ElemType *pb = LB.elem;
    ElemType *pb_last = LB.elem + LB.length - 1;
    ElemType *pc = LC.elem;

    while ((pa <= pa_last) && (pb <= pb_last)) {
        // 依次摘取两表中值较小的结点插入到LC的最后
        if (*pa <= *pb)*pc++ = *pa++;
        else
            *pc++ = *pb++;
    }

    while (pa <= pa_last) *pc++ = *pa++;   //已达到LB表尾，依次将LA的剩余元素插入LC的最后
    while (pb <= pb_last) *pc++ = *pb++;   //已达到LA表尾，依次将LB的剩余元素插入LC的最后

}

// 算法2.17 链式有序表的合并
// 已知单链表LA和LB的元素按值非递减排序, 归并LA和LB得到新的单链表LC的元素也按值非递减排序

// 时间复杂度：O(m+n)
// 空间复杂度：O(1)

void MergeList_L(LinkList &LA, LinkList &LB, LinkList &LC) {
    // LA的头结点作为LC的头结点
    LC = LA;

    // pa和pb的初值分别指向两个表的第一个结点
    LNode *pa = LA->next;
    LNode *pb = LB->next;

    // pc的初值指向LC的头结点
    LinkList pc = LC;

    // LA和LB均未达到表尾，依次“摘取”两表中值较小的结点插入到LC的最后
    while (pa && pb) {
        if (pa->data <= pb->data) {
            pc->next = pa;
            pc = pa;
            pa = pa->next;
        } else {
            pc->next = pb;
            pc = pb;
            pb = pb->next;
        }
    }

    pc->next = pa ? pa : pb;  // 将非空表的剩余段插入到pc所指结点之后
    delete LB;                // 释放LB的头结点
}