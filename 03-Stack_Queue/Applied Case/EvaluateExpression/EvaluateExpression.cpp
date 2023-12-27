#include "EvaluateExpression.h"
#include<iostream>

/* 链栈实现表达式求值 */

// 支持的运算符和界限符
const char oper[] = {'+', '-', '*', '/', '(', ')', '#'};

// 算法3.22　表达式求值
// 算术表达式求值的算符优先算法, 设OPTR和OPND分别为运算符栈和操作数栈

char EvaluateExpression() {
    char ch, theta, a, b, x, top;

    LinkStack OPTR, OPND;
    InitStack(OPND);            // 初始化OPND栈
    InitStack(OPTR);            // 初始化OPTR栈
    Push(OPTR, '#');         // 将表达式起始符“#”压入OPTR栈
    std::cin >> ch;

    // 表达式没有扫描完毕或OPTR的栈顶元素不为“#”
    while (ch != '#' || (GetTop(OPTR) != '#')) {
        // ch不是运算符则进OPND栈
        if (!In(ch)) {
            Push(OPND, ch);
            std::cin >> ch;
        } else
            switch (Precede(GetTop(OPTR), ch)) // 比较OPTR的栈顶元素和ch的优先级
            {
                case '<':
                    Push(OPTR, ch);
                    std::cin >> ch;                                         // 当前字符ch压入OPTR栈，读入下一字符ch
                    break;
                case '>':
                    Pop(OPTR, theta);                                // 弹出OPTR栈顶的运算符
                    Pop(OPND, b);
                    Pop(OPND, a);                                    // 弹出OPND栈顶的两个运算数
                    Push(OPND, Operate(a, theta, b));   // 将运算结果压入OPND栈
                    break;
                case '=':                     // OPTR的栈顶元素是“(”且ch是“)”
                    Pop(OPTR, x);
                    std::cin >> ch;           // 弹出OPTR栈顶的“(”，读入下一字符ch
                    break;
            }
    }

    // OPND栈顶元素即为表达式求值结果
    return GetTop(OPND);
}

// 判断ch是否为运算符
bool In(char ch) {
    for (int i = 0; i < sizeof(oper) / sizeof(oper[0]); i++) {
        if (ch == oper[i]) {
            return true;
        }
    }
    return false;
}

// 判断运算符优先级
char Precede(char theta1, char theta2) {
    if ((theta1 == '(' && theta2 == ')') || (theta1 == '#' && theta2 == '#')) {
        return '=';
    } else if (theta1 == '(' || theta1 == '#' || theta2 == '(' || (theta1
                                                                   == '+' || theta1 == '-') &&
                                                                  (theta2 == '*' || theta2 == '/')) {
        return '<';
    } else
        return '>';
}

// 计算两数运算结果
char Operate(char first, char theta, char second) {
    switch (theta) {
        case '+':
            return (first - '0') + (second - '0') + 48;
        case '-':
            return (first - '0') - (second - '0') + 48;
        case '*':
            return (first - '0') * (second - '0') + 48;
        case '/':
            return (first - '0') / (second - '0') + 48;
    }
    return 0;
}