#include "BInsertSort.h"

// 算法8.2 折半插入排序
// 对顺序表L做折半插入排序

// 时间复杂度: O(n^2)
// 空间复杂度: O(1)
// 稳定性: 稳定排序

void BInsertSort(DataList &L) {
    int low, high, mid;

    for (int i = 2; i <= L.length; ++i) {
        L.r[0] = L.r[i];                            // 将待插入的记录暂存到监视哨中
        low = 1;
        high = i - 1;                               // 置查找区间初值

        while (low <= high) {                       // 在r[low..high]中折半查找插入的位置
            mid = (low + high) / 2;                 // 折半
            if (L.r[0].key < L.r[mid].key)
                high = mid - 1;                     // 插入点在前一子表
            else
                low = mid + 1;                      // 插入点在后一子表
        }

        for (int j = i - 1; j >= high + 1; j--)
            L.r[j + 1] = L.r[j];                    // 记录后移
        L.r[high + 1] = L.r[0];                     // 将r[0]即原r[i], 插入到正确位置
    }
}