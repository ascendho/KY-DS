#include "EvaluateExpression.h"
#include <iostream>

using namespace std;

int menu();

int main() {
    // 解决中文乱码问题
    system("chcp 65001");

    while (1) {
        switch (menu()) {
            case 1: {
                cout << "请输入要计算的表达式（操作数和结果都在0-9的范围内，以#结束）: " << endl;

                // 注：跟书中所输入的前后共计两个#不同, 具体实现这里只需要在后面添加一个#
                // 例如：(3+2*(3-2))*3#

                char res = EvaluateExpression();
                cout << "计算结果为" << res - 48 << endl << endl;
            }
                break;
            case 0:
                cout << "退出成功\n" << endl;
                exit(0);
            default:
                break;
        }
    }

    return 0;
}

int menu() {
    cout << "0-9以内的多项式计算" << endl;
    cout << "1.计算" << endl;
    cout << "0.退出\n" << endl;
    cout << "选择：";

    int command;
    cin >> command;

    return command;
}