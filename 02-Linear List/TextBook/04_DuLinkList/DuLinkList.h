#ifndef INC_02_LINEAR_LIST_DULINKLIST_H
#define INC_02_LINEAR_LIST_DULINKLIST_H

#include "../../../Status/Status.h"

typedef struct DuLNode {
    ElemType data;         // 数据域
    struct DuLNode *prior; // 直接前驱
    struct DuLNode *next;  // 直接后继
} DuLNode, *DuLinkList;

Status ListInsert_DuL(DuLinkList &L, int i, ElemType e);

Status ListDelete_DuL(DuLinkList &L, int i);

DuLNode *GetElemP_DuL(DuLinkList L, int i);

#endif //INC_02_LINEAR_LIST_DULINKLIST_H