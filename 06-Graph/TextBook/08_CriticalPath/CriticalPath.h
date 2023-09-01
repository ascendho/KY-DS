#ifndef TEXTBOOK_CRITICALPATH_H
#define TEXTBOOK_CRITICALPATH_H

#include "../../../Status/Status.h"
#include "../02_AdjacencyList/AdjacencyList.h"
#include "../07_TopologicalSort/TopologicalSort.h"
#include <iostream>

// 考虑把公共变量如S、topo、indegree存储在公共头文件
// extern关键字: 

int indegree_[MVNum];                       // 数组indegree存放个顶点的入度
int ve[BDNum];                              // 事件vi的最早发生时间
int vl[BDNum];                              // 事件vi的最迟发生时间
int topo[MVNum];                            // 记录拓扑序列的顶点序号
spStack S_;

Status CriticalPath(ALGraph G);

#endif //TEXTBOOK_CRITICALPATH_H