#include "Deque.h"
#include <iostream>

// 创建队列
Status InitQueue(SqQueueWithTag &Q) {
    Q.base = new QElemType[MAXQSIZE];
    if (!Q.base) return OVERFLOW;

    Q.front = Q.rear = 0;
    return OK;
}

// 在Q的队头插入新元素e
Status EnQueue(SqQueueWithTag &Q, QElemType e) {
    // 队满
    if (Q.rear == (Q.front - 1 + MAXQSIZE) % MAXQSIZE)
        return ERROR;

    // 新元素插入队头
    Q.base[Q.front] = e;

    // 修改头指针
    Q.front = (Q.front - 1 + MAXQSIZE) % MAXQSIZE;
    return OK;
}

// 删除Q的队尾元素，用e返回其值
Status DeQueue(SqQueueWithTag &Q, QElemType &e) {
    // 队空
    if (Q.front == Q.rear)
        return ERROR;

    // 保存队尾元素
    e = Q.base[Q.rear];

    // 尾指针减1
    Q.rear = (Q.rear - 1 + MAXQSIZE) % MAXQSIZE;
    return OK;
}