#include "RecursionInLinkList.h"

// 递归求解链表的最大整数
int GetMax(LinkList p) {
    if (!p->next)                                    // p指向表尾，返回其数值域
        return p->data;
    else {
        int max = GetMax(p->next);                // 递归
        return p->data >= max ? p->data : max;       // 返回较大者
    }
}

// 递归求解链表的结点个数
int GetLength(LinkList p) {
    if (!p->next)                                    // p指向表尾，返回1
        return 1;
    else                                             // 每递归一次，结点个数加1
    {
        return GetLength(p->next) + 1;
    }
}

// 递归求解链表中所有整数的平均值
double GetAverage(LinkList p, int n) {
    if (!p->next)                                    // p指向表尾，返回其数值
        return p->data;
    else {
        double ave = GetAverage(p->next, n - 1);

        // 递归求解除尾结点之外的其余n-1个结点的平均值
        return (ave * (n - 1) + p->data) / n;            // 返回平均值
    }
}