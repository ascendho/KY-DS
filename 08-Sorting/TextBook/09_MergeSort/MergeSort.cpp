#include "MergeSort.h"

// 算法8.11 归并排序
// 对顺序表L做归并排序

// 时间复杂度: O(nlog2n)
// 空间复杂度: O(n)
// 稳定性: 稳定排序

void MergeSort(DataList &L) {
    MSort(L.r, L.r, 1, L.length);
}

// R[low..high]归并排序后放入T[low..high]中

void MSort(RecType R[], RecType T[], int low, int high) {
    RecType *S = new RecType[MAXSIZE];

    if (low == high)
        T[low] = R[low];
    else {
        int mid = (low + high) / 2;                      // 将当前序列一分为二，求出分裂点mid
        MSort(R, S, low, mid);                  // 对子序列R[low..mid] 递归归并排序，结果放入S[low..mid]
        MSort(R, S, mid + 1, high);              // 对子序列R[mid+1..high] 递归归并排序，结果放入S[mid+1..high]
        Merge(S, T, low, mid, high);                 // 将S[low..mid]和S [mid+1..high]归并到T[low..high]
    }
}

// 算法8.10 相邻两个有序子序列的归并
// 将有序表R[low..mid]和R[mid+1..high]归并为有序表T[low..high]

void Merge(RecType R[], RecType T[], int low, int mid, int high) {
    int i = low, j = mid + 1, k = low;

    while (i <= mid && j <= high) {
        // 将R中记录由小到大地并入T中
        if (R[i].key <= R[j].key)
            T[k++] = R[i++];
        else
            T[k++] = R[j++];
    }
    while (i <= mid)              // 将剩余的R[low..mid]复制到T中
        T[k++] = R[i++];
    while (j <= high)             // 将剩余的R[j.high]复制到T中
        T[k++] = R[j++];
}