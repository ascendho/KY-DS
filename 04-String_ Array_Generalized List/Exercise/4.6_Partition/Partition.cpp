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

// 双指针法 (初步验证无误)
void Partition_dp(int A[], int n) {
    int NegPtr = 0, PosPtr = 0;                     // 分别指向负数和正数, 初始化指向0
    bool IsNegative = false, IsPositive = false;    // 分别标志双指针是否分别指向负数和正数, 初始化为false

    // 负数和正数指针都不能越界
    while (NegPtr < n && PosPtr < n) {
        if (A[NegPtr] < 0 ) IsNegative = true;   // 验证负数指针是否指向负数
        if (A[PosPtr] > 0 ) IsPositive = true;   // 验证正数指针是否指向正数

        // 分别指向负数和正数时
        if (IsNegative && IsPositive) {
            if (NegPtr < PosPtr) {                      // 负数在整数前面
                std::swap(A[NegPtr], A[PosPtr]);  // 交换
                IsNegative = IsPositive = false;        // 调整标志值以便移动指针
            } else {
                IsPositive = false;                     // 负数在正数后面, 令标志值为false以便移动指针
            }
        }

        if (!IsNegative) NegPtr++;         // 移动负数指针
        if (!IsPositive) PosPtr++;         // 移动正数指针
    }
}