#ifndef INC_02_LINEAR_LIST_CLINKLIST_H
#define INC_02_LINEAR_LIST_CLINKLIST_H

#include "../../Status/Status.h"
#include "LinkList.h"

typedef LinkList CLinkList;
typedef LNode CLNode;

Status InitCList(CLinkList &L);

Status EmptyOfCList(CLinkList L);

Status isTail(CLinkList L, CLNode *p);

#endif //INC_02_LINEAR_LIST_CLINKLIST_H
