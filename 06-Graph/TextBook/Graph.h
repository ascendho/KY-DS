#ifndef TEXTBOOK_GRAPH_H
#define TEXTBOOK_GRAPH_H

#include "../../Status/Status.h"

bool visited[MVNum];                            // 访问标志数组，其初值为"false"

typedef struct {
    VerTexType vexs[MVNum];                     // 顶点表
    ArcType arcs[MVNum][MVNum];                 // 邻接矩阵
    int vexnum, arcnum;                         // 图的当前点数和边数
} Graph;

int FirstAdjVex(Graph G, int v);

int NextAdjVex(Graph G, int v, int w);

int LocateVex(Graph G, VerTexType v);

void CreateUDN(Graph &G);

// 只给出定义, 不给出具体含义
void Visit(VerTexType);

#endif //TEXTBOOK_GRAPH_H
