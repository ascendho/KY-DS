#include "DisjointSet.h"
#include <iostream>

// 初始化并查集
void Initial(int S[]) {
    for (int i = 0; i < MAXSIZE; i++)
        S[i] = -1;
}

// "查"操作优化, 先找到根结点, 再进行"压缩路径"

int Find(int S[], int x) {
    int root = x;

    // 循环找到根
    while (S[root] >= 0)
        root = S[root];

    // 压缩路径
    while (x != root) {
        int t = S[x];      // t指向x的父结点
        S[x] = root;       // x直接挂到根结点下
        x = t;
    }

    // 返回根结点编号
    return root;
}

// "并"操作优化, 小树合并到大树

void Union(int S[], int Root1, int Root2) {
    if (Root1 == Root2)
        exit(OVERFLOW);

    if (S[Root2] > S[Root1]) {
        S[Root1] += S[Root2];    // 累加结点总数
        S[Root2] = Root1;        // 小树合并到大树
    } else {
        S[Root2] += S[Root1];    // 累加结点总数
        S[Root1] = Root2;        // 小树合并到大树
    }

}