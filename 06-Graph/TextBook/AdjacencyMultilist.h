#ifndef TEXTBOOK_ADJACENCYMULTILIST_H
#define TEXTBOOK_ADJACENCYMULTILIST_H

#include "../../Status/Status.h"

// 无向图的邻接多重表存储表示
typedef enum {
    unvisited, visited
} VisitIf;

typedef struct EBox {
    VisitIf mark;                 // 访问标记
    int ivex, jvex;               // 该边依附的两个顶点的位置
    struct EBox *ilink, *jlink;   // 分别指向依附这两个顶点的下一条边
    InfoType *info;               // 该边信息指针
} Ebox;

typedef struct VexBox {
    VertexType data;
    EBox *firstedge;              // 指向第一条依附该顶点的边
} VexBox;

typedef struct {
    VexBox adjmulist[MAX_VERTEX_NUM];
    int vexnum, edgenum;　　       // 无向图的当前顶点数和边数
} AMLGraph;

#endif //TEXTBOOK_ADJACENCYMULTILIST_H