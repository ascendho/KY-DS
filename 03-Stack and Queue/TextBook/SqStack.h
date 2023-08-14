#ifndef INC_03_STACK_AND_QUEUE_SQSTACK_H
#define INC_03_STACK_AND_QUEUE_SQSTACK_H

#include "../../Status/Status.h"

// 顺序栈定义
typedef struct {
    SElemType *base; //栈底指针
    SElemType *top;  //栈顶指针
    int size;        //栈可用的最大容量
} SqStack;

// 算法3.1　顺序栈的初始化
Status InitSqStack(SqStack &S);

// 算法3.2　顺序栈的入栈
Status Push(SqStack &S, SElemType e);

// 算法3.3　顺序栈的出栈
Status Pop(SqStack &S, SElemType &e);

// 算法3.4　取顺序栈的栈顶元素
SElemType GetTop(SqStack S);

Status StackEmpty(SqStack S);

Status DestroySqStack(SqStack& S);

Status ClearSqStack(SqStack& S);

#endif //INC_03_STACK_AND_QUEUE_SQSTACK_H