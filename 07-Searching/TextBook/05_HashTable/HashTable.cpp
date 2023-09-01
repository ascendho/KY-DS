#include "HashTable.h"

#define Length 16     // 哈希表的表长

// 算法7.10 为哈希表查找的算法，采用线性探测法处理冲突
// 在哈希表HT中查找关键字为key的元素，若查找成功，返回哈希表的单元标号，否则返回-1

int SearchHash(HashTable HT[], KeyType key) {
    int H0 = H(key);                                    // 根据哈希函数H（key）计算哈希地址
    if (HT[H0].key == NULLKEY)                          // 若单元H0为空，则所查元素不存在
        return -1;
    else if (HT[H0].key == key)
        return H0;                                      // 若单元H0中元素的关键字为key，则查找成功
    else {
        for (int i = 1; i < Length; ++i) {
            int Hi = (H0 + i) % Length;                 // 按照线性探测法计算下一个哈希地址Hi
            if (HT[Hi].key == NULLKEY)
                return -1;                              // 若单元Hi为空，则所查元素不存在
            else if (HT[Hi].key == key)
                return Hi;                              // 若单元Hi中元素的关键字为key，则查找成功
        }
        return -1;
    }
}

int H(KeyType key) {
    return key % 13;
}