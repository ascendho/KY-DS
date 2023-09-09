#include "Ack.h"

// Ack(m,n)的递归算法
int Ack(int m, int n) {
    if (m == 0)
        return (n + 1);                                 // 递归结束
    else if (n == 0)
        return (Ack(m - 1, 1));                  // 调用递归函数Ack(m-1,1)
    else
        return (Ack(m - 1, Ack(m, n - 1)));   // 调用递归函数Ack(m-1, Ack(m,n-1))
}


// Ack(m,n)的非递归算法
int Ackerman(int m, int n) {
    for (int i = 0; i < MAXSIZE; i++)
        akm[0][i] = i + 1;

    for (int i = 1; i <= m; i++) {
        akm[i][0] = akm[i - 1][1];
        for (int j = 1; j < MAXSIZE; j++)
            akm[i][j] = akm[i - 1][akm[i][j - 1]];
    }

    return akm[m][n];
}