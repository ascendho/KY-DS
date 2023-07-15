#ifndef TEXTBOOK_BITHRNODE_H
#define TEXTBOOK_BITHRNODE_H

#include "../../Status/Status.h"

// 二叉树的二叉线索存储表示
typedef struct BiThrNode {
    TElemType data;
    struct BiThrNode *lchild, *rchild;     // 左右孩子指针
    int LTag, RTag;                        // 左右标志
} BiThrNode, *BiThrTree;

#endif //TEXTBOOK_BITHRNODE_H