#ifndef TEXTBOOK_DISJOINTSET_H
#define TEXTBOOK_DISJOINTSET_H

#include "../../Status/Status.h"

// 集合元素数组
int UFSets[MAXSIZE];

void Initial(int S[]);

int Find(int S[], int x);

void Union(int S[], int Root1, int Root2);

#endif //TEXTBOOK_DISJOINTSET_H