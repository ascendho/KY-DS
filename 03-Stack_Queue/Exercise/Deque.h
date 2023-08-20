#ifndef EXERCISE_DEQUE_H
#define EXERCISE_DEQUE_H

#include "../../Status/Status.h"

typedef struct {
    QElemType *base;                                 //存储空间的基地址
    int front;                                         //头指针
    int rear;                                         //尾指针
} SqQueueWithTag;

Status EnQueue(SqQueueWithTag &Q, QElemType e);
Status DeQueue(SqQueueWithTag &Q, QElemType &e);
Status InitQueue(SqQueueWithTag &Q);


#endif //EXERCISE_DEQUE_H