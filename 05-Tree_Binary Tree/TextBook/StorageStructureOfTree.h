#ifndef TEXTBOOK_STORAGESTRUCTUREOFTREE_H
#define TEXTBOOK_STORAGESTRUCTUREOFTREE_H

#include "../../Status/Status.h"

/* 双亲表示法 */

// 优点：找双亲（父节点）很方便
// 缺点：找孩子不方便，只能从头到尾遍历整个数组

// 适用于“找父亲” 多，“找孩子” 少 的应用场景。如：并查集

typedef struct {
    TElemType data;
    int parent;                 // 双亲位置域
} PTNode;

typedef struct {
    PTNode nodes[MAXTREESIZE];  // 双亲表示
    int n;                      // 结点数
} PTree;

/* 孩子表示法 */

// 优点：找孩子很方便
// 缺点：找双亲（父节点）不方便，只能遍历每个链表

// 适用于“找孩子” 多，“找父亲” 少 的应用场景。如：服务流程树

struct CTNode {
    int child;                 // 孩子结点在数组中的位置
    struct CTNode *next;       // 下一个孩子
};

typedef struct {
    TElemType data;
    struct CTNode *firstChild; // 第一个孩子
} CTBox;

typedef struct {
    CTBox nodes[MAXTREESIZE];
    int n, r;                 // 结点数目和根的位置
} CTree;

/* 孩子兄弟表示法 */

// 当使用“孩子兄弟表示法”存储树或森林时，从存储视角来看形态上与二叉树类似

typedef struct CSNode {
    TElemType data;
    struct CSNode *firstchild, *nextsibling; // 第一个孩子和右兄弟指针
} CSNode, *CSTree;

#endif //TEXTBOOK_STORAGESTRUCTUREOFTREE_H