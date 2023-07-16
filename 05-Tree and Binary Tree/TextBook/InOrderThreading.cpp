#include "InThreading.cpp"

// 算法5.8　
// 带头节点的二叉树中序线索化

// 中序遍历二叉树T，并将其中序线索化，Thrt指向头结点

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