#include<iostream>
#include "Index_BF.h"

using namespace std;

int main() {
    system("chcp 65001");

    SString S;
    StrAssign(S, "bbaaabbaba");
    cout << S.ch[0] << endl;

    SString T;
    StrAssign(T, "abb");
    cout << T.ch[0] << endl;

    cout << "主串和子串在第" << Index_BF(S, T, 1) << "个字符处首次匹配\n";
    return 0;
}