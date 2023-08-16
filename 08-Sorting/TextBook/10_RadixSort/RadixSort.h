#ifndef INC_10_RADIXSORT_RADIXSORT_H
#define INC_10_RADIXSORT_RADIXSORT_H

#include "SLList.h"


void RadixSort(SLList &L);

void Distribute(SLCell *r, int i, ArrType &f, ArrType &e);

void Collect(SLCell *r, int i, ArrType &f, ArrType &e);

int ord(char c);

int succ(int i);

#endif //INC_10_RADIXSORT_RADIXSORT_H
