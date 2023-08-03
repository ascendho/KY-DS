#ifndef BINARYTREECOMPUTEEXP_COMPUTEEXPRESSION_H
#define BINARYTREECOMPUTEEXP_COMPUTEEXPRESSION_H

#include "../../../Status/Status.h"
#include "../../TextBook/BiNode.h"
#include "../../../03-Stack and Queue/TextBook/SqStack.h"

// 树栈定义
typedef struct {
    BiTree *base;
    BiTree *top;
    int stacksize;
} BiTreeStack;

void InitBiTreeStack(BiTreeStack &S);

int EvaluateExTree(BiTree T);

void PushBiTree(BiTreeStack &S, BiTree e);

void PopBiTree(BiTreeStack &S, BiTree &e);

char Precede(char t1, char t2);

int In(char c);

int GetValue(char theta, int a, int b);

void CreateExpTree(BiTree &T, BiTree a, BiTree b, char ch);

#endif //BINARYTREECOMPUTEEXP_COMPUTEEXPRESSION_H