#include "Partition.h"
#include <iostream>

void Print(int A[], int length);

int main() {
    int arr[] = { 1 , 3,-1,-2,8,9,-7,5,-1,2,6,-7,-2 };
    int num = sizeof(arr) / sizeof(arr[0]);     // 获取数组长度

    Partition(arr, num);

    Print(arr,num);

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