#ifndef TEXTBOOK_ADJACENCYMATRIX_H
#define TEXTBOOK_ADJACENCYMATRIX_H

#include "../../Status/Status.h"

// 图的邻接矩阵存储表示
typedef struct {
    VerTexType vexs[MVNum];                    // 顶点表
    ArcType arcs[MVNum][MVNum];                // 邻接矩阵
    int vexnum, arcnum;                        // 图的当前点数和边数
} AMGraph;

int LocateVex(AMGraph G, VerTexType v);

int CreateUDN(AMGraph &G);

#endif //TEXTBOOK_ADJACENCYMATRIX_H