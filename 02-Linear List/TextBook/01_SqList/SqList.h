#ifndef INC_02_LINEAR_LIST_SQLIST_H
#define INC_02_LINEAR_LIST_SQLIST_H

#include "../../../Status/Status.h"

typedef struct {
    ElemType *elem;  // 存储空间的基地址
    int length;      // 当前长度
} SqList;

Status InitSqList(SqList &L);

Status GetSqListElem(SqList L, int i, ElemType &e);

int LocateSqElem(SqList L, ElemType e);

Status SqListInsert(SqList &L, int i, ElemType e);

Status SqListDelete(SqList &L, int i, ElemType &e);

void IncreaseSize(SqList &L, int len);

int SqListLength(SqList L);

Status ElemIsInSqList(SqList L, ElemType e);

#endif //INC_02_LINEAR_LIST_SQLIST_H