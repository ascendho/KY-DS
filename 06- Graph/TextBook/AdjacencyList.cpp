#include "AdjacencyList.h"
#include <iostream>

// 算法6.2　采用邻接表表示法创建无向图
// 采用邻接表表示法，创建无向图G

// 时间复杂度: O(n+e)
// 空间复杂度: O(n+e)

int CreateUDG(ALGraph &G) {

    // 输入总顶点数，总边数
    std::cout << "请输入总顶点数, 总边数中间以空格隔开:";
    std::cin >> G.vexnum >> G.arcnum;
    std::cout << std::endl;

    // 输入各点，构造表头结点表
    std::cout << "输入点的名称, 如 a " << std::endl;
    for (int i = 0; i < G.vexnum; ++i) {
        std::cout << "请输入第" << (i + 1) << "个点的名称:";
        std::cin >> G.vertices[i].data;               // 输入顶点值
        G.vertices[i].firstarc = nullptr;             // 初始化表头结点的指针域为NULL
    }
    std::cout << std::endl;

    // 输入各边，构造邻接表
    std::cout << "请输入一条边依附的顶点,如 a b" << std::endl;
    for (int k = 0; k < G.arcnum; ++k) {
        VerTexType v1, v2;
        std::cout << "请输入第" << (k + 1) << "条边依附的顶点:";

        // 输入一条边依附的两个顶点
        std::cin >> v1 >> v2;

        // 确定v1和v2在G中位置，即顶点在G.vertices中的序号
        int i = LocateVex(G, v1);
        int j = LocateVex(G, v2);


        ArcNode *p1 = new ArcNode;                   // 生成一个新的边结点*p1
        p1->adjvex = j;                              // 邻接点序号为j

        // 将新结点*p1插入顶点vi的边表头部
        p1->nextarc = G.vertices[i].firstarc;
        G.vertices[i].firstarc = p1;

        // 生成另一个对称的新的边结点*p2
        // 邻接点序号为i
        ArcNode *p2 = new ArcNode;
        p2->adjvex = i;

        // 将新结点*p2插入顶点vj的边表头部
        p2->nextarc = G.vertices[j].firstarc;
        G.vertices[j].firstarc = p2;
    }
    return OK;
}

// 确定点v在G中的位置
int LocateVex(ALGraph G, VerTexType v) {
    for (int i = 0; i < G.vexnum; ++i)
        if (G.vertices[i].data == v)
            return i;
    return -1;
}