#include "BiNode.h"
#include <iostream>

// 算法5.3
// 按先序次序输入二叉树中结点的值（一个字符），创建二叉链表表示的二叉树T

void CreateBiTree(BiTree &T) {
    char ch;
    std::cin >> ch;

    // 递归结束，建空树
    if (ch == '#') T = nullptr;
    else {
        T = new BiTNode;
        T->data = ch;                   // 生成根结点
        CreateBiTree(T->lchild);     // 递归创建左子树
        CreateBiTree(T->rchild);     // 递归创建右子树
    }
}




