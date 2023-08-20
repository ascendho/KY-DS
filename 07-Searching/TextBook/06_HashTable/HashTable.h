#ifndef INC_06_HASHTABLE_HASHTABLE_H
#define INC_06_HASHTABLE_HASHTABLE_H

#include "../../../Status/Status.h"

// 开放地址法哈希表的存储表示
struct HashTable {
    KeyType key;                         // 关键字项
    InfoType otherinfo;                  // 其他数据项
};

int SearchHash(HashTable HT[], KeyType key);

int H(KeyType key);

#endif //INC_06_HASHTABLE_HASHTABLE_H