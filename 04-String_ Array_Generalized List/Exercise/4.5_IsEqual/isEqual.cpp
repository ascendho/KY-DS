#include "isEqual.h"
#include <iostream>

// 判断二维数组中a所有元素是否互不相同, 如是, 返回1；否则, 返回0
bool IsEqual(int a[ROW][COL], int m, int n) {
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n - 1; j++) {
            for (int p = j + 1; p < n; p++)        // 和同行其他元素比较
                if (a[i][j] == a[i][p])            // 只要有一个相同，则不是互不相同
                {
                    std::cout << "no";
                    return false;
                }

            // 和第i+1行及以后元素比较
            for (int k = i + 1; k < m; k++)
                for (int p = 0; p < n; p++)
                    if (a[i][j] == a[k][p]) {
                        std::cout << "no";
                        return 0;
                    }
        }

    std::cout << "yes";
    return true;                 // 元素互不相同
}