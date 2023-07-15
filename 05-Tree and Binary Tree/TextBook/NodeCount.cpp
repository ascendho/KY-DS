#include "BiNode.h"

// 算法5.6
// 统计二叉树T中结点的个数

int NodeCount(BiTree T) {
    // 如果是空树，则结点个数为0，递归结束
    if (T == nullptr) return 0;
    else
        return NodeCount(T->lchild) + NodeCount(T->rchild) + 1;
    // 否则结点个数为左子树的结点个数+右子树的结点个数+1
}