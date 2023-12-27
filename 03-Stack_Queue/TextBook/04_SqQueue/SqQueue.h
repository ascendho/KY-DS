#ifndef INC_03_STACK_AND_QUEUE_SQQUEUE_H
#define INC_03_STACK_AND_QUEUE_SQQUEUE_H

#include "../../../Status/Status.h"

typedef struct {
    QElemType *base;  // 初始化时动态分配存储空间
    int front;        // 头指针
    int rear;         // 尾指针
} SqQueue;

Status InitQueue(SqQueue &Q);

int QueueLength(SqQueue Q);

Status EnQueue(SqQueue &Q, QElemType e);

Status DeQueue(SqQueue &Q, QElemType &e);

SElemType GetHead(SqQueue Q);

#endif //INC_03_STACK_AND_QUEUE_SQQUEUE_H