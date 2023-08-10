#include "Search_Seq.h"

// 算法7.1　顺序查找
// 在顺序表ST中顺序查找其关键字等于key的数据元素。若找到，则函数值为该元素在表中的位置，否则为0

// 时间复杂度: O(n)
// 注: ST.R[0]闲置不用

int Search_Seq(SSTable ST, int key) {
    // 从后往前找
    for (int i = ST.length; i >= 1; --i)
        if (ST.R[i].key == key)
            return i;
    return 0;
}

// 算法7.2　设置监视哨的顺序查找
// 在顺序表ST中顺序查找其关键字等于key的数据元素。若找到，则函数值为该元素在表中的位置，否则为0

// 时间复杂度: O(n)

int Search_Seq_(SSTable ST, int key) {
    int index = ST.length;

    ST.R[0].key = key;                               // “监视哨”
    for (; ST.R[index].key != key; --index);         // 从后往前找
    return index;
}