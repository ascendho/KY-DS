#ifndef INC_09_MERGESORT_MERGESORT_H
#define INC_09_MERGESORT_MERGESORT_H

#include "../DataList/DataList.h"

void Merge(RecType R[], RecType T[], int low, int mid, int high);

void MSort(RecType R[], RecType T[], int low, int high);

void MergeSort(DataList &L);

#endif //INC_09_MERGESORT_MERGESORT_H