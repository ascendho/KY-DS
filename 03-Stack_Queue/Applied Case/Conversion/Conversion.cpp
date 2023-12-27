#include "Conversion.h"
#include<iostream>

// 算法3.20　数制的转换(链栈实现)
// 注：严蔚敏教材中只是10进制转换为8进制, 这里参考邓俊辉版本的课本进行拓展
// 对于任意一个非负十进制数, 打印输出与其等值的base进制数

// 时间复杂度: O(log)
// 空间复杂度: O(log)

void Conversion(int N, int base) {
    SElemType e;

    // 1<base<=16,base新进制下的数位符号, 可视base取值范围适当扩充
    static char digit[] = {'0', '1', '2', '3',
                           '4', '5', '6', '7',
                           '8', '9', 'A', 'B',
                           'C', 'D', 'E', 'F'};

    // 初始化空栈S
    LinkStack S;
    InitStack(S);

    // 当N非零时,循环
    while (N) {
        int remainder = N % base;

        // 把N与base求余得到的base进制数压入栈S
        Push(S, digit[remainder]);

        // N更新为N与base的商
        N = N / base;
    }

    // 当栈S非空时，循环
    while (!StackEmpty(S)) {
        // 弹出栈顶元素e
        Pop(S, e);
        std::cout << e;
    }
}

// 递归版本: 参考邓书, 修改为严书风格代码
// 整数n的1<base<=16进制打印（递归版）

void Conversion_Recursive(int N, int base) {
    // 1<base<=16,base新进制下的数位符号, 可视base取值范围适当扩充
    static char digit[] = {'0', '1', '2', '3',
                           '4', '5', '6', '7',
                           '8', '9', 'A', 'B',
                           'C', 'D', 'E', 'F'};

    SElemType e;

    // 初始化空栈S
    LinkStack S;
    InitStack(S);

    // 在尚有余数之前, 反复地
    if (0 < N) {
        // 通过递归得到所有更高位
        Conversion_Recursive(N / base, base);

        // 逆向记录当前最低位
        Push(S, digit[N % base]);

    }

    // 当栈S非空时, 循环
    while (!StackEmpty(S)) {
        // 弹出栈顶元素e
        Pop(S, e);
        std::cout << e;
    }
}