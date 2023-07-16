#include "BiNode.h"
#include <iostream>

// 算法5.1
// 中序遍历二叉树T的递归算法

// 时间复杂度: O(n)

void InOrderTraverse(BiTree T) {
    // 若二叉树非空
    if (T) {

        // 中序遍历左子树
        InOrderTraverse(T->lchild);

        // 访问根节点
        // 注: 教材中是直接打印输出结点值, 这里封装成Visit函数, 更具"普遍意义"
        Visit(T);

        // 中序遍历右子树
        InOrderTraverse(T->rchild);
    }
}

// 先序遍历
void PreOrderTraverse(BiTree T) {
    // 若二叉树非空
    if (T) {

        // 访问根节点
        // 注: 教材中是直接打印输出结点值, 这里封装成Visit函数, 更具"普遍意义"
        Visit(T);

        // 先序遍历左子树
        InOrderTraverse(T->lchild);

        // 先序遍历右子树
        InOrderTraverse(T->rchild);
    }
}

// 后序遍历
void PostOrderTraverse(BiTree T) {
    // 若二叉树非空
    if (T) {

        // 后序遍历左子树
        InOrderTraverse(T->lchild);

        // 后序遍历右子树
        InOrderTraverse(T->rchild);

        // 访问根节点
        // 注: 教材中是直接打印输出结点值, 这里封装成Visit函数, 更具"普遍意义"
        Visit(T);
    }
}