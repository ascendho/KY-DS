#include<iostream>
#include "SqList.h"

// 算法2.1 顺序表的初始化

Status InitSqList(SqList &L) {
    // 为顺序表分配一个大小为MAXSIZE的数组空间
    L.elem = new ElemType[MAXSIZE];

    // 存储分配失败退出
    if (!L.elem)
        exit(OVERFLOW);

    // 空表长度为0
    L.length = 0;
    return OK;
}

// 算法2.2　顺序表的取值(按位序查找)

// 时间复杂度：O(1)

Status GetSqListElem(SqList L, int i, ElemType &e) {
    // 判断i值是否合理，若不合理，返回ERROR
    if (i < 1 || i > L.length)
        return ERROR;

    // elem[i-1]单元存储第i个数据元素
    e = L.elem[i - 1];
    return OK;
}

// 算法2.3 顺序表的查找(按值查找)

// 平均查找长度(ASL): (n+1)/2
// 时间复杂度：O(n) [若有序, O(log)]

int LocateSqElem(SqList L, ElemType e) {
    // 查找成功，返回序号i+1
    for (int i = 0; i < L.length; i++)
        if (L.elem[i] == e)
            return i + 1;

    // 查找失败，返回0
    return 0;
}

// 算法2.4 顺序表的插入

// 移动元素次数的期望值E(平均次数): n/2
// 时间复杂度：O(n)

Status SqListInsert(SqList &L, int i, ElemType e) {
    // i值的合法范围是[1,L.length+1]
    if ((i < 1) || (i > L.length + 1))
        return ERROR;

    // 当前存储空间已满
    if (L.length == MAXSIZE)
        return ERROR;

    // 插入位置及之后的元素后移
    for (int j = L.length - 1; j >= i - 1; j--)
        L.elem[j + 1] = L.elem[j];

    // 将新元素e放入第i个位置
    L.elem[i - 1] = e;

    // 表长增1
    ++L.length;
    return OK;
}

// 算法2.5 顺序表的删除

// E: (n-1)/2
// 时间复杂度: O(n)

// 注：当删除的是表尾的元素时，表尾元素还在内存中，只是在“逻辑上”消失了
Status SqListDelete(SqList &L, int i, ElemType &e) {
    // i值的合法范围是[1,L.length](已包含L.length==0的情况，故无需再判断)
    if ((i < 1) || (i > L.length))
        return ERROR;

    // 带回将被删除的数据元素
    e = L.elem[i - 1];

    // 被删除元素之后的元素前移
    for (int j = i; j <= L.length - 1; j++)
        L.elem[j - 1] = L.elem[j];

    // 表长减1
    --L.length;
    return OK;
}

/* 王道课程补充算法 */

// 增加动态数组的长度
// 时间复杂度：O(n)

void IncreaseSize(SqList &L, int len) {
    ElemType *p = L.elem;
    // 注意需要MAXSIZE+len这么大的连续的新空间，而不是只需要len个新空间
    L.elem = new int[MAXSIZE + len];

    // 将数据复制到新区域
    for (int i = 0; i < L.length; i++)
        L.elem[i] = p[i];

    // 释放原来的内存空间
    delete p;
}

// 求顺序表的长度

int SqListLength(SqList L) {
    return L.length;
}

// 判断List里有没有e这个元素
Status ElemIsInSqList(SqList L, ElemType e) {
    for (int i = 0; i < L.length; i++)
        if (e == L.elem[i])
            return OK;
    return ERROR;
}