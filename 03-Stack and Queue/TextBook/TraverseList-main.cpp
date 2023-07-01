#include <iostream>
#include "TraverseList.h"

using namespace std;

int main() {
    // 解决中文乱码问题
    system("chcp 65001");

    int n;
    cout << "请输入元素个数: " << endl;
    cin >> n;

    LinkList L;
    cout << "请输入链表元素(以空格隔开，按回车结束): " << endl;

    // 后插法创建链表算法
    CreateList_R(L, n);

    cout << "链表中的元素依次为: " << endl;
    TraverseList(L->next);

    cout << endl;
    return 0;
}