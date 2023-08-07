#include "ShortestPath.h"
#include "BFS.h"

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