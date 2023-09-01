#include "BubbleSort.h"
#include <iostream>

// 算法8.4 冒泡排序
// 对顺序表L做冒泡排序

// 时间复杂度: O(n^2)
// 空间复杂度: O(1)
// 稳定性: 稳定排序

void BubbleSort(DataList &L) {
    int m = L.length - 1;
    int flag = 1;                                // flag用来标记某一趟排序是否发生交换

    while ((m > 0) && (flag == 1)) {
        flag = 0;                                // flag置为0，如果本趟排序没有发生交换，则不会执行下一趟排序
        for (int j = 1; j <= m; j++)
            if (L.r[j].key > L.r[j + 1].key) {
                flag = 1;                        // flag置为1，表示本趟排序发生了交换
                std::swap(L.r[j], L.r[j + 1]);
            }
        --m;
    }
}