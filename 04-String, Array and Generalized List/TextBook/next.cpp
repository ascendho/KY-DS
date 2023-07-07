#include "next.h"

// 算法4.3　计算next函数值
// 求模式串T的next函数值并存入数组next

void next(SString T, int next[]) {
    int i = 1, j = 0;
    next[1] = 0;

    while (i < T.length)
        if (j == 0 || T.ch[i] == T.ch[j]) {
            ++i;
            ++j;
            next[i] = j;
        } else
            j = next[j];
}