#include "Triplet.h"
#include <iostream>

// 构造三元组T, 依次置T的3个元素的初值为v1, v2和v3
Status InitTriplet(Triplet &T, ElemType v1, ElemType v2, ElemType v3) {
    T = (ElemType *) malloc(3 * sizeof(ElemType));
    if (!T)
        exit(OVERFLOW);
    T[0] = v1, T[1] = v2, T[2] = v3;
    return OK;
}

// 销毁三元组
Status DestroyTriplet(Triplet &T) {
    free(T);
    T = nullptr;
    return OK;
}

// 1<=i<=3, 用e返回T的第i元的值
Status Get(Triplet T, int i, ElemType &e) {
    if (i < 1 || i > 3)
        return ERROR;
    e = T[i - 1];
    return OK;
}

// 1<=i<=3, 置T的第i元的值为e
Status Put(Triplet T, int i, ElemType e) {
    if (i < 1 || i > 3)
        return ERROR;
    T[i - 1] = e;
    return OK;
}

// 判断三元组是否按照升序排列
Status IsAscending(Triplet T) {
    return (T[0] <= T[1] && T[1] <= T[2]);
}

// 判断三元组是否按照降序排列
Status IsDescending(Triplet T) {
    return (T[0] >= T[1] && T[1] >= T[2]);
}

// 用e返回指向三元组最大元素的值
Status Max(Triplet T, ElemType &e) {
    e = (T[0] >= T[1]) ? (T[0] >= T[2] ? T[0] : T[2]) : (T[1] >= T[2] ? T[1] : T[2]);
    return OK;
}

// 用e返回指向三元组最小元素的值
Status Min(Triplet T, ElemType &e) {
    e = (T[0] <= T[1]) ? (T[0] <= T[2] ? T[0] : T[2]) : (T[1] <= T[2] ? T[1] : T[2]);
    return OK;
}