#include "CharacterFrequencyStatistics.h"
#include<iostream>

// 统计输入字符串中数字字符和字母字符的个数
void Count() {
    int num[LENGTH];
    char ch;

    // 初始化
    for (int i = 0; i < LENGTH; i++) {    // LENGTH为总长度36(即大写字母个数加数字个数)
        num[i] = 0;
    }

    // 依次读入字符进行判断
    while ((ch = getchar()) != '\n') {
        // 数字字符
        if ('0' <= ch && ch <= '9') {
            int i = ch - 48;
            num[i]++;
        } else if ('A' <= ch && ch <= 'Z')    // 字母字符
        {
            int i = ch - 65 + 10;
            num[i]++;
        }
    }

    // 输出数字字符的个数
    for (int i = 0; i < NUMLENGTH; i++) {          // NUMLENGTH为数字长度10
        std::cout << "数字" << i << "的个数=" << num[i] << std::endl;
    }

    // 输出字母字符的个数
    for (int i = NUMLENGTH; i < LENGTH; i++) {
        std::cout << "字母字符" << char(i + 55) << "的个数=" << num[i] << std::endl;
    }
}