#ifndef INC_3_6_LINKQUEUE_LINKQUEUE_H
#define INC_3_6_LINKQUEUE_LINKQUEUE_H

#include "../../../Status/Status.h"

// 循环队列的链式存储结构
typedef struct QNode {
    QElemType data;
    struct QNode *next;
} QNode, *QueuePtr;

typedef struct {
    QueuePtr rear;                                    // 只设一个尾指针
} LinkQueue;


void InitQueue(LinkQueue &Q);                       // 置空队列
int EmptyQueue(LinkQueue Q);                        // 判断队列是否为空
Status EnQueue(LinkQueue &Q, QElemType e);          // 入队
Status DeQueue(LinkQueue &Q, QElemType &e);         // 出队
void Init(LinkQueue &Q);                            // 建立队列

#endif //INC_3_6_LINKQUEUE_LINKQUEUE_H