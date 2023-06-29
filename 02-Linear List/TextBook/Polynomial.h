#ifndef INC_02_LINEAR_LIST_POLYNOMIAL_H
#define INC_02_LINEAR_LIST_POLYNOMIAL_H

#include<iostream>
#include<string>
#include<fstream>

using namespace std;

#include "../../Status/Status.h"

typedef struct PNode {
    float coef;           //系数
    int expn;             //指数
    struct PNode *next;
} PNode, *Polynomial;

//算法2.18 多项式的创建
void CreatPolyn(Polynomial &P, int n);

//算法2.19 多项式的相加
void AddPolyn(Polynomial &Pa, Polynomial &Pb);

// 减法

// 乘法


#endif //INC_02_LINEAR_LIST_POLYNOMIAL_H
