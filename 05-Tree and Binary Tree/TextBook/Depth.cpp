#include "BiNode.h"
#include <iostream>

// 算法5.5
// 计算二叉树T的深度

int Depth(BiTree T) {
    int m, n;

    // 如果是空树，深度为0，递归结束
    if (T == nullptr) return 0;
    else {
        // 递归计算左子树的深度记为m
        m = Depth(T->lchild);

        // 递归计算右子树的深度记为n
        n = Depth(T->rchild);

        // 二叉树的深度为m 与n的较大者加1
        if (m > n)
            return (m + 1);
        else
            return (n + 1);
    }
}