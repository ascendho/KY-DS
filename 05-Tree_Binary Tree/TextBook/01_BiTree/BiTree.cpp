#include "BiTree.h"
#include <iostream>
#include <stack>

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

// 算法5.2
// 中序遍历二叉树T的非递归算法

// 时间复杂度: O(n)

// 所需辅助空间为遍历过程中栈的最大容量，即树的深度，最坏情况下为n
// 空间复杂度: O(n)

void InOrderTraverseUsingStack(BiTree T) {
    std::stack<BiTree> S;
    BiTree p = T;
    BiTree q = new BiTNode;

    while (p || !S.empty()) {
        if (p) {
            // p非空根指针进栈，遍历左子树

            S.push(p);
            p = p->lchild;
        } else {
            // p为空根指针退栈，访问根结点，遍历右子树
            // 注: c++中stl中栈的pop函数不会返回栈顶元素，因此需要事先取出

            q = S.top();
            S.pop();

            // 访问根节点
            // 注: 教材中是直接打印输出结点值, 这里封装成Visit函数, 更具"普遍意义"
            Visit(q);

            // 遍历右子树
            p = q->rchild;
        }
    }
}

// 算法5.3
// 按先序次序输入二叉树中结点的值（单字符）, 创建二叉链表表示的二叉树T

void CreateBiTree(BiTree &T) {
    char ch;
    std::cin >> ch;

    // 递归结束，建空树
    if (ch == '#') T = nullptr;
    else {
        // 生成根结点
        T = new BiTNode;
        T->data = ch;

        // 递归创建左子树
        CreateBiTree(T->lchild);

        // 递归创建右子树
        CreateBiTree(T->rchild);
    }
}

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

// 算法5.6
// 统计二叉树T中结点的个数

int NodeCount(BiTree T) {
    // 如果是空树，则结点个数为0，递归结束
    if (T == nullptr) return 0;
    else
        return NodeCount(T->lchild) + NodeCount(T->rchild) + 1;
    // 否则结点个数为左子树的结点个数+右子树的结点个数+1
}