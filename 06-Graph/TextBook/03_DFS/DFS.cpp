#include "DFS.h"

// 算法6.3　深度优先搜索遍历连通图的递归算法
// 从第v个顶点出发递归地深度优先遍历图G

void DFS(Graph G, int v) {
    // 访问第v个顶点，并置访问标志数组相应分量值为true
    Visit(G.vexs[v]);
    visited[v] = true;

    // 依次检查v的所有邻接点w ，FirstAdjVex(G, v)表示v的第一个邻接点
    // NextAdjVex(G, v, w)表示v相对于w的下一个邻接点，w≥0表示存在邻接点

    for (int w = FirstAdjVex(G, v); w >= 0; w = NextAdjVex(G, v, w))
        if (!visited[w])
            DFS(G, w);                                         // 对v的尚未访问的邻接顶点w递归调用DFS
}

// 算法6.4　深度优先搜索遍历非连通图
// 对非连通图G做深度优先遍历

void DFSTraverse(Graph G) {
    for (int v = 0; v < G.vexnum; ++v)
        visited[v] = false;                                       // 访问标志数组初始化

    for (int v = 0; v < G.vexnum; ++v)                            // 循环调用算法6.3
        if (!visited[v])
            DFS(G, v);                                            // 对尚未访问的顶点调用DFS
}

// 算法6.5　采用邻接矩阵表示图的深度优先搜索遍历
// 图G为邻接矩阵类型

// 时间复杂度: O(n^2)

void DFS_AM(AMGraph G, int v) {
    // 访问第v个顶点，并置访问标志数组相应分量值为true
    Visit(G.vexs[v]);
    visited[v] = true;

    // 依次检查邻接矩阵v所在的行
    for (int w = 0; w < G.vexnum; w++)
        if ((G.arcs[v][w] != 0) && (!visited[w]))
            DFS_AM(G, w);                            // G.arcs[v][w]!=0表示w是v的邻接点，如果w未访问，则递归调用DFS_AM
}

// 算法6.6　采用邻接表表示图的深度优先搜索遍历
// 图G为邻接表类型

// 时间复杂度: O(n+e)

void DFS_AL(ALGraph G, int v) {
    // 访问第v个顶点，并置访问标志数组相应分量值为true
    Visit(G.vertices[v].data);
    visited[v] = true;

    // p指向v的边链表的第一个边结点
    ArcNode *p = G.vertices[v].firstarc;

    // 边结点非空
    while (p != nullptr) {
        int w = p->adjvex;                            // 表示w是v的邻接点
        if (!visited[w])
            DFS_AL(G, w);                          // 如果w未访问，则递归调用DFS_AL

        p = p->nextarc;                               // p指向下一个边结点
    }
}