#ifndef SLINKLIST_SLINKLIST_H
#define SLINKLIST_SLINKLIST_H

#include "../../../Status/Status.h"

typedef struct {
    ElemType data;
    int cur;         // 游标
} component, SLinkList[MAXSIZE];

int LocateElem_SL(SLinkList S, ElemType e);

void InitSpace_SL(SLinkList space);

int Malloc_SL(SLinkList &space);

void Free_SL(SLinkList &space, int k);

#endif //SLINKLIST_SLINKLIST_H