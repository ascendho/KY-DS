#include "SelectSort.h"
#include <iostream>

// 算法8.6 简单选择排序
// 对顺序表L做简单选择排序

void SelectSort(DataList &L) {
    // 在L.r[i..L.length]中选择关键字最小的记录
    for (int i = 1; i < L.length; ++i) {
        int k = i;
        for (int j = i + 1; j <= L.length; ++j)
            if (L.r[j].key < L.r[k].key)
                k = j;                               // k指向此趟排序中关键字最小的记录
        if (k != i) {
            std::swap(L.r[i], L.r[k]);  // 交换r[i]与r[k]
        }
    }
}