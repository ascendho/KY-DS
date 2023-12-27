#ifndef INC_02_LINEAR_LIST_POLYNOMIAL_H
#define INC_02_LINEAR_LIST_POLYNOMIAL_H

#include "../../../Status/Status.h"

typedef struct PNode {
    float coef;           // 系数
    int expn;             // 指数
    struct PNode *next;
} PNode, *Polynomial;

void CreatPolyn(Polynomial &P, int n);

void AddPolyn(Polynomial &Pa, Polynomial &Pb);

#endif //INC_02_LINEAR_LIST_POLYNOMIAL_H