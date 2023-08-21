#ifndef EXERCISE_DBLSTACK_H
#define EXERCISE_DBLSTACK_H

#include "../../../Status/Status.h"

typedef struct {
    int top[2], bot[2];     // 栈顶和栈底指针
    SElemType *V;           // 栈数组
    int max;                // 栈最大可容纳元素个数
} DblStack;

Status InitDblStack(DblStack &S, int max);

Status DblPush(DblStack &S, int i, int x);

Status DblPop(DblStack &S, int i, SElemType &x);

Status IsEmpty(DblStack S, int i);

Status IsFull(DblStack S);

#endif //EXERCISE_DBLSTACK_H