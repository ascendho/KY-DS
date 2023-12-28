#ifndef INC_03_STACK_AND_QUEUE_DANCEPARTNER_H
#define INC_03_STACK_AND_QUEUE_DANCEPARTNER_H

#include "../../../Status/Status.h"

typedef struct {
    char name[20]; // 姓名
    char sex;      // 性别，'F'表示女性，'M'表示男性
} Person;

typedef struct {
    Person *base;
    int front;
    int rear;
} SqQueue;

SqQueue Mdancers, Fdancers;

Status InitQueue(SqQueue &Q);

Status EnQueue(SqQueue &Q, Person e);

Status QueueEmpty(SqQueue Q);

Status DeQueue(SqQueue &Q, Person &e);

Person GetHead(SqQueue Q);

void DancePartner(Person dancer[], int num);

#endif //INC_03_STACK_AND_QUEUE_DANCEPARTNER_H