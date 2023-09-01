#ifndef TEXTBOOK_DATALIST_H
#define TEXTBOOK_DATALIST_H

#include "../../../Status/Status.h"

typedef struct {
    KeyType key;            // 关键字项
    InfoType *otherinfo;    // 其他数据项
} RecType;                  // 记录类型 (注: 教材中命名为RedType, 考虑到Red本身就是一个完整的单词容易引起"混乱", 故这里用'Rec'代表'Record')


// 数据表的存储结构
typedef struct {
    RecType r[MAXSIZE + 1]; // r[0]闲置或用做哨兵单元
    int length;             // 数据表长度
} DataList;                 // 数据表类型 (注: 教材中命名为SqList, 考虑到容易跟第二章的顺序表引起"混淆", 故这里命名为数据表(DataList))

void CreateList(DataList &L);

void show(DataList L);

#endif //TEXTBOOK_DATALIST_H