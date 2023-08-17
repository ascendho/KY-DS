#ifndef INC_08_HEAPSORT_HEAPSORT_H
#define INC_08_HEAPSORT_HEAPSORT_H

#include "../DataList.h"

void HeapAdjust(DataList &L, int s, int m);

void CreatHeap(DataList &L);

void HeapSort(DataList &L);

#endif //INC_08_HEAPSORT_HEAPSORT_H