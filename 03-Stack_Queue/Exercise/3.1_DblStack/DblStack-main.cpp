#include "DblStack.h"
#include <iostream>

using namespace std;

int main() {
    system("chcp 65001");

    // e0和e1分别代表压入0号栈和1号栈的序列的长度（依次连续入栈，中间不出栈），d0和d1分别代表从0号栈和1号栈弹出的序列的长度（依次连续出栈，中间不入栈）
    int e0 = 3, e1 = 4, d0 = 2, d1 = 2;

    char laData[] = {'1', '2', '3'};
    char lbData[] = {'2', '3', '4', '5'};

    DblStack s;
    s.max = 7;
    InitDblStack(s, s.max);

    for (int i = 0; i < e0; i++)
        DblPush(s, 0, laData[i]);

    for (int i = 0; i < e1; i++)
        DblPush(s, 1, lbData[i]);

    if (IsFull(s))
        cout << "栈满" << endl;


    while (d0--) {
        char a;
        DblPop(s, 0, a);
        cout << a << " ";
    }
    cout << endl;

    while (d1--) {
        char b;
        DblPop(s, 1, b);
        cout << b << " ";
    }
    cout << endl;

    if (IsEmpty(s, 0))
        cout << "0号栈空" << endl;
    if (IsEmpty(s, 1))
        cout << "1号栈空" << endl;

}