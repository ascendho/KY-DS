#include "BiNode.h"
#include <iostream>
#include <stack>

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