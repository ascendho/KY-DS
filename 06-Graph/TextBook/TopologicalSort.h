#ifndef TEXTBOOK_TOPOLOGICALSORT_H
#define TEXTBOOK_TOPOLOGICALSORT_H

#include "AdjacencyList.h"
#include <iostream>

// 顺序栈的定义
typedef struct {
    int *base;
    int *top;
    int stacksize;
} spStack;

// 栈的相关操作
void InitStack(spStack &S) {
    //初始化栈
    S.base = new int[MVNum];
    if (!S.base)
        exit(1);
    S.top = S.base;
    S.stacksize = MVNum;
}

void Push(spStack &S, int i) {
    // 进栈
    if (S.top - S.base == S.stacksize)
        return;
    *S.top++ = i;
}

void Pop(spStack &S, int &i) {
    // 出栈
    if (S.top == S.base)
        return;
    i = *--S.top;
}

bool StackEmpty(spStack S) {
    // 判断栈是否为空
    if (S.top == S.base)
        return true;
    return false;
}

int indegree[MVNum];  // 数组indegree存放个顶点的入度
spStack S;            // 暂存所有入度为0的顶点

void FindInDegree(ALGraph G);

int TopologicalSort(ALGraph G, int topo[]);

#endif //TEXTBOOK_TOPOLOGICALSORT_H