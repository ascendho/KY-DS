#include "DancePartner.h"
#include <iostream>

// 算法3.23 舞伴问题

// 时间复杂度: O(n)
// 空间复杂度: O(n)

void DancePartner(Person dancer[], int num) {
    // 结构数组dancer中存放跳舞的男女姓名, num是跳舞的人数
    InitQueue(Mdancers);
    InitQueue(Fdancers);

    Person p;
    // 依次将跳舞者根据其性别入队
    for (int i = 0; i < num; i++) {
        p = dancer[i];
        if ('F' == p.sex)
            EnQueue(Fdancers, p);
        else
            EnQueue(Mdancers, p);
    }

    std::cout << "The dancing partners are:\n";

    // 依次输出男女舞伴的姓名
    while (!QueueEmpty(Fdancers) && !QueueEmpty(Mdancers)) {
        DeQueue(Fdancers, p);
        std::cout << p.name << " ";
        DeQueue(Mdancers, p);
        std::cout << p.name << std::endl;
    }

    // 女士队列非空, 输出队头女士的姓名
    if (!QueueEmpty(Fdancers)) {
        p = GetHead(Fdancers);
        std::cout << "The first woman to get a partner is: " << p.name << std::endl;
    }
    // 男士队列非空, 输出队头男士的姓名
    else if (!QueueEmpty(Mdancers)) {
        p = GetHead(Mdancers);
        std::cout << "The first man to get a partner is: " << p.name << std::endl;
    }
}

Status InitQueue(SqQueue &Q) {
    Q.base = new Person[MAXQSIZE];

    if (!Q.base)
        exit(OVERFLOW);

    Q.front = Q.rear = 0;

    return OK;
}

Status EnQueue(SqQueue &Q, Person e) {
    if ((Q.rear + 1) % MAXQSIZE == Q.front)
        return ERROR;

    Q.base[Q.rear] = e;

    Q.rear = (Q.rear + 1) % MAXQSIZE;
    return OK;
}

Status QueueEmpty(SqQueue Q) {
    if (Q.front == Q.rear)
        return OK;
    return ERROR;
}

Status DeQueue(SqQueue &Q, Person &e) {
    if (Q.front == Q.rear)
        return ERROR;

    e = Q.base[Q.front];

    Q.front = (Q.front + 1) % MAXQSIZE;
    return OK;
}

Person GetHead(SqQueue Q) {
    if (Q.front != Q.rear)
        return Q.base[Q.front];  // 返回队头元素的值, 队头指针不变

    exit(OVERFLOW);
}