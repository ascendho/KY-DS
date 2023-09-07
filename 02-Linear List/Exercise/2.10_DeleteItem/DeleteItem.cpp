#include "DeleteItem.h"

// 删除顺序表A中所有值为item的元素
void DeleteItem(SqList &A, int item) {
    int k = 0;                                // k记录值不等于item的元素个数
    for (int i = 0; i < A.length; i++)        // 从前向后扫描顺序表
        if (A.elem[i] != item)                // 查找值不为item的元素
        {
            A.elem[k] = A.elem[i];            // 利用原表的空间记录值不为item的元素
            k++;                              // 不等于item的元素增1
        }
    A.length = k;                             // 顺序表A的长度等于k
}