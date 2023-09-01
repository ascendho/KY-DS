#ifndef TEXTBOOK_MINIMUMCOSTSPANNINGTREE_H
#define TEXTBOOK_MINIMUMCOSTSPANNINGTREE_H

#include "../../../Status/Status.h"
#include "../01_AdjacencyMatrix/AdjacencyMatrix.h"

/* Prim算法 */

// 辅助数组的定义，用来记录从顶点集U到V-U的权值最小的边
struct {
    VerTexType adjvex;                        // 最小边在U中的那个顶点
    ArcType lowcost;                          // 最小边上的权值
} closedge[MVNum];

void MiniSpanTree_Prim(AMGraph G, VerTexType u);

int Min(AMGraph G);

/* -------------------------- */

/* Kruskal算法 */

// 辅助数组Edges的定义
// 存储边的信息，包括边的两个顶点信息和权值
struct {
    VerTexType Head;                        // 边的始点
    VerTexType Tail;                        // 边的终点
    ArcType lowcost;                        // 边上的权值
} Edge[(MVNum * (MVNum - 1)) / 2];

// 辅助数组Vexset的定义
// 标识各个顶点所属的连通分量
int Vexset[MVNum];

void MiniSpanTree_Kruskal(AMGraph G);

void Sort(AMGraph G);

#endif //TEXTBOOK_MINIMUMCOSTSPANNINGTREE_H