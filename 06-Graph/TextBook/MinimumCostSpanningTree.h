#ifndef TEXTBOOK_MINIMUMCOSTSPANNINGTREE_H
#define TEXTBOOK_MINIMUMCOSTSPANNINGTREE_H

#include "../../Status/Status.h"
#include "AdjacencyMatrix.h"

// 辅助数组的定义，用来记录从顶点集U到V-U的权值最小的边
struct {
    VerTexType adjvex;                        // 最小边在U中的那个顶点
    ArcType lowcost;                          // 最小边上的权值
} closedge[MVNum];


void MiniSpanTree_Prim(AMGraph G, VerTexType u);

int Min(AMGraph G);


#endif //TEXTBOOK_MINIMUMCOSTSPANNINGTREE_H