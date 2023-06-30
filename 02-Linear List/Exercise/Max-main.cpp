#include <iostream>
#include "Max.h"

using namespace std;

int main() {
    // 解决输出中文乱码问题
    system("chcp 65001");

    // 链表数据
    int laData[] = {2, -6, 8, 9, -11, 15, -20};

    // 初始化链表
    LinkList la;
    InitLinkList(la);

    // 后插法创建链表
    CreateList_R(la, laData, sizeof(laData) / sizeof(laData[0]));

    // 取最大值
    int lamax = Max(la)->data;
    cout << "链表la中的最大值为: " << lamax << endl;

    // 销毁链表
    DestroyList(la);

    return 0;
}