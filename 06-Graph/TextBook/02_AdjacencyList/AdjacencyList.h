#ifndef TEXTBOOK_ADJACENCYLIST_H
#define TEXTBOOK_ADJACENCYLIST_H

#include "../../../Status/Status.h"

// 图的邻接表存储表示
typedef struct ArcNode {                      // 边结点
    int adjvex;                               // 该边所指向的顶点的位置
    struct ArcNode *nextarc;                  // 指向下一条边的指针
    OtherInfo info;                           // 和边相关的信息
} ArcNode;

typedef struct VNode {
    VerTexType data;                           // 顶点信息
    ArcNode *firstarc;                         // 指向第一条依附该顶点的边的指针
} VNode, AdjList[MVNum];                       // AdjList表示邻接表类型

typedef struct {
    AdjList vertices;                          // 邻接表
    AdjList converse_vertices;				   // 逆邻接表
    int vexnum, arcnum;                        // 图的当前顶点数和边数
} ALGraph;

int LocateVex(ALGraph G, VerTexType v);

int CreateUDG(ALGraph &G);

#endif //TEXTBOOK_ADJACENCYLIST_H