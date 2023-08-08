#include "ShortestPath.h"
#include "BFS.h"
#include <iostream>

// 王道补充算法BFS
// BFS算法求解无权图的单源最短路径
void BFS_MIN_Distance(Graph G, int u) {
    int d[G.vexnum], path[G.vexnum];
    sqQueue Q;

    for (int i = 0; i < G.vexnum; i++) {
        // d[i]表示从u到i结点的最短路径
        d[i] = MaxInt;

        // 最短路径从哪个顶点过来
        path[i] = -1;
    }

    d[u] = 0;
    visited[u] = true;

    // 辅助队列Q初始化, 置空
    InitQueue(Q);
    EnQueue(Q, u);

    while (!QueueEmpty(Q)) {
        DeQueue(Q, u);

        for (ArcType w = FirstAdjVex(G, u); w >= 0; w = NextAdjVex(G, u, w)) {
            if (!visited[w]) {
                d[w] = d[u] + 1;                     // 路径长度加1
                path[w] = u;                         // 最短路径应从u到w
                visited[w] = true;                   // 置访问标志数组相应分量值为true
                EnQueue(Q, w);                 // 顶点w进队
            }
        }
    }
}

// 算法6.10　迪杰斯特拉算法
// 用Dijkstra算法求有向网G的v0顶点到其余顶点的最短路径

// 时间复杂度: O(n^2)

void ShortestPath_DIJ(AMGraph G, int v0) {
    int v;
    int n = G.vexnum;                                        // n为G中顶点的个数

    // n个顶点依次初始化
    for (int i = 0; i < n; ++i) {
        S[i] = false;                                        // S初始为空集
        D[i] = G.arcs[v0][i];                                // 将v0到各个终点的最短路径长度初始化为弧上的权值
        if (D[i] < MaxInt) Path[i] = v0;                     // 如果v0和v之间有弧，则将v的前驱置为v0
        else Path[i] = -1;                                   // 如果v0和v之间无弧，则将v的前驱置为-1
    }

    S[v0] = true;                                             // 将v0加入S
    D[v0] = 0;                                                // 源点到源点的距离为0

    /* ―初始化结束，开始主循环，每次求得v0到某个顶点v的最短路径，将v加到S集― */

    // 对其余n-1个顶点，依次进行计算
    for (int i = 1; i < n; ++i) {
        int min = MaxInt;
        for (int w = 0; w < n; ++w)
            if (!S[w] && D[w] < min) {                        // 选择一条当前的最短路径，终点为v
                v = w;
                min = D[w];
            }
        S[v] = true;                                          // 将v加入S
        for (int w = 0; w < n; ++w)                           // 更新从v0出发到集合V?S上所有顶点的最短路径长度
            if (!S[w] && (D[v] + G.arcs[v][w] < D[w])) {
                D[w] = D[v] + G.arcs[v][w];                   // 更新D[w]
                Path[w] = v;                                  // 更改w的前驱为v
            }
    }
}

// 显示最短路径
void DisplayPath(AMGraph G, int begin, int temp) {
    if (Path[temp] != -1) {
        DisplayPath(G, begin, Path[temp]);
        std::cout << G.vexs[Path[temp]] << "-->";
    }
}


// 算法6.11　弗洛伊德算法
// 用Floyd算法求有向网G中各对顶点i和j之间的最短路径

// 时间复杂度: O(n^3)

void ShortestPath_Floyd(AMGraph G) {
    for (int i = 0; i < G.vexnum; ++i)
        for (int j = 0; j < G.vexnum; ++j) {
            D_[i][j] = G.arcs[i][j];                 // 各对结点之间初始已知路径及距离

            if (D_[i][j] < MaxInt && i != j)
                Path_[i][j] = i;                     // 如果i和j之间有弧，则将j的前驱置为i
            else
                Path_[i][j] = -1;                    // 如果i和j之间无弧，则将j的前驱置为-1
        }

    for (int k = 0; k < G.vexnum; ++k)
        for (int i = 0; i < G.vexnum; ++i)
            for (int j = 0; j < G.vexnum; ++j)
                if (D_[i][k] + D_[k][j] < D_[i][j]) {          // 从i经k到j的一条路径更短
                    D_[i][j] = D_[i][k] + D_[k][j];            // 更新D[i][j]
                    Path_[i][j] = Path_[k][j];                 // 更改j的前驱为k
                }
}

// 显示最短路径
void DisplayPath_(AMGraph G, int begin, int temp) {
    if (Path_[begin][temp] != -1) {
        DisplayPath(G, begin, Path_[begin][temp]);
        std::cout << G.vexs[Path_[begin][temp]] << "-->";
    }
}