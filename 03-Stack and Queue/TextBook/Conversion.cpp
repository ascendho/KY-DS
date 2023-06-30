#include "Conversion.h"
#include<iostream>

/* 链栈实现数制的转换 */

// 算法3.20　数制的转换(链栈实现)
// 注：严蔚敏教材中只是10进制转换为8进制，这里参考邓俊辉版本的课本进行拓展
// 对于任意一个非负十进制数，打印输出与其等值的base进制数

// 时间复杂度: O(log)
// 空间复杂度: O(log)

void Conversion(int N, int base) {
    SElemType e;

    // 1<base<=16,base新进制下的数位符号，可视base取值范围适当扩充
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
        Push(S, digit[remainder]);     // 把N与base求余得到的八进制数压入栈S
        N = N / base;                        // N更新为N与base的商
    }

    while (!StackEmpty(S))                   // 当栈S非空时，循环
    {
        Pop(S, e);                     // 弹出栈顶元素e
        std::cout << e;
    }
}