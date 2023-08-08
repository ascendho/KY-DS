#ifndef TEXTBOOK_SHORTESTPATH_H
#define TEXTBOOK_SHORTESTPATH_H

#include "Graph.h"
#include "AdjacencyMatrix.h"
#include "../../Status/Status.h"

/* 王道补充算法BFS */
void BFS_MIN_Distance(Graph G, int u);

/* 迪杰斯特拉算法 */
int *D = new int[MVNum];                                   // 用于记录最短路的长度
bool *S = new bool[MVNum];                                 // 标记顶点是否进入S集合
int *Path = new int[MVNum];                                // 用于记录最短路顶点的前驱

void ShortestPath_DIJ(AMGraph G, int v0);

void DisplayPath(AMGraph G, int begin, int temp);



#endif //TEXTBOOK_SHORTESTPATH_H
