#include <iostream>
#include "LinkQueue.h"

// 算法3.16　链队的初始化
// 构造一个空队列Q

Status InitQueue(LinkQueue &Q) {
    // 生成新结点作为头结点, 队头和队尾指针指向此结点
    Q.front = Q.rear = new QNode;

    // 头结点的指针域置空
    Q.front->next = nullptr;
    return OK;
}

// 算法3.17　链队的入队
// 插入元素e为Q的新的队尾元素

Status EnQueue(LinkQueue &Q, QElemType e) {
    // 为入队元素分配结点空间, 用指针p指向
    QueuePtr p = new QNode;

    p->data = e;          // 将新结点数据域置为e
    p->next = nullptr;

    Q.rear->next = p;     // 将新结点插入到队尾
    Q.rear = p;           // 修改队尾指针
    return OK;
}

// 算法3.18　链队的出队
// 删除Q的队头元素, 用e返回其值

Status DeQueue(LinkQueue &Q, QElemType &e) {
    // 若队列空, 则返回ERROR
    if (Q.front == Q.rear)
        return ERROR;

    // p指向队头元素
    QueuePtr p = Q.front->next;
    e = p->data;                // e保存队头元素的值
    Q.front->next = p->next;    // 修改头指针

    // 最后一个元素被删, 队尾指针指向头结点
    if (Q.rear == p)
        Q.rear = Q.front;

    // 释放原队头元素的空间
    delete p;
    return OK;
}

// 算法3.19　取链队的队头元素
// 返回Q的队头元素, 不修改队头指针

SElemType GetHead(LinkQueue Q) {
    // 队列非空
    if (Q.front != Q.rear)
        return Q.front->next->data;   // 返回队头元素的值, 队头指针不变

    exit(OVERFLOW);
}