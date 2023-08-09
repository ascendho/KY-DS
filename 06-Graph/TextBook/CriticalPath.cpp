#include "CriticalPath.h"
#include <iostream>

// 算法6.13　关键路径算法
// 注: CreateUDG可能需要做一些修改, 创建逆邻接表

// 时间复杂度: O(n+e)

// G为邻接表存储的有向网，输出G的各项关键活动

Status CriticalPath(ALGraph G) {
    // 调用拓扑排序算法，使拓扑序列保存在topo中，若调用失败，则存在有向环，返回ERROR
    if (!TopologicalSort(G, topo))
        return ERROR;

    int n = G.vexnum;                                // n为顶点个数
    for (int i = 0; i < n; i++)                      // 给每个事件的最早发生时间置初值0
        ve[i] = 0;

    /* 按拓扑次序求每个事件的最早发生时间 */

    for (int i = 0; i < n; i++) {
        int k = topo[i];                            // 取得拓扑序列中的顶点序号k
        ArcNode *p = G.vertices[k].firstarc;        // p指向k的第一个邻接顶点
        while (p != nullptr) {                      // 依次更新k的所有邻接顶点的最早发生时间
            int j = p->adjvex;                      // j为邻接顶点的序号
            if (ve[j] < ve[k] + p->info)            // 更新顶点j的最早发生时间ve[j]
                ve[j] = ve[k] + p->info;
            p = p->nextarc;                         // p指向k的下一个邻接顶点
        }
    }

    for (int i = 0; i < n; i++)                     // 给每个事件的最迟发生时间置初值ve[n-1]
        vl[i] = ve[n - 1];

    /* 按逆拓扑次序求每个事件的最迟发生时间 */
    for (int i = n - 1; i >= 0; i--) {
        int k = topo[i];                            // 取得拓扑序列中的顶点序号k
        ArcNode *p = G.vertices[k].firstarc;        // p指向k的第一个邻接顶点
        while (p != nullptr) {                      // 根据k的邻接点，更新k的最迟发生时间
            int j = p->adjvex;                      // j为邻接顶点的序号
            if (vl[k] > vl[j] - p->info)            // 更新顶点k的最迟发生时间vl[k]
                vl[k] = vl[j] - p->info;
            p = p->nextarc;                         // p指向k的下一个邻接顶点
        }
    }

    /* 判断每一活动是否为关键活动 */
    std::cout << std::endl;
    std::cout << "关键活动路径为:";

    // 每次循环针对vi为活动开始点的所有活动
    for (int i = 0; i < n; i++) {
        ArcNode *p = G.vertices[i].firstarc;        // p指向i的第一个邻接顶点
        while (p != nullptr) {
            int j = p->adjvex;                      // j为i的邻接顶点的序号
            int e = ve[i];                          // 计算活动<vi, vj>的最早开始时间
            int l = vl[j] - p->info;                // 计算活动<vi, vj>的最迟开始时间
            if (e == l)                             // 若为关键活动，则输出<vi, vj>
                std::cout << G.vertices[i].data << "-->" << G.vertices[j].data << " ";
            p = p->nextarc;                         // p指向i的下一个邻接顶点
        }
    }

    return OK;
}