#include <iostream>
#include "Conversion.h"

using namespace std;

int main() {
    // 解决中文乱码问题
    system("chcp 65001");

    int N, base;
    cout << "输入一个非负十进制数:" << endl;
    cin >> N;

    cout << "输入要转换的进制(2-16):" << endl;
    cin >> base;

    Conversion(N, base);
    cout << endl;
    Conversion_Recursive(N, base);

    return 0;
}