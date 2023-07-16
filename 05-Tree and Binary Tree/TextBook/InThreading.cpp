#include "BiThrNode.h"

// 全局变量pre
// pre是全局变量，初始化时其右孩子指针为空，便于在树的最左点开始建线索

BiThrNode *pre = new BiThrNode;

// 算法5.7
// 以节点p为根的子树中序线索化

void InThreading(BiThrTree p) {
    if (p) {
        InThreading(p->lchild);                        // 左子树递归线索化
        if (!p->lchild) {                                 // p的左孩子为空
            p->LTag = 1;                                  // 给p加上左线索
            p->lchild = pre;                              // p的左孩子指针指向pre（前驱）
        } else
            p->LTag = 0;
        if (!pre->rchild) {                               // pre的右孩子为空
            pre->RTag = 1;                                // 给pre加上右线索
            pre->rchild = p;                              // pre的右孩子指针指向p（后继）
        } else
            pre->RTag = 0;
        pre = p;                                          // 保持pre指向p的前驱
        InThreading(p->rchild);                        // 右子树递归线索化
    }
}