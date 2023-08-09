#include "SSTable.h"
#include <iostream>

int InitList_SSTable(SSTable &L) {
    L.R = new Data[MAXSIZE];
    if (!L.R) {
        std::cout << "初始化错误";
        return 0;
    }

    L.length = 0;
    return OK;
}

int Insert_SSTable(SSTable &L) {
    int j = 1;                          // 空出ST.R[0]的位置

    for (int i = 1; i < MAXSIZE; i++) {
        L.R[i].key = j;
        L.length++;
        j++;
    }
    return 1;
}

void Show_End(int result, int TestKey) {
    if (result == 0)
        std::cout << "未找到" << TestKey << std::endl;
    else
        std::cout << "找到" << TestKey << "位置为" << result << std::endl;
}