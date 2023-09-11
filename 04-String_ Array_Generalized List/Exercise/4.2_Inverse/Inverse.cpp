#include "Inverse.h"
#include "../../../Status/Status.h"
#include <iostream>

// 递归实现字符串的逆序存储
void Inverse(char A[]) {
    static int i = 0;         // 静态变量记录字符数组的下标
    char ch;
    std::cin >> ch;
    if (ch != ENDFLAG)        // '#'是字符串输入结束的标志
    {
        Inverse(A);           // 递归
        A[i++] = ch;          // 递归返回后存储字符串
    }
    A[i] = '\0';              // 字符串最后加上结尾标记
}