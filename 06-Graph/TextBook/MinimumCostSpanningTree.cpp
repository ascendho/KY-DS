#include "MinimumCostSpanningTree.h"
#include <iostream>

// 算法6.8　普里姆算法
// 无向网G以邻接矩阵形式存储，从顶点u出发构造G的最小生成树T，输出T的各条边

// 时间复杂度: O(n^2), 与网中的边数无关
// 适用于求稠密网的最小生成树

void MiniSpanTree_Prim(AMGraph G, VerTexType u) {
    VerTexType u0, v0;
    int k = LocateVex(G, u);                                                 // k为顶点u的下标

    // 对V-U的每一个顶点vi，初始化closedge[i]
    for (int j = 0; j < G.vexnum; ++j) {
        if (j != k) {
            closedge[j].adjvex = u;
            closedge[j].lowcost = G.arcs[k][j];
        }
    }

    // 初始, U = {u}
    closedge[k].lowcost = 0;

    // 选择其余n-1个顶点, 生成n-1条边(n= G.vexnum)
    for (int i = 1; i < G.vexnum; ++i) {
        k = Min(G);

        // 求出T的下一个结点：第k个顶点，closedge[k]中存有当前最小边
        u0 = closedge[k].adjvex;                                             // u0为最小边的一个顶点，u0∈U
        v0 = G.vexs[k];                                                      // v0为最小边的另一个顶点，v0∈V-U

        // 输出当前的最小边(u0, v0)
        std::cout << "边  " << u0 << "--->" << v0 << std::endl;

        // 第k个顶点并入U集
        closedge[k].lowcost = 0;

        for (int j = 0; j < G.vexnum; ++j)
            // 新顶点并入U后重新选择最小边
            if (G.arcs[k][j] < closedge[j].lowcost) {
                closedge[j].adjvex = G.vexs[k];
                closedge[j].lowcost = G.arcs[k][j];
            }
    }
}

// 返回权值最小的点
int Min(AMGraph G) {
    int index = -1;
    int min = MaxInt;

    for (int i = 0; i < G.vexnum; ++i) {
        if (min > closedge[i].lowcost && closedge[i].lowcost != 0) {
            min = closedge[i].lowcost;
            index = i;
        }
    }

    return index;
}