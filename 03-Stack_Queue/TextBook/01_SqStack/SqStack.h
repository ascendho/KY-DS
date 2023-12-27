#ifndef INC_03_STACK_AND_QUEUE_SQSTACK_H
#define INC_03_STACK_AND_QUEUE_SQSTACK_H

#include "../../../Status/Status.h"

// 顺序栈定义
typedef struct {
    SElemType *base;  // 栈底指针
    SElemType *top;   // 栈顶指针
    int size;         // 栈可用的最大容量
} SqStack;

Status InitSqStack(SqStack &S);

Status Push(SqStack &S, SElemType e);

Status Pop(SqStack &S, SElemType &e);

SElemType GetTop(SqStack S);

#endif //INC_03_STACK_AND_QUEUE_SQSTACK_H