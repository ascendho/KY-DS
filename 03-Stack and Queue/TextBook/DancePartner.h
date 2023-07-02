#ifndef INC_03_STACK_AND_QUEUE_DANCEPARTNER_H
#define INC_03_STACK_AND_QUEUE_DANCEPARTNER_H

#include "SqQueue.h"

typedef struct {
    char name[20]; //姓名
    char sex; //性别，'F'表示女性，'M'表示男性
} Person;

void DancePartner(Person dancer[], int num);

#endif //INC_03_STACK_AND_QUEUE_DANCEPARTNER_H