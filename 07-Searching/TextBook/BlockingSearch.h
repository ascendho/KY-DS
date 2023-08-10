#ifndef TEXTBOOK_BLOCKINGSEARCH_H
#define TEXTBOOK_BLOCKINGSEARCH_H

#include "../../Status/Status.h"
#include "SSTable.h"

// 索引表
typedef struct {
    KeyType maxValue;     // 块最大值
    int low, high;        // 块区间
} IndexTable;

// 数据
Data data[100];

#endif //TEXTBOOK_BLOCKINGSEARCH_H