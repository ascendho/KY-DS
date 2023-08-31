#include "BiThrTree.h"

// 算法5.7
// 以节点p为根的子树中序线索化

// 全局变量pre
// pre是全局变量，初始化时其右孩子指针为空，便于在树的最左点开始建线索

BiThrNode *pre = new BiThrNode;

void InThreading(BiThrTree p) {
    if (p) {
        InThreading(p->lchild);                        // 左子树递归线索化
        if (!p->lchild) {                                 // p的左孩子为空
            p->LTag = 1;                                  // 给p加上左线索
            p->lchild = pre;                              // p的左孩子指针指向pre（前驱）
        } else
            p->LTag = 0;
        if (!pre->rchild) {                               // pre的右孩子为空
            pre->RTag = 1;                                // 给pre加上右线索
            pre->rchild = p;                              // pre的右孩子指针指向p（后继）
        } else
            pre->RTag = 0;
        pre = p;                                          // 保持pre指向p的前驱
        InThreading(p->rchild);                        // 右子树递归线索化
    }
}

// 算法5.8　
// 带头节点的二叉树中序线索化, 中序遍历二叉树T，并将其中序线索化，Thrt指向头结点

void InOrderThreading(BiThrTree &Thrt, BiThrTree T) {
    // 建头结点
    Thrt = new BiThrNode;

    // 头结点有左孩子，若树非空，则其左孩子为树根
    Thrt->LTag = 0;

    // 头结点的右孩子指针为右线索
    Thrt->RTag = 1;

    // 初始化时右指针指向自己
    Thrt->rchild = Thrt;

    // 若树为空，则左指针也指向自己
    if (!T) Thrt->lchild = Thrt;
    else {
        // 头结点的左孩子指向根，pre初值指向头结点
        Thrt->lchild = T;
        pre = Thrt;

        // 调用算法5.7，对以T为根的二叉树进行中序线索化
        InThreading(T);

        // 算法5.7结束后，pre为最右结点，pre的右线索指向头结点
        pre->rchild = Thrt;
        pre->RTag = 1;

        // 头结点的右线索指向pre
        Thrt->rchild = pre;
    }
}

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