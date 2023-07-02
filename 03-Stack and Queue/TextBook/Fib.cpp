#include "Fib.h"
#include <vector>

// 二阶斐波那契数列

// 递归实现
// 时间复杂度: O(2^n)
// 空间复杂度: O(n)

long Fib(long n) {
    // 递归终止的条件
    if (n == 1 || n == 2) return 1;
    else return Fib(n - 1) + Fib(n - 2); // 递归步骤
}

// 迭代实现
// 时间复杂度: O(n)

long Fib_iteration(long n) {
    std::vector<int> numbers = {0, 1};

    for (int i = 2; i < n + 1; i++)
        numbers.push_back(numbers[i - 2] + numbers[i - 1]);

    return numbers[n];
}