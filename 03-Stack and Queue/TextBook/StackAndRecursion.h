#ifndef INC_03_STACK_AND_QUEUE_STACKANDRECURSION_H
#define INC_03_STACK_AND_QUEUE_STACKANDRECURSION_H

#include "../../02-Linear List/TextBook/LinkList.h"

long Fib(long n);

long Fib_iteration(long n);

long Fact(long n);

long Fact_iteration(long n);

void TraverseList(LinkList p);

void move(char A, int n, char C);

void Hanoi(int n, char A, char B, char C);

//（m是初值为0的全局变量，对搬动计数）
int m = 0;

void Visit(LinkList p);

#endif //INC_03_STACK_AND_QUEUE_STACKANDRECURSION_H
