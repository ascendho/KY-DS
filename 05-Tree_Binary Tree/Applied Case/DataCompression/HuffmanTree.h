#ifndef TEXTBOOK_HUFFMANTREE_H
#define TEXTBOOK_HUFFMANTREE_H

typedef struct {
    int weight;                  // 节点的权值
    int parent, lchild, rchild;  // 节点的双亲、左孩子、右孩子的下标
} HTNode, *HuffmanTree;          // 动态分配数组存储哈夫曼树

typedef char **HuffmanCode;      // 动态分配数组存储哈夫曼编码表

void Select(HuffmanTree HT, int len, int &s1, int &s2);

void CreatHuffmanTree(HuffmanTree &HT, int n);

void CreatHuffmanCode(HuffmanTree HT, HuffmanCode &HC, int n);

#endif //TEXTBOOK_HUFFMANTREE_H