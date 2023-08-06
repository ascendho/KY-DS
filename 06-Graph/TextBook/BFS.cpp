#include "BFS.h"

// 算法6.7　广度优先搜索遍历连通图
// 按广度优先非递归遍历连通图G

void BFS(Graph G, int v) {
    sqQueue Q;
    ArcType u;

    // 访问第v个顶点，并置访问标志数组相应分量值为true
    Visit(G.vexs[v]);
    visited[v] = true;

    // 辅助队列Q初始化，置空
    InitQueue(Q);
    EnQueue(Q, v);                                                        // v进队
    while (!QueueEmpty(Q)) {                                                    // 队列非空
        DeQueue(Q, u);                                                    // 队头元素出队并置为u

        // 依次检查u的所有邻接点w ，FirstAdjVex(G, u)表示u的第一个邻接点
        // NextAdjVex(G, u, w)表示u相对于w的下一个邻接点，w≥0表示存在邻接点
        for (ArcType w = FirstAdjVex(G, u); w >= 0; w = NextAdjVex(G, u, w)) {

            if (!visited[w]) {                                                  // w为u的尚未访问的邻接顶点
                Visit(G.vexs[v]);
                visited[w] = true;                                              // 访问w, 并置访问标志数组相应分量值为true
                EnQueue(Q, w);                                            // w进队
            }
        }
    }
}