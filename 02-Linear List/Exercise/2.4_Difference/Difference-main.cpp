#include <iostream>
#include "Difference.h"

using namespace std;

int main() {
    // 解决输出中文乱码问题
    system("chcp 65001");

    // 测试数据
    int laData[] = {3, 5, 8, 11};
    int lbData[] = {2, 6, 8, 9, 11, 15, 20};

    // 尾插法创建链表
    LinkList la, lb;
    CreateList_R(la, laData, sizeof(laData) / sizeof(laData[0]));
    CreateList_R(lb, lbData, sizeof(lbData) / sizeof(lbData[0]));

    int n = 0;
    Difference(la, lb, n);

    cout << "差运算后的线性表为: ";
    PrintList(la);
    cout << "该集合的元素个数为: " << n << endl;

    // 销毁链表
    DestroyList(la);
    DestroyList(lb);

    return 0;
}