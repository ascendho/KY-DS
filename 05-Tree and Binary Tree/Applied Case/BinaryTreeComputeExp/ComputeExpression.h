#ifndef BINARYTREECOMPUTEEXP_COMPUTEEXPRESSION_H
#define BINARYTREECOMPUTEEXP_COMPUTEEXPRESSION_H

#include "../../../03-Stack and Queue/TextBook/SqStack.h"
#include "BiTreeStack.h"

void InitExpTree(BiTree &T);

int EvaluateExTree(BiTree T);

void CreateExpTree(BiTree &T, BiTree a, BiTree b, char ch);

char Precede(char t1, char t2);

int In(char c);

int GetValue(char theta, int a, int b);

#endif //BINARYTREECOMPUTEEXP_COMPUTEEXPRESSION_H