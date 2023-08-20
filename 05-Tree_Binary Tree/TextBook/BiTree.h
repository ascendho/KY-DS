#ifndef TEXTBOOK_BITREE_H
#define TEXTBOOK_BITREE_H

// 二叉链表定义
typedef struct BiTNode {
    char data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

void InOrderTraverse(BiTree T);

void PreOrderTraverse(BiTree T);

void PostOrderTraverse(BiTree T);

void InOrderTraverseUsingStack(BiTree T);

void CreateBiTree(BiTree &T);

void Copy(BiTree T, BiTree &NewT);

int Depth(BiTree T);

int NodeCount(BiTree T);

// 只给出声明, 不给出具体定义
void Visit(BiTree T);

#endif //TEXTBOOK_BITREE_H