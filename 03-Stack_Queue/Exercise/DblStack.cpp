#include "DblStack.h"

// 初始化一个大小为m的双向栈s
Status InitDblStack(DblStack &S, int m) {
    // 动态分配一个最大容量为m的数组空间
    S.V = new SElemType[m];

    S.bot[0] = -1;                                    // 左栈栈底指针
    S.bot[1] = m;                                     // 右栈栈底指针
    S.top[0] = -1;                                    // 左栈栈顶指针
    S.top[1] = m;                                     // 右栈栈顶指针

    return OK;
}

// 向指定的i号栈中插入元素x
Status DblPush(DblStack &S, int i, int x) {
    // 栈满
    if (S.top[1] - S.top[0] == 1)
        return ERROR;

    if (i == 0)
        S.V[++S.top[0]] = x;                        //左栈：栈顶指针先加1，然后按此地址进栈
    else
        S.V[--S.top[1]] = x;                        //右栈：栈顶指针先减1，然后按此地址进栈
}

// 删除指定的i号栈的栈顶元素，用x返回其值
Status DblPop(DblStack &S, int i, SElemType &x) {
    // 栈空
    if (S.top[i] == S.bot[i])
        return ERROR;

    if (i == 0)
        x = S.V[S.top[0]--];                        // 左栈：栈顶指针减1
    else
        x = S.V[S.top[1]++];                        // 右栈：栈顶指针加1

    return OK;
}

// 判断指定的i号栈是否为空，空返回1，否则返回0
Status IsEmpty(DblStack S, int i) {
    return S.top[i] == S.bot[i];
}

// 判断栈是否满,满返回1,否则返回0
Status IsFull(DblStack S) {
    if (S.top[0] + 1 == S.top[1])
        return OK;
    else
        return ERROR;
}