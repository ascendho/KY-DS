#include "Format.h"
#include <iostream>

// 将s1拆分成s2和s3，要求s2长度为n且两端对齐
void Format(char *s1, char *s2, char *s3, int n) {
    // 指针p和q分别为s1和s2的工作指针
    char *p = s1;
    char *q = s2;

    // 滤掉s1左端所有的空格
    while (*p != '\0' && *p == ' ')
        p++;

    if (*p == '\0') {
        std::cout << "字符串s1为空串或空格串" << std::endl;
        std::exit(0);
    }

    int i = 0;

    // 将s1中的n个字符复制到s2
    while (*p != '\0' && i < n)
    {
        *q = *p;
        q++;
        p++;
        i++;
    }
    p--;
    q--;

    if (*p == '\0') {
        std::cout << "字符串s1没有" << n << "个有效字符" << std::endl;
        exit(0);
    }

    // 若最后一个字符为空格
    if (*q == ' ')
    {
        while (*p == ' ' && *p != '\0')        // 往后查找一个非空格字符作为s2的尾字符
            p++;
        if (*p == '\0') {
            std::cout << "字符串s1没有" << n << "个两端对齐的字符串" << std::endl;
            exit(0);
        }
        *q = *p;                               // 复制s2的最后一个非空字符
    }

    *(++q) = '\0';                          // 置s2结束标记
    q = s3;                                 // q重置为s3
    p++;                                    // 将s1其余部分送入s3

    while (*p != '\0') {
        *q = *p;
        q++;
        p++;
    }
    *q = '\0';                              //置 s3结束标记
}