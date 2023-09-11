#include "Partition.h"
#include <iostream>

// 数组A中存储n个整数, 将A中所有正数排在所有负数的前面
void Partition(int A[], int n) {
    int low = 0, high = n - 1;
    while (low < high) {
        while (low < high && A[low] > 0)
            low++;

        while (low < high && A[high] < 0)
            high--;

        // 交换A[low]与A[high]
        if (low < high)
            std::swap(A[low], A[high]);
    }
}

// 双指针法 目前还存在问题
void Partition_dp(int A[], int n){
    int tag1 = 0, tag2 = 0;
    int Neg, Pos;                  // 分别指向负数和正数

    for (int i = 0, j = 0; i < n && j < n;) {
        if (A[i] < 0 && tag1 == 0) {
            Neg = i;
            tag1 = 1;
        }

        if (A[j] > 0 && tag2 == 0) {
            Pos = j;
            tag2 = 1;
        }

        if (tag1 == 1 && tag2 == 1) {
            if (Neg < Pos) {
                std::swap(A[Neg], A[Pos]);
                tag1 = tag2 = 0;
            } else {
                tag2=0;
            }
        }

        if (tag1 == 0) i++;
        if (tag2 == 0) j++;
    }
}


// 3, 1, -1, -3, 4, 5, -2
