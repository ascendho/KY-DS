#include "HeapSort.h"

// 算法8.9 堆排序
// 对数据表L进行堆排序

// 时间复杂度: O(nlog2n)
// 空间复杂度: O(1)
// 稳定性: 不稳定排序

void HeapSort(DataList &L) {
    CreatHeap(L);                        // 把无序序列L.r[1..L.length]建成大根堆
    for (int i = L.length; i > 1; --i) {
        RecType x = L.r[1];                 // 将堆顶记录和当前未经排序子序列L.r[1..i]中最后一个记录互换
        L.r[1] = L.r[i];
        L.r[i] = x;
        HeapAdjust(L, 1, i - 1);  // 将L.r[1..i-1]重新调整为大根堆
    }
}

// 用算法8.7 筛选法调整堆
// 假设r[s+1..m]已经是堆，将r[s..m]调整为以r[s]为根的大根堆

void HeapAdjust(DataList &L, int s, int m) {
    RecType rc = L.r[s];

    for (int j = 2 * s; j <= m; j *= 2) {                // 沿key较大的孩子结点向下筛选
        if (j < m && L.r[j].key < L.r[j + 1].key)
            ++j;                                         // j为key较大的记录的下标
        if (rc.key >= L.r[j].key)
            break;                                       // rc应插入在位置s上
        L.r[s] = L.r[j];
        s = j;
    }
    L.r[s] = rc;                                    //插入
}

// 用算法8.8 建初堆
// 把无序序列L.r[1..n]建成大根堆

void CreatHeap(DataList &L) {
    int n = L.length;

    // 反复调用HeapAdjust
    for (int i = n / 2; i > 0; --i)
        HeapAdjust(L, i, n);
}