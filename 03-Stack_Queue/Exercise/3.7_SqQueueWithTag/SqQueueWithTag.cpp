#include "SqQueueWithTag.h"
#include <iostream>

// 构造一个空队列Q
Status InitQueue(SqQueueWithTag &Q) {
    Q.base = new QElemType[MAXQSIZE];
    // 存储分配失败
    if (!Q.base) exit(OVERFLOW);

    // 头指针和尾指针置为零，队列为空
    Q.front = Q.rear = 0;

    // 标志初始化为0，队列为空
    Q.tag = 0;
    return OK;
}

// 插入元素e为Q的新的队尾元素
Status EnQueue(SqQueueWithTag &Q, QElemType e) {
    // 队满
    if ((Q.tag == 1) && (Q.rear == Q.front))
        return ERROR;

    // 新元素插入队尾
    Q.base[Q.rear] = e;

    // 尾指针加1
    Q.rear = (Q.rear + 1) % MAXQSIZE;

    // 标志改1，表示队列非空
    if (Q.tag == 0) Q.tag = 1;
    return OK;
}

// 删除Q的队头元素，用e返回其值
Status DeQueue(SqQueueWithTag &Q, QElemType &e) {
    // 队空
    if ((Q.tag == 0) && (Q.rear == Q.front))
        return ERROR;

    // 保存队头元素
    e = Q.base[Q.front];

    // 头指针加1
    Q.front = (Q.front + 1) % MAXQSIZE;

    // 标志改0，表示队列非满
    if (Q.tag == 1) Q.tag = 0;
    return OK;
}