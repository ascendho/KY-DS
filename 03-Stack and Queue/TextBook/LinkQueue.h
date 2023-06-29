#ifndef INC_03_STACK_AND_QUEUE_LINKQUEUE_H
#define INC_03_STACK_AND_QUEUE_LINKQUEUE_H

// 链队的基本操作

#include "../../Status/Status.h"

// 队列的链式存储结构
typedef struct QNode {
    QElemType data;
    struct QNode *next;
} QNode, *QueuePtr;

typedef struct {
    QueuePtr front;   //队头指针
    QueuePtr rear;    //队尾指针
} LinkQueue;

Status InitQueue(LinkQueue &Q);

Status EnQueue(LinkQueue &Q, QElemType e);

Status DeQueue(LinkQueue &Q, QElemType &e);

SElemType GetHead(LinkQueue Q);

#endif //INC_03_STACK_AND_QUEUE_LINKQUEUE_H