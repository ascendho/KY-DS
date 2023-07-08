#ifndef TEXTBOOK_GLIST_H
#define TEXTBOOK_GLIST_H

#include "../../Status/Status.h"

// 广义表的头尾链表存储表示
typedef enum {
    ATOM, LIST
} ElemTag;                            //ATOM==0：原子 ；LIST==1：子表
typedef struct GLNode {
    ElemTag tag;                      // 公共部分，用于区分原子节点和表节点
    union                             // 原子节点和表节点的联合部分
    {
        AtomType atom;                // atom是原子节点的值域，AtomType由用户定义
        struct {
            struct GLNode *hp, *tp;
        } ptr;                        // ptr是表节点的指针域，ptr.hp 和ptr.tp分别指向表头和表尾

    };
} *GList;

// 扩展线性链表的存储结构
// 在这种结构中，无论是表节点还是原子节点均由3个域组成

#endif //TEXTBOOK_GLIST_H