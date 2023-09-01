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

// 算法6.9　克鲁斯卡尔算法
// 无向网G以邻接矩阵形式存储，构造G的最小生成树T，输出T的各条边

// 时间复杂度: O(eloge), 与网中的边数有关
// 适合于求稀疏网的最小生成树

void MiniSpanTree_Kruskal(AMGraph G) {
    int v1, v2, vs1, vs2;

    Sort(G);                                                  // 将数组Edge中的元素按权值从小到大排序
    for (int i = 0; i < G.vexnum; ++i)                        // 辅助数组，表示各顶点自成一个连通分量
        Vexset[i] = i;

    // 依次查看排好序的数组Edge中的边是否在同一连通分量上
    for (int i = 0; i < G.arcnum; ++i) {

        v1 = LocateVex(G, Edge[i].Head);                // v1为边的始点Head的下标
        v2 = LocateVex(G, Edge[i].Tail);                // v2为边的终点Tail的下标
        vs1 = Vexset[v1];                                  // 获取边Edge[i]的始点所在的连通分量vs1
        vs2 = Vexset[v2];                                  // 获取边Edge[i]的终点所在的连通分量vs2

        // 边的两个顶点分属不同的连通分量
        if (vs1 != vs2) {
            std::cout << Edge[i].Head << "-->" << Edge[i].Tail << std::endl;        // 输出此边
            for (int j = 0; j < G.vexnum; ++j)                                      // 合并vs1和vs2两个分量，即两个集合统一编号
                if (Vexset[j] == vs2) Vexset[j] = vs1;                              // 集合编号为vs2的都改为vs1
        }
    }
}

// 冒泡排序
void Sort(AMGraph G) {
    int m = G.arcnum - 2;
    int flag = 1;

    while ((m > 0) && flag == 1) {
        flag = 0;
        for (int j = 0; j <= m; j++) {
            if (Edge[j].lowcost > Edge[j + 1].lowcost) {
                flag = 1;

                VerTexType temp_Head = Edge[j].Head;
                Edge[j].Head = Edge[j + 1].Head;
                Edge[j + 1].Head = temp_Head;


                VerTexType temp_Tail = Edge[j].Tail;
                Edge[j].Tail = Edge[j + 1].Tail;
                Edge[j + 1].Tail = temp_Tail;

                ArcType temp_lowcost = Edge[j].lowcost;
                Edge[j].lowcost = Edge[j + 1].lowcost;
                Edge[j + 1].lowcost = temp_lowcost;
            }
        }
        --m;
    }
}