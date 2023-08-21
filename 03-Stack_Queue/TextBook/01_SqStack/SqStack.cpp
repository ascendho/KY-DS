#include <iostream>
#include "SqStack.h"

// 算法3.1　顺序栈的初始化

Status InitSqStack(SqStack &S) {
    // 为顺序栈动态分配一个最大容量为MAXSIZE的数组空间
    S.base = new SElemType[MAXSIZE];

    // 存储分配失败
    if (!S.base)
        exit(OVERFLOW);

    // top初始为base，空栈
    S.top = S.base;

    // size置为栈的最大容量MAXSIZE
    S.size = MAXSIZE;
    return OK;
}

// 算法3.2　顺序栈的入栈

Status Push(SqStack &S, SElemType e) {
    // 栈满
    if (S.top - S.base == S.size)
        return ERROR;

    // 元素e压入栈顶，栈顶指针加1
    *(S.top++) = e;
    return OK;
}

// 算法3.3　顺序栈的出栈

Status Pop(SqStack &S, SElemType &e) {
    // 栈空
    if (S.top == S.base)
        return ERROR;

    // 栈顶指针减1，将栈顶元素赋给e
    e = *(--S.top);
    return OK;
}

// 算法3.4　取顺序栈的栈顶元素

SElemType GetTop(SqStack S) {
    // 栈非空
    if (S.top != S.base)
        return *(S.top - 1);  // 返回栈顶元素的值，栈顶指针不变

    exit(OVERFLOW);
}

Status StackEmpty(SqStack S) {
    if (S.top == S.base)
        return OK;
    return ERROR;
}

Status DestroySqStack(SqStack &S) {
    if (StackEmpty(S))
        return ERROR;

    free(S.base);

    S.base = nullptr;
    S.top = nullptr;
    S.size = 0;

    return OK;
}

Status ClearSqStack(SqStack &S) {
    if (&S == nullptr || (S).base == nullptr) {
        return ERROR;
    }

    S.top = S.base;

    return OK;
}