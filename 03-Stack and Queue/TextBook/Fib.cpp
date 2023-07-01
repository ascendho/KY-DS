#include "Fib.h"

// 二阶斐波那契数列
long Fib(long n) {
    if (n == 1 || n == 2) return 1;            // 递归终止的条件
    else return Fib(n - 1) + Fib(n - 2); // 递归步骤
}