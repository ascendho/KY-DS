#ifndef INC_05_QUICKSORT_QUICKSORT_H
#define INC_05_QUICKSORT_QUICKSORT_H

#include "../DataList/DataList.h"

void QuickSort(DataList &L);

void QSort(DataList &L, int low, int high);

int Partition(DataList &L, int low, int high);

#endif //INC_05_QUICKSORT_QUICKSORT_H