#ifndef INC_03_STACK_AND_QUEUE_LINKSTACK_H
#define INC_03_STACK_AND_QUEUE_LINKSTACK_H

#include "../../Status/Status.h"

// 链栈的定义
typedef struct StackNode {
    SElemType data;
    struct StackNode *next;
} StackNode, *LinkStack;

// 算法3.5　链栈的初始化
Status InitStack(LinkStack &S);

// 算法3.6　链栈的入栈
Status Push(LinkStack &S, SElemType e);

// 算法3.7　链栈的出栈
Status Pop(LinkStack &S, SElemType &e);

// 算法3.8　取链栈的栈顶元素
SElemType GetTop(LinkStack S);

#endif //INC_03_STACK_AND_QUEUE_LINKSTACK_H