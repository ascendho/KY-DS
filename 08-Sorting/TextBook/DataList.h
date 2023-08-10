#ifndef TEXTBOOK_DATALIST_H
#define TEXTBOOK_DATALIST_H

#include "../../Status/Status.h"

typedef struct {
    KeyType key;           // 关键字项
    InfoType *otherinfo;   // 其他数据项
} Data;                    // 记录类型

// 数据表的存储结构
typedef struct {
    Data r[MAXSIZE + 1];     // r[0]闲置或用做哨兵单元
    int length;              // 数据表长度
} DataList;                  // 数据表类型

void CreateList(DataList &L);

void show(DataList L);

#endif //TEXTBOOK_DATALIST_H