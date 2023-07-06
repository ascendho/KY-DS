#ifndef EXERCISE_SQSTACKWITHTAG_H
#define EXERCISE_SQSTACKWITHTAG_H

#include "../../Status/Status.h"

typedef struct {
    QElemType *base;
    int front, rear, tag;
} SqQueueWithTag;

Status InitQueue(SqQueueWithTag &Q);                   //构造一个空队列
Status EnQueue(SqQueueWithTag &Q, QElemType e);       //插入元素e为Q的新的队尾元素
Status DeQueue(SqQueueWithTag &Q, QElemType &e);     //删除Q的队头元素，用e返回其值

#endif //EXERCISE_SQSTACKWITHTAG_H