#ifndef SIXDEGREESEPARATION_SIXDEGREE_BFS_H
#define SIXDEGREESEPARATION_SIXDEGREE_BFS_H

#include "../../TextBook/Graph.h"
#include <iostream>

#define Mod 10
#define N 10010
#define M 1000010

struct Node {        //存储点的结构体
    int id;
    int step;
};
struct sqQueue {        //队列的结构体
    Node *base;
    int front;
    int rear;
};

sqQueue Q;

void InitQueue(sqQueue &Q) {    //初始化队列
    Q.base = new Node[M];
    if (!Q.base)
        exit(OVERFLOW);
    Q.front = Q.rear = 0;
    return;
}

int QueueLength(sqQueue Q) {        //求队列的长度
    return (Q.rear - Q.front + M) % M;
}

int EnQueue(sqQueue &Q, Node e) {    //入队
    if ((Q.rear + 1) % M == Q.front)
        return 0;
    Q.base[Q.rear] = e;
    Q.rear = (Q.rear + 1) % M;
    return 1;
}

int DeQueue(sqQueue &Q) {        //出队
    if (Q.front == Q.rear)
        return 0;
    Q.front = (Q.front + 1) % M;
    return 1;
}

Node getHead(sqQueue Q) {    //得到队列头部的元素
    return Q.base[Q.front];
}

#endif //SIXDEGREESEPARATION_SIXDEGREE_BFS_H
