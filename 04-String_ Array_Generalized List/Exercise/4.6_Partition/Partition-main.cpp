#include "Partition.h"
#include <iostream>

void Print(int A[], int length);

int main() {
    int arr1[] = {1, 3, -1, -2, 8, 9, -7, 5, -1, 2, 6, -7, -2};
    int arr2[] = {3, 1, -1, -3, 4, 5, -2};

    int length1 = sizeof(arr1) / sizeof(arr1[0]);     // 获取数组长度
    int length2 = sizeof(arr2) / sizeof(arr2[0]);     // 获取数组长度

    Partition_dp(arr1, length1);
    Print(arr1, length1);

    Partition_dp(arr2, length2);
    Print(arr2, length2);

    return 0;
}

// 输出处理后的数组
void Print(int A[], int length) {
    std::cout << A[0];
    for (int i = 1; i < length; i++) {
        std::cout << "->" << A[i];
    }

    std::cout << std::endl;
}