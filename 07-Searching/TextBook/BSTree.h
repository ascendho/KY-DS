#ifndef TEXTBOOK_BSTREE_H
#define TEXTBOOK_BSTREE_H

#include "../../Status/Status.h"

typedef struct Data {
    KeyType key;           // 关键字项
    InfoType otherinfo;    // 其他数据项
} Data;

typedef struct BSTNode {
    Data data;                   // 结点数据域
    BSTNode *lchild, *rchild;    // 左右孩子指针
} BSTNode, *BSTree;

BSTree SearchBST(BSTree T, char key);

void InsertBST(BSTree &T, Data e);

void CreateBST(BSTree &T);

void DeleteBST(BSTree &T, char key);

void InOrderTraverse(BSTree &T);

void Visit(BSTree T);

#endif //TEXTBOOK_BSTREE_H
