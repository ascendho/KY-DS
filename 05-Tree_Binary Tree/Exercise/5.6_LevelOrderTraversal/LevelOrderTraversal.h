#ifndef EXERCISE_LEVELORDERTRAVERSAL_H
#define EXERCISE_LEVELORDERTRAVERSAL_H

#include "../../TextBook/01_BiTree/BiTree.h"

int LevelOrderTraverse(BiTree T);

// 定义队列节点结构体
typedef struct LNode {
    BiTree data;
    struct LNode *next;
} LNode, *Queue;

// 初始化队列
void InitQueue(Queue &Q) {
    Q = new LNode;
    Q->next = Q;
}

// 二叉树节点入队
void EnQueue(Queue &Q, BiTree e) {
    Queue p = new LNode;
    p->data = e;
    p->next = Q->next;
    Q->next = p;
}

// 二叉树节点出队
BiTree DeQueue(Queue &Q) {
    Queue q = Q->next;
    Q->next = q->next;
    if (q == Q)
        Q = Q->next;
    return q->data;
}

// 检测队列是否为空
int QueueEmpty(Queue Q) {
    return Q->next == Q ? 1 : 0;
}

#endif //EXERCISE_LEVELORDERTRAVERSAL_H