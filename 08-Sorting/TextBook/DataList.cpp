#include "DataList.h"
#include <iostream>

void CreateList(DataList &L) {
    std::cout << "请输入数据个数，不超过" << MAXSIZE << "个。" << std::endl;

    int n;
    std::cin >> n;                                            // 输入个数

    std::cout << "请输入待排序的数据:\n";
    while (n > MAXSIZE) {
        std::cout << "个数超过上限，不能超过" << MAXSIZE << "，请重新输入" << std::endl;
        std::cin >> n;
    }

    for (int i = 1; i <= n; i++) {
        std::cin >> L.r[i].key;
        L.length++;
    }
}

void show(DataList L) {
    for (int i = 1; i <= L.length; i++)
        std::cout << L.r[i].key << std::endl;
}