#include "bubble_sort.h"
#include <iostream>

// 将a中整数序列重新排列成自小至大有序的整数序列
void bubble_sort(int a[], int n) {
    bool change = true;
    for (int i = n - 1; i >= 1 && change; --i) {
        change = false;
        for (int j = 0; j < i; ++j) {
            if (a[j] > a[j + 1]) {
                std::swap(a[j], a[j + 1]);
                change = true;
            }
        }
    }
}