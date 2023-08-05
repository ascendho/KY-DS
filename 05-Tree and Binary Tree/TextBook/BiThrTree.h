#ifndef TEXTBOOK_BITHRTREE_H
#define TEXTBOOK_BITHRTREE_H

#include "../../Status/Status.h"

// 二叉树的二叉线索存储表示
typedef struct BiThrNode {
    TElemType data;
    struct BiThrNode *lchild, *rchild;     // 左右孩子指针
    int LTag, RTag;                        // 左右标志
} BiThrNode, *BiThrTree;

void InThreading(BiThrTree p);

void InOrderThreading(BiThrTree &Thrt, BiThrTree T);

void InOrderTraverse_Thr(BiThrTree T);

// 只给出声明, 不给出具体定义
void Visit(BiThrTree T);

#endif //TEXTBOOK_BITHRTREE_H