#include <iostream>
#include "LinkStack.h"

// 算法3.5　链栈的初始化
// 构造一个空栈 S，栈顶指针置空

Status InitStack(LinkStack &S) {
    S = nullptr;
    return OK;
}

// 算法3.6　链栈的入栈
// 在栈顶插入元素e

Status Push(LinkStack &S, SElemType e) {
    LinkStack p = new StackNode;
    p->data = e;
    p->next = S;
    S = p;
    return OK;
}

// 算法3.7　链栈的出栈
// 删除S的栈顶元素，用e返回其值

Status Pop(LinkStack &S, SElemType &e) {
    // 栈空
    if (S == nullptr)
        return ERROR;

    //用p临时保存栈顶元素空间，以备释放
    LinkStack p = S;

    e = S->data; //将栈顶元素赋给e
    S = S->next; //修改栈顶指针
    delete p;    //释放原栈顶元素的空间
    return OK;
}

// 算法3.8　取链栈的栈顶元素
// 返回S的栈顶元素，不修改栈顶指针

SElemType GetTop(LinkStack S) {
    // 栈非空
    if (S != nullptr)
        return S->data;

    exit(OVERFLOW);
}