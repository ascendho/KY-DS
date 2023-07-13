#include "BiNode.h"
#include <iostream>

// 中序遍历二叉树T的递归算法

void InOrderTraverse(BiTree T) {
    if (T) {
        InOrderTraverse(T->lchild);
        std::cout << T->data;
        InOrderTraverse(T->rchild);
    }
}