#include "RadixSort.h"

// 算法8.12 基数排序

// 时间复杂度: O(d(n+rd))
// 空间复杂度: O(n+rd)
// 稳定性: 稳定排序

// 对L做基数排序, 使得L成为按关键字自小到大的有序静态链表, L.r[0]为头结点, L是采用静态链表表示的顺序表
void RadixSort(SLList &L) {
    ArrType f, e;

    // 将L改造为静态链表
    for (int i = 0; i < L.recnum; ++i)
        L.r[i].next = i + 1;
    L.r[L.recnum].next = 0;

    for (int i = 0; i < L.keynum; ++i) {
        // 按最低位优先依次对各关键字进行分配和收集
        Distribute(L.r, i, f, e);           // 第i趟分配
        Collect(L.r, i, f, e);              // 第i趟收集
    }
}

// 静态链表L的r域中记录已按（keys[0], …, keys[i-1]）有序
// 本算法按第i个关键字keys[i]建立RADIX个子表, 使同一子表中记录的keys[i]相同
// f[0..RADIX-1]和e[0..RADIX-1]分别指向各子表中第一个和最后一个记录

void Distribute(SLCell *r, int i, ArrType &f, ArrType &e) {
    // 各子表初始化为空表
    for (int j = 0; j < RADIX; ++j)
        f[j] = 0;

    for (int p = r[0].next; p; p = r[p].next) {
        int j = ord(r[p].keys[i]);              // ord将记录中第i个关键字映射到[0..RADIX-1]
        if (!f[j])
            f[j] = p;
        else
            r[e[j]].next = p;
        e[j] = p;                                 // 将p所指的结点插入第j个子表中
    }
}

// 本算法按keys[i]自小至大地将f[0..RADIX-1]所指各子表依次链接成一个链表
// e[0..RADIX-1]为各子表的尾指针

void Collect(SLCell *r, int i, ArrType &f, ArrType &e) {
    int j;
    for (j = 0; !f[j]; j = succ(j));                // 找第一个非空子表，succ为求后继函数
    r[0].next = f[j];                                 // r[0].next指向第一个非空子表中第一个结点
    int t = e[j];
    while (j < RADIX - 1) {
        // 找下一个非空子表
        for (j = succ(j); j < RADIX - 1 && !f[j]; j = succ(j));

        // 链接两个非空子表
        if (f[j]) {
            r[t].next = f[j];
            t = e[j];
        }
    }
    r[t].next = 0;                        // t指向最后一个非空子表中的最后一个结点
}

// 返回k的映射(个位整数)
int ord(char c) {
    return c - '0';
}

// 求后继函数
int succ(int i) {
    return ++i;
}