#ifndef TEXTBOOK_DFS_H
#define TEXTBOOK_DFS_H

#include "../Graph/Graph.h"
#include "../01_AdjacencyMatrix/AdjacencyMatrix.h"
#include "../02_AdjacencyList/AdjacencyList.h"

void DFS(Graph G, int v);

void DFSTraverse(Graph G);

void DFS_AM(AMGraph G, int v);

void DFS_AL(ALGraph G, int v);

#endif //TEXTBOOK_DFS_H