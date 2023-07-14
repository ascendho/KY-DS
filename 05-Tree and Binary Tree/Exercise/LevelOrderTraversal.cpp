#include "LevelOrderTraversal.h"

// 层次遍历二叉树，并统计度为1的结点的个数

int LevelOrderTraverse(BiTree T) {
    // num为1的结点的个数
    int num = 0;
    if (T) {
        // Q是以二叉树结点指针为元素的队列,初始化为空
        Queue Q;
        InitQueue(Q);

        // 根结点进队
        EnQueue(Q, T);

        while (!QueueEmpty(Q)) {
            BiTree p = DeQueue(Q);                      // p出队,访问结点
            if ((p->lchild && !p->rchild) || (!p->lchild && p->rchild))
                num++;                                     // 度为1的结点，计数加1
            if (p->lchild) EnQueue(Q, p->lchild);    // 非空左子女入队
            if (p->rchild) EnQueue(Q, p->rchild);    // 非空右子女入队
        }
    }
    return num;
}