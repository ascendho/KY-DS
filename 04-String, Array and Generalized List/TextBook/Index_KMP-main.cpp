#include<iostream>
#include "Index_KMP.h"

using namespace std;

int main() {
    system("chcp 65001");

    SString S;
    StrAssign(S, "aaabbaba");
    SString T;
    StrAssign(T, "abb");
    int *p = new int[T.length + 1]; // 生成T的next数组
    next(T, p);
    cout << "主串和子串在第" << Index_KMP(S, T, 1, p) << "个字符处首次匹配\n";

    return 0;
}