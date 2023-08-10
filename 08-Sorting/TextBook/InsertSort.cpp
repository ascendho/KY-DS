#include "InsertSort.h"

// 算法8.1 直接插入排序
// 对顺序表L做直接插入排序

// 时间复杂度: O(n^2)
// 空间复杂度: O(1)
// 稳定性: 稳定排序

void InsertSort(DataList &L) {
    int j;

    for (int i = 2; i <= L.length; ++i)
        if (L.r[i].key < L.r[i - 1].key) {              // "<"，需将r[i]插入有序子表
            L.r[0] = L.r[i];                            // 将待插入的记录暂存到监视哨中
            L.r[i] = L.r[i - 1];                        // r[i-1]后移

            for (j = i - 2; L.r[0].key < L.r[j].key; --j)            // 从后向前寻找插入位置
                L.r[j + 1] = L.r[j];                                 // 记录逐个后移，直到找到插入位置
            L.r[j + 1] = L.r[0];                                     // 将r[0]即原r[i]，插入到正确位置
        }
}