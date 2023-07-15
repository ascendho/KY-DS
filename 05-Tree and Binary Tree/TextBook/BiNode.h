#ifndef TEXTBOOK_BINODE_H
#define TEXTBOOK_BINODE_H

// 二叉链表定义
typedef struct InOrderTraverse {
    char data;
    struct InOrderTraverse *lchild, *rchild;
} BiTNode, *BiTree;

void InOrderTraverse(BiTree T);

void InOrderTraverseUsingStack(BiTree T);

void Visit(BiTree T);

#endif //TEXTBOOK_BINODE_H