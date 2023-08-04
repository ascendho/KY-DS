#include "AdjacencyMatrix.h"
#include <iostream>

// 算法6.1　采用邻接矩阵表示法创建无向网
// 采用邻接矩阵表示法，创建无向网G

// 时间复杂度: O(n^2)
// 空间复杂度: O(n^2)

int CreateUDN(AMGraph &G) {

    std::cout << "请输入总顶点数, 总边数, 以空格隔开: ";

    // 输入总顶点数，总边数
    std::cin >> G.vexnum >> G.arcnum;

    std::cout << std::endl;
    std::cout << "输入点的名称, 如a" << std::endl;

    // 依次输入点的信息
    for (int i = 0; i < G.vexnum; ++i) {
        std::cout << "请输入第" << (i + 1) << "个点的名称: ";
        std::cin >> G.vexs[i];
    }

    // 初始化邻接矩阵，边的权值均置为极大值MaxInt
    std::cout << std::endl;
    for (int i = 0; i < G.vexnum; ++i)
        for (int j = 0; j < G.vexnum; ++j)
            G.arcs[i][j] = MaxInt;

    std::cout << "输入边依附的顶点及权值, 如 a b 5" << std::endl;

    // 构造邻接矩阵
    for (int k = 0; k < G.arcnum; ++k) {
        VerTexType v1, v2;
        ArcType w;

        // 输入一条边依附的顶点及权值
        std::cout << "请输入第" << (k + 1) << "条边依附的顶点及权值: ";
        std::cin >> v1 >> v2 >> w;

        // 确定v1和v2在G中的位置，即顶点数组的下标
        int i = LocateVex(G, v1);
        int j = LocateVex(G, v2);

        // 边<v1, v2>的权值置为w
        // 置<v1, v2>的对称边<v2, v1>的权值为w

        G.arcs[i][j] = w;
        G.arcs[j][i] = G.arcs[i][j];
    }
    return OK;
}

// 确定点v在G中的位置
int LocateVex(AMGraph G, VerTexType v) {
    for (int i = 0; i < G.vexnum; ++i)
        if (G.vexs[i] == v)
            return i;
    return -1;
}