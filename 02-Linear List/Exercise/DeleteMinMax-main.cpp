#include <iostream>
#include "DeleteMinMax.h"

using namespace std;

int main() {
    // 解决输出中文乱码问题
    system("chcp 65001");

    // 链表数据
    int laData[] = {2, 6, 8, 9, 11, 15, 20};

    // 尾插法创建链表
    LinkList la;
    CreateList_R(la, laData, sizeof(laData) / sizeof(laData[0]));

    int min = 7, max = 11;
    DeleteMinMax(la, min, max);
    cout << "链表la删除介于" << min << "到" << max << "之间的元素后变为: ";

    PrintList(la);

    // 销毁链表
    DestroyList(la);

    return 0;
}