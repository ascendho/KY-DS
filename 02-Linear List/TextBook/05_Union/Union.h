#ifndef INC_02_LINEAR_LIST_UNION_H
#define INC_02_LINEAR_LIST_UNION_H

#include "../../../Status/Status.h"
#include "../02_LinkList/LinkList.h"
#include "../01_SqList/SqList.h"

//算法2.15 线性表的并集（链表）
void UnionList(LinkList &LA, LinkList LB);

//算法2.15 线性表的并集（顺序表）
void UnionList(SqList &LA, SqList LB);

#endif //INC_02_LINEAR_LIST_UNION_H