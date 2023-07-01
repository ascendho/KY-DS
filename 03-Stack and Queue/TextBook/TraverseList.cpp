#include "TraverseList.h"
#include<iostream>

/* 依次输出链表中的各个结点 */

//算法3.9　遍历输出链表中各个结点的递归算法
void TraverseList(LinkList p) {
    // 递归终止
    if (p == nullptr)
        return;
    else {
        std::cout << p->data << std::endl;   // 输出当前结点的数据域
        TraverseList(p->next);            // p指向后继指点继续递归
    }
}