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

/* 弗洛伊德算法 */
int Path_[MVNum][MVNum];                     // 最短路径上顶点vj的前一顶点的序号
int D_[MVNum][MVNum];                        // 记录顶点vi和vj之间的最短路径长度

void ShortestPath_Floyd(AMGraph G);

void DisplayPath_(AMGraph G, int begin, int temp);

#endif //TEXTBOOK_SHORTESTPATH_H
