#include "BiThrNode.h"
#include <iostream>

// 算法5.9　
// 遍历中序线索二叉树

// 时间复杂度: O(n)
// 空间复杂度: O(1)

void InOrderTraverse_Thr(BiThrTree T) {
    // T指向头结点，头结点的左链lchild指向根结点，可参见线索化算法5.8。
    // 中序遍历二叉线索树T的非递归算法，对每个数据元素直接输出

    BiThrTree p;

    // p指向根结点
    p = T->lchild;

    // 空树或遍历结束时，p==T
    while (p != T) {
        // 沿左孩子向下
        // 访问其左子树为空的结点

        while (p->LTag == 0)
            p = p->lchild;
        Visit(p);

        while (p->RTag == 1 && p->rchild != T) {
            // 沿右线索访问后继结点
            p = p->rchild;
            Visit(p);
        }
        p = p->rchild;
    }
}