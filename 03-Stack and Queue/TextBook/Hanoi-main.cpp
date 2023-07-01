/* Hanoi塔问题 */
#include <iostream>
#include"Hanoi.h"

using namespace std;

int main() {
    // 解决中文乱码问题
    system("chcp 65001");

    char a, b, c;
    a = '1';
    b = '2';
    c = '3';

    int n;
    cout << "请输入初始第一个柱子上的圆盘个数：" << endl;
    cin >> n;

    cout << "将第一个柱子上的圆盘全部移动到第三个柱子上的过程为：" << endl;
    Hanoi(n, a, b, c);

    return 0;
}