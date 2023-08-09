#include "TopologicalSort.h"

// 算法6.12　拓扑排序
// 求出各顶点的入度存入数组indegree中

// 时间复杂度: O(n+e)

// 注: CreateUDG可能需要做一些修改, 创建逆邻接表
// 待补充: 逆拓扑排序、DFS实现拓扑排序

int TopologicalSort(ALGraph G, int topo[]) {
    // 有向图G采用邻接表存储结构
    // 若G无回路，则生成G的一个拓扑序列topo[]并返回OK，否则ERROR

    FindInDegree(G);                                 // 求出各顶点的入度存入数组indegree中
    InitStack(S);                                 // 栈S初始化为空

    for (int i = 0; i < G.vexnum; ++i)
        if (!indegree[i]) Push(S, i);             // 入度为0者进栈
    int m = 0;                                       // 对输出顶点计数，初始为0

    // 栈S非空
    while (!StackEmpty(S)) {
        int i;
        Pop(S, i);                             // 将栈顶顶点vi出栈
        topo[m] = i;                                 // 将vi保存在拓扑序列数组topo中
        ++m;                                         // 对输出顶点计数
        ArcNode *p = G.vertices[i].firstarc;         // p指向vi的第一个邻接点
        while (p) {
            int k = p->adjvex;                       // vk为vi的邻接点
            --indegree[k];                           // vi的每个邻接点的入度减1
            if (indegree[k] == 0) Push(S, k);  // 若入度减为0，则入栈
            p = p->nextarc;                         // p指向顶点vi下一个邻接结点
        }
    }

    if (m < G.vexnum)
        return ERROR;                              // 该有向图有回路
    else
        return OK;
}

void FindInDegree(ALGraph G) {
    for (int i = 0; i < G.vexnum; i++) {
        int count = 0;
        ArcNode *p = G.converse_vertices[i].firstarc;
        if (p) {
            while (p) {
                p = p->nextarc;
                count++;
            }
        }
        indegree[i] = count;
    }
}