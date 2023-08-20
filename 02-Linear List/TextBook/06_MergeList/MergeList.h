#ifndef INC_02_LINEAR_LIST_MERGELIST_H
#define INC_02_LINEAR_LIST_MERGELIST_H

#include "../../../Status/Status.h"
#include "../01_SqList/SqList.h"
#include "../02_LinkList/LinkList.h"

void MergeList_Sq(SqList LA, SqList LB, SqList &LC);

void MergeList_L(LinkList &LA, LinkList &LB, LinkList &LC);

#endif //INC_02_LINEAR_LIST_MERGELIST_H