#include "BiNode.h"
#include <iostream>

// 算法5.1
// 中序遍历二叉树T的递归算法

// 时间复杂度: O(n)

void InOrderTraverse(BiTree T) {
    if (T) {
        InOrderTraverse(T->lchild);
        std::cout << T->data;
        InOrderTraverse(T->rchild);
    }
}