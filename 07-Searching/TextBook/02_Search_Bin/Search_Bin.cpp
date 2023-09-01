#include "Search_Bin.h"

// 算法7.3　折半查找
// 在有序表ST中折半查找其关键字等于key的数据元素。若找到，则函数值为该元素在表中的位置，否则为0

// 时间复杂度: O(logn)

int Search_Bin(SSTable ST, int key) {
    int low = 1, high = ST.length;                            // 置查找区间初值
    int mid;

    while (low <= high) {
        mid = (low + high) / 2;
        if (key == ST.R[mid].key)
            return mid;                                      // 找到待查元素
        else if (key < ST.R[mid].key)
            high = mid - 1;                                  // 继续在前一子表进行查找
        else
            low = mid + 1;                                   // 继续在后一子表进行查找
    }
    return 0;                                                // 表中不存在待查元素
}