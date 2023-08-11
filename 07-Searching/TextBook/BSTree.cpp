#include "BSTree.h"
#include<iostream>

// 算法7.4　二叉排序树的递归查找
// 在根指针T所指二叉排序树中递归地查找某关键字等于key的数据元素, 若查找成功, 则返回指向该数据元素结点的指针, 否则返回空指针

// 时间复杂度: O(logn)

BSTree SearchBST(BSTree T, KeyType key) {
    if ((!T) || key == T->data.key)
        return T;                               // 查找结束
    else if (key < T->data.key)
        return SearchBST(T->lchild, key);    // 在左子树中继续查找
    else
        return SearchBST(T->rchild, key);    // 在右子树中继续查找
}


// 算法7.5　二叉排序树的插入
// 当二叉排序树T中不存在关键字等于e.key的数据元素时，则插入该元素

// 时间复杂度: O(logn)

void InsertBST(BSTree &T, Data e) {
    if (!T) {                                // 找到插入位置，递归结束
        BSTree S = new BSTNode;              // 生成新结点*S
        S->data = e;                         // 新结点*S的数据域置为e
        S->lchild = S->rchild = nullptr;     // 新结点*S作为叶子结点
        T = S;                               // 把新结点*S链接到已找到的插入位置
    } else if (e.key < T->data.key)
        InsertBST(T->lchild, e);          // 将*S插入左子树
    else if (e.key > T->data.key)
        InsertBST(T->rchild, e);          // 将*S插入右子树
}


// 算法7.6　二叉排序树的创建
// 依次读入一个关键字为key的结点，将此结点插入二叉排序树T中

// 时间复杂度: O(nlogn)

void CreateBST(BSTree &T) {
    T = nullptr;
    Data e;
    std::cin >> e.key;

    while (e.key != ENDFLAG) {    // ENDFLAG为自定义常量，作为输入结束标志
        InsertBST(T, e);       // 将此结点插入二叉排序树T中
        std::cin >> e.key;
    }
}

// 算法 7.7　二叉排序树的删除
// 从二叉排序树T中删除关键字等于key的结点

// 时间复杂度: O(logn)

void DeleteBST(BSTree &T, KeyType key) {
    // 初始化
    BSTree p = T;
    BSTree f = nullptr;
    BSTree q;
    BSTree s;

    /* 下面的while循环从根开始查找关键字等于key的结点*p */
    while (p) {
        if (p->data.key == key) break;            // 找到关键字等于key的结点*p，结束循环
        f = p;                                    // *f为*p的双亲结点
        if (p->data.key > key)
            p = p->lchild;                        // 在*p的左子树中继续查找
        else
            p = p->rchild;                        // 在*p的右子树中继续查找
    }
    if (!p)
        return;                                   // 找不到被删结点则返回

/* ―考虑三种情况实现p所指子树内部的处理：*p左右子树均不空、无右子树、无左子树― */
    if ((p->lchild) && (p->rchild)) {             // 被删结点*p左右子树均不空
        q = p;
        s = p->lchild;
        while (s->rchild)                         // 在*p的左子树中继续查找其前驱结点，即最右下结点
        {
            q = s;
            s = s->rchild;
        }                                         // 向右到尽头
        p->data = s->data;                        // s指向被删结点的“前驱”
        if (q != p) {
            q->rchild = s->lchild;                // 重接*q的右子树
        } else q->lchild = s->lchild;             // 重接*q的左子树
        delete s;
    } else {
        if (!p->rchild) {                         // 被删结点*p无右子树，只需重接其左子树
            q = p;
            p = p->lchild;
        } else if (!p->lchild) {                  // 被删结点*p无左子树，只需重接其右子树
            q = p;
            p = p->rchild;
        }

        /* 将p所指的子树挂接到其双亲结点*f相应的位置 */
        if (!f)
            T = p;                               // 被删结点为根结点

        else if (q == f->lchild)
            f->lchild = p;                       // 挂接到*f的左子树位置
        else
            f->rchild = p;                       // 挂接到*f的右子树位置
        delete q;
    }
}


// 中序遍历
void InOrderTraverse(BSTree &T) {
    if (T) {
        InOrderTraverse(T->lchild);
        Visit(T);
        InOrderTraverse(T->rchild);
    }
}