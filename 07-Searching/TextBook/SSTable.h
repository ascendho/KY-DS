#ifndef TEXTBOOK_SSTABLE_H
#define TEXTBOOK_SSTABLE_H

#include "../../Status/Status.h"

typedef struct {
    KeyType key;            // 关键字域
    InfoType otherinfo;     // 其他域
} Data;

typedef struct {
    Data *R;
    int length;
} SSTable;

int InitList_SSTable(SSTable &L);

int Insert_SSTable(SSTable &L);

void Show_End(int result, int TestKey);

#endif //TEXTBOOK_SSTABLE_H
