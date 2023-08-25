#include "CharacterFrequencyStatistics.h"
#include<iostream>

using namespace std;

// 统计输入字符串中数字字符和字母字符的个数
void Count() {
    int num[36];
    char ch;
    int i;

    // 初始化
    for (i = 0; i < 36; i++) {
        num[i] = 0;
    }

    // 依次读入字符进行判断
    while ((ch = getchar()) != '\n') {
        // 数字字符
        if ('0' <= ch <= '9') {
            i = ch - 48;
            num[i]++;
        } else if ('A' <= ch <= 'Z')    // 字母字符
        {
            i = ch - 65 + 10;
            num[i]++;
        }
    }

    system("chcp 65001");

    for (i = 0; i < 10; i++)    // 输出数字字符的个数
    {
        cout << "数字" << i << "的个数=" << num[i] << endl;
    }
    for (i = 10; i < 36; i++)    // 输出字母字符的个数
    {
        cout << "字母字符" << char(i + 55) << "的个数=" << num[i] << endl;
    }
}