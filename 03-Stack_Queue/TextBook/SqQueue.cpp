#include "SqQueue.h"
#include <iostream>

// 算法3.11　循环队列的初始化
// 构造一个空队列Q

Status InitQueue(SqQueue &Q) {
    // 为队列分配一个最大容量为MAXSIZE的数组空间
    Q.base = new QElemType[MAXQSIZE];

    if (!Q.base)
        exit(OVERFLOW); //存储分配失败

    // 头指针和尾指针置为零，队列为空
    Q.front = Q.rear = 0;
    return OK;
}

// 算法3.12　求循环队列的长度
// 返回Q的元素个数，即队列的长度

int QueueLength(SqQueue Q) {
    return (Q.rear - Q.front + MAXQSIZE) % MAXQSIZE;
}

Status EnQueue(SqQueue &Q, QElemType e) {
    // 尾指针在循环意义上加1后等于头指针，表明队满
    if ((Q.rear + 1) % MAXQSIZE == Q.front)
        return ERROR;

    // 新元素插入队尾
    Q.base[Q.rear] = e;

    // 队尾指针加1
    Q.rear = (Q.rear + 1) % MAXQSIZE;
    return OK;
}

// 算法3.14　循环队列的出队
// 删除Q的队头元素，用e返回其值

Status DeQueue(SqQueue &Q, QElemType &e) {
    // 队空
    if (Q.front == Q.rear)
        return ERROR;

    // 保存队头元素
    e = Q.base[Q.front];

    // 队头指针加1
    Q.front = (Q.front + 1) % MAXQSIZE;
    return OK;
}

// 算法3.15　取循环队列的队头元素
// 返回Q的队头元素，不修改队头指针

SElemType GetHead(SqQueue Q) {
    // 队列非空
    if (Q.front != Q.rear)
        return Q.base[Q.front]; //返回队头元素的值，队头指针不变

    exit(OVERFLOW);
}