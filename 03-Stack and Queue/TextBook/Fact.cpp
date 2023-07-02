#include "Fact.h"

// 阶乘函数

// 递归实现
// 时间复杂度: O(n)
// 空间复杂度: O(n)

long Fact(long n) {
    if (n == 0) return 1;           // 递归终止的条件
    else return n * Fact(n - 1); // 递归步骤
}



// 迭代实现
// 时间复杂度: O(n)

long Fact_iteration(long n) {
    int result = 1;

    for (int i = 2; i <= n; i++)
        result *= i;

    return result;
}