#include "SixDegree_BFS.h"
#include <iostream>

// 通过广度优先搜索方法遍历G来验证六度空间理论，Start为指定的始点
// 待完善...

/*
void SixDegree_BFS(Graph G, int Start) {
    int Visit_Num = 0;                             // 记录路径长度不超过7的顶点个数
    visited[Start] = true;                         // 置顶点Start访问标志数组相应分量值为true
    InitQueue(Q);
    EnQueue(Q, Start);                             // 辅助队列Q初始化，置空，Start进队　　　　
    level[0] = 1;                                  // 第一层入队的顶点个数初始化为1


    // 统计路径长度不超过7的顶点个数
    for (int len = 1; len <= 6 && !QueueEmpty(Q); len++) {
        for (int i = 0; i < level[len - 1]; i++) {
            DeQueue(Q, u); //队头顶点u出队
            for (int w = FirstAdjVex(G, u); w >= 0; w = NextAdjVex(G, u, w))
                // 依次检查u的所有邻接点w，FirstAdjVex(G,u)表示u的第一个邻接点
                // NextAdjVex(G,u,w)表示u相对于w的下一个邻接点，w≥0表示存在邻接点
                if (!visited[w]) //w为u的尚未访问的邻接顶点
                {
                    visited[w] = true; //将w标记为六度顶点
                    Visit_Num++;
                    level[len]++; //路径长度不超过7的顶点个数加1，该层次的顶点个数加1
                    EnQueue(Q, w); //w入队
                }
        }
    }

    // 输出从顶点Start出发，到其他顶点长度不超过7的路径的百分比
    std::cout << 100 * Visit_Num / G.vexnum;
}
 */