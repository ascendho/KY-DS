#ifndef TEXTBOOK_BFS_H
#define TEXTBOOK_BFS_H

#include "../../Status/Status.h"
#include "Graph.h"
#include <iostream>

void BFS(Graph G, int v);

// 辅助队列的定义及操作
typedef struct {
    ArcType *base;                            // 初始化的动态分配存储空间
    int front;                                // 头指针，若队列不空，指向队头元素
    int rear;                                 // 尾指针，若队列不空，指向队尾元素的下一个位置
} sqQueue;

void InitQueue(sqQueue &Q) {
    // 构造一个空队列Q
    Q.base = new ArcType[MAXQSIZE];
    if (!Q.base)
        exit(1);                       // 存储分配失败

    Q.front = Q.rear = 0;
}

void EnQueue(sqQueue &Q, ArcType e) {
    // 插入元素e为Q的新的队尾元素
    if ((Q.rear + 1) % MAXQSIZE == Q.front)
        return;

    Q.base[Q.rear] = e;
    Q.rear = (Q.rear + 1) % MAXQSIZE;
}

bool QueueEmpty(sqQueue Q) {
    // 判断是否为空队
    if (Q.rear == Q.front)
        return true;
    return false;
}

void DeQueue(sqQueue &Q, ArcType &u) {
    // 队头元素出队并置为u
    u = Q.base[Q.front];
    Q.front = (Q.front + 1) % MAXQSIZE;
}

#endif //TEXTBOOK_BFS_H