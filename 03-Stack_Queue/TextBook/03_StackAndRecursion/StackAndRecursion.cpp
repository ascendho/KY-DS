#include "StackAndRecursion.h"
#include<iostream>
#include<vector>

/* 二阶斐波那契数列 */

// 递归实现
// 时间复杂度: O(2^n)
// 空间复杂度: O(n)

long Fib(long n) {

    if (n == 1 || n == 2) return 1;           // 递归终止的条件
    else
        return Fib(n - 1) + Fib(n - 2); // 递归步骤
}

// 迭代实现
// 时间复杂度: O(n)

long Fib_iteration(long n) {
    std::vector<int> numbers = {0, 1};

    for (int i = 2; i < n + 1; i++)
        numbers.push_back(numbers[i - 2] + numbers[i - 1]);

    return numbers[n];
}

/* 阶乘函数 */

// 递归实现
// 时间复杂度: O(n)
// 空间复杂度: O(n)

long Fact(long n) {
    if (n == 0) return 1;           // 递归终止的条件
    else
        return n * Fact(n - 1);  // 递归步骤
}


// 迭代实现
// 时间复杂度: O(n)

long Fact_iteration(long n) {
    int result = 1;

    for (int i = 2; i <= n; i++)
        result *= i;

    return result;
}


// 算法3.9　遍历输出链表中各个结点的递归算法
// 依次输出链表中的各个结点

void TraverseList(LinkList p) {
    if (p == nullptr)
        return;                     // 递归终止
    else {
        Visit(p);                   // 输出当前结点的数据域
        TraverseList(p->next);   // p指向后继指点继续递归
    }
}

// 算法3.10　Hanoi塔问题的递归算法
// 将塔座A上的n个圆盘按规则搬到C上，B做辅助塔

// 时间复杂度：O(2^n)
// 空间复杂度：O(n)

void Hanoi(int n, char A, char B, char C) {
    // 将编号为1的圆盘从A移到C
    if (n == 1)
        move(A, 1, C);
    else {
        Hanoi(n - 1, A, C, B);   // 将A上编号为1至n-1的圆盘移到B，C做辅助塔
        move(A, n, C);                    // 将编号为n的圆盘从A移到C
        Hanoi(n - 1, B, A, C);   // 将B上编号为1至n-1的圆盘移到C，A做辅助塔
    }
}

// 搬动操作
void move(char A, int n, char C) {
    std::cout << "第" << ++k << "步," << "将编号为" << n << "的圆盘从第" << A << "个柱子上移到第" << C
              << "个柱子上" << std::endl;
}