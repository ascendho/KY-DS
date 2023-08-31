#ifndef BINARYTREECOMPUTEEXP_BITREESTACK_H
#define BINARYTREECOMPUTEEXP_BITREESTACK_H

#include "../../TextBook/01_BiTree/BiTree.h"
#include "../../../Status/Status.h"

// 树栈定义
typedef struct {
    BiTree *base;
    BiTree *top;
    int size;
} BiTreeStack;

void InitBiTreeStack(BiTreeStack &S);

void PushBiTree(BiTreeStack &S, BiTree e);

void PopBiTree(BiTreeStack &S, BiTree &e);

#endif //BINARYTREECOMPUTEEXP_BITREESTACK_H