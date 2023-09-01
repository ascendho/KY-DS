#include "ShellSort.h"

// 算法8.3 希尔排序
// 对顺序表L做一趟增量是dk的希尔插入排序

// 时间复杂度: 希尔排序的时间复杂度较直接插入排序的低
// 空间复杂度: O(1)
// 稳定性: 记录跳跃式地移动导致排序方法是不稳定的

void ShellInsert(DataList &L, int dk) {
    for (int i = dk + 1; i <= L.length; ++i)
        if (L.r[i].key < L.r[i - dk].key) {         // 需将L.r[i]插入有序增量子表
            L.r[0] = L.r[i];                        // 暂存在L.r[0]

            int j = i - dk;;
            for (; j > 0 && L.r[0].key < L.r[j].key; j -= dk)
                L.r[j + dk] = L.r[j];               // 记录后移，直到找到插入位置
            L.r[j + dk] = L.r[0];                   // 将r[0]即原r[i]，插入到正确位置
        }
}

// 按增量序列dt[0..t-1]对顺序表L作t趟希尔排序

void ShellSort(DataList &L, int dt[], int t) {
    for (int k = 0; k < t; ++k)
        ShellInsert(L, dt[k]);               // 一趟增量为dt[t]的希尔插入排序
}