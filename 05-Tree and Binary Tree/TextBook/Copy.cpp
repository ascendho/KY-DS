#include "BiNode.h"
#include <iostream>

// 算法5.4
// 复制一棵和T完全相同的二叉树

void Copy(BiTree T, BiTree &NewT) {
    // 如果是空树，递归结束
    if (T == nullptr) {
        NewT = nullptr;
        return;
    } else {
        // 复制根结点
        NewT = new BiTNode;
        NewT->data = T->data;

        // 递归复制左子树
        Copy(T->lchild, NewT->lchild);

        // 递归复制右子树
        Copy(T->rchild, NewT->rchild);
    }
}