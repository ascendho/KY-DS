#include "CLinkList.h"

// 初始化一个循环单链表
Status InitCList(CLinkList &L) {
    L = new CLNode;
    // 内存可能不足，分配失败
    L->next = L;

    return OK;
}

// 判断循环单链表是否为空
Status EmptyOfCList(CLinkList L) {
    if (L->next == L)
        return OK;

    return ERROR;
}

// 判断结点p是否为循环单链表的表尾结点
Status isTail(CLinkList L, CLNode *p) {
    if (p->next == L)
        return OK;

    return ERROR;
}
