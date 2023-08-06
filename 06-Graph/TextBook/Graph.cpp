#include "Graph.h"
#include <iostream>

// 返回v的第一个邻接点
int FirstAdjVex(Graph G, int v) {
    for (int i = 0; i < G.vexnum; ++i) {
        if (G.arcs[v][i] == 1 && !visited[i])
            return i;
    }
    return -1;
}

// 返回v相对于w的下一个邻接点
int NextAdjVex(Graph G, int v, int w) {
    for (int i = w; i < G.vexnum; ++i) {
        if (G.arcs[v][i] == 1 && !visited[i])
            return i;
    }
    return -1;
}

// 确定点v在G中的位置
int LocateVex(Graph G, VerTexType v) {
    for (int i = 0; i < G.vexnum; ++i)
        if (G.vexs[i] == v)
            return i;
    return -1;
}

// 采用邻接矩阵表示法，创建无向网G
void CreateUDN(Graph &G) {
    int i, j, k;

    std::cout << "请输入总顶点数，总边数 , 以空格隔开:";
    std::cin >> G.vexnum >> G.arcnum;                          // 输入总顶点数，总边数
    std::cout << std::endl;

    std::cout << "输入点的名称，如 a：" << std::endl;

    for (i = 0; i < G.vexnum; ++i) {
        std::cout << "请输入第" << (i + 1) << "个点的名称:";
        std::cin >> G.vexs[i];                                 // 依次输入点的信息
    }
    std::cout << std::endl;

    for (i = 0; i < G.vexnum; ++i)                             // 初始化邻接矩阵，边的权值均置为极大值MaxInt
        for (j = 0; j < G.vexnum; ++j)
            G.arcs[i][j] = 0;
    std::cout << "输入边依附的顶点，如：a b" << std::endl;

    // 构造邻接矩阵
    for (k = 0; k < G.arcnum; ++k) {
        VerTexType v1, v2;
        std::cout << "请输入第" << (k + 1) << "条边依附的顶点:";
        std::cin >> v1 >> v2;                                  // 输入一条边依附的顶点及权值
        i = LocateVex(G, v1);
        j = LocateVex(G, v2);                               // 确定v1和v2在G中的位置，即顶点数组的下标
        G.arcs[j][i] = G.arcs[i][j] = 1;                       // 置<v1, v2>的对称边<v2, v1>的权值为w
    }
}