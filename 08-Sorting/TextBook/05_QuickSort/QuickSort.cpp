#include "QuickSort.h"

// 算法8.5 快速排序

// 时间复杂度: 平均情况下, O(nlog2n)
// 空间复杂度: 以最好情况下的空间复杂度为O(log2n), 最坏情况下为O(n)。
// 稳定性: 不稳定

// 对顺序表L做快速排序
void QuickSort(DataList &L) {
    // 调用前置初值：low=1; high=L.length;
    QSort(L, 1, L.length);
}

// 对顺序表L中的子序列L.r[low..high]做快速排序
void QSort(DataList &L, int low, int high) {
    if (low < high) {                                     // 长度大于1
        int pivotloc = Partition(L, low, high);        // 将L.r[low..high]一分为二，pivotloc是枢轴位置
        QSort(L, low, pivotloc - 1);              // 对左子表递归排序
        QSort(L, pivotloc + 1, high);             // 对右子表递归排序
    }
}

// 对顺序表L中的子表r[low..high]进行一趟排序，返回枢轴位置
int Partition(DataList &L, int low, int high) {
    L.r[0] = L.r[low];                        // 用子表的第一个记录做枢轴记录
    int pivotkey = L.r[low].key;              // 枢轴记录关键字保存在pivotkey中

    // 从表的两端交替地向中间扫描
    while (low < high) {
        while (low < high && L.r[high].key >= pivotkey)
            --high;
        L.r[low] = L.r[high];                    // 将比枢轴记录小的记录移到低端
        while (low < high && L.r[low].key <= pivotkey)
            ++low;
        L.r[high] = L.r[low];                   // 将比枢轴记录大的记录移到高端
    }
    L.r[low] = L.r[0];                          // 枢轴记录到位
    return low;                                 // 返回枢轴位置
}