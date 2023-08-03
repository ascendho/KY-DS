#include "BiTreeStack.h"
#include <iostream>

// 树栈初始化
void InitBiTreeStack(BiTreeStack &S) {
    S.base = new BiTree[MAXSIZE];
    if (!S.base) exit(-1);

    S.top = S.base;
    S.size = MAXSIZE;
}

// 树栈入栈
void PushBiTree(BiTreeStack &S, BiTree e) {
    if (S.top - S.base == S.size) return;
    *S.top = e;
    S.top++;
}

// 树栈出栈
void PopBiTree(BiTreeStack &S, BiTree &e) {
    if (S.top == S.base) return;
    e = *--S.top;
}