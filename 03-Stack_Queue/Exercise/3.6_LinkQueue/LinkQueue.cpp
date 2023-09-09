#include "LinkQueue.h"

void Init(LinkQueue &Q) {
    Q.rear = new QNode;
    Q.rear->next = Q.rear;
}

// 置空队列
void InitQueue(LinkQueue &Q) {
    Q.rear = Q.rear->next;                    // 将尾指针指向头结点

    // 当列非空时, 将队中元素逐个出队
    while (Q.rear != Q.rear->next) {
        QueuePtr s = Q.rear->next;            // s指向队头元素
        Q.rear->next = s->next;               // 尾结点的指针域指向新的队头元素
        delete s;                             // 释放结点的空间
    }
}

// 判断队是否为空, 空返回1, 否则返回0
int EmptyQueue(LinkQueue Q) {
    // 队列只有一个头结点, 即当头结点的指针域指向自己时, 队列为空
    return Q.rear->next->next == Q.rear->next;
}

// 入队，插入元素e为Q的新的队尾元素
Status EnQueue(LinkQueue &Q, QElemType e) {
    QueuePtr s = new QNode;                   // 申请新结点
    s->data = e;                              // 将新结点数据域置为e

    // 将新结点插入到队尾
    s->next = Q.rear->next;
    Q.rear->next = s;

    // 将尾指针移至新结点
    Q.rear = s;

    return OK;
}

// 出队, 删除Q的队头元素, 用e返回其值
Status DeQueue(LinkQueue &Q, QElemType &e) {
    // 若队列空，则返回ERROR
    if (Q.rear->next->next == Q.rear->next)
        return ERROR;

    QueuePtr p = Q.rear->next->next;             // p指向队头元素
    e = p->data;                                 // e保存队头元素的值
    if (p == Q.rear)                             // 当队列中只有一个结点
    {
        Q.rear = Q.rear->next;                   // 修改尾指针, 使其指向头结点
        Q.rear->next = p->next;
    } else
        Q.rear->next->next = p->next;            // 摘下结点p

    delete p;                                    // 释放原队头元素的空间

    return OK;
}