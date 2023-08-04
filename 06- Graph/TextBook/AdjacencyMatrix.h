#ifndef TEXTBOOK_ADJACENCYMATRIX_H
#define TEXTBOOK_ADJACENCYMATRIX_H

#include "../../Status/Status.h"

typedef char VerTexType;                    // 假设顶点的数据类型为字符型
typedef int ArcType;                        // 假设边的权值类型为整型

// 图的邻接矩阵存储表示
typedef struct {
    VerTexType vexs[MVNum];                    // 顶点表
    ArcType arcs[MVNum][MVNum];                // 邻接矩阵
    int vexnum, arcnum;                        // 图的当前点数和边数
} AMGraph;

int CreateUDN(AMGraph &G);

int LocateVex(AMGraph G, VerTexType v);

#endif //TEXTBOOK_ADJACENCYMATRIX_H