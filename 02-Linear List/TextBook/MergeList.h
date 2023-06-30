#ifndef INC_02_LINEAR_LIST_MERGELIST_H
#define INC_02_LINEAR_LIST_MERGELIST_H

#include<iostream>
#include<fstream>

using namespace std;

#include "../../Status/Status.h"
#include "SqList.h"
#include "LinkList.h"

void MergeList_Sq(SqList LA, SqList LB, SqList &LC);

void MergeList_L(LinkList &LA, LinkList &LB, LinkList &LC);

#endif //INC_02_LINEAR_LIST_MERGELIST_H