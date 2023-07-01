#include "Fact.h"

// 阶乘函数

// 时间复杂度: O(n)
// 空间复杂度: O(n)

long Fact(long n) {
    if (n == 0) return 1;           // 递归终止的条件
    else return n * Fact(n - 1); // 递归步骤
}