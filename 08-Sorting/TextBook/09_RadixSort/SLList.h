#ifndef INC_10_RADIXSORT_SLLIST_H
#define INC_10_RADIXSORT_SLLIST_H

#include "../../../Status/Status.h"

typedef int ArrType[RADIX];             // 指针数组类型

// 静态链表类型
typedef struct {
    KeysType keys[MAXNUM_KEY];          // 关键字
    InfoType otheritems;                // 其他数据项
    int next;
} SLCell;                               // 静态链表的结点类型
typedef struct {
    SLCell r[MAX_SPACE];                // 静态链表的可利用空间，r[0]为头结点
    int keynum;                         // 记录的当前关键字个数
    int recnum;                         // 静态链表的当前长度
} SLList;

void print(SLList L);

void Sort(SLList L, int adr[]);

void Rearrange(SLList *L, int adr[]);

#endif //INC_10_RADIXSORT_SLLIST_H