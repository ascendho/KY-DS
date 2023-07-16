#ifndef TEXTBOOK_BINODE_H
#define TEXTBOOK_BINODE_H

// 二叉链表定义
typedef struct InOrderTraverse {
    char data;
    struct InOrderTraverse *lchild, *rchild;
} BiTNode, *BiTree;

void InOrderTraverse(BiTree T);

void PreOrderTraverse(BiTree T);

void PostOrderTraverse(BiTree T);

void InOrderTraverseUsingStack(BiTree T);

// 只给出声明, 不给出具体定义
void Visit(BiTree T);

#endif //TEXTBOOK_BINODE_H