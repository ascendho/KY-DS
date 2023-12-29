#include<iostream>

void Insert(char *s, char *t, int pos) {
    char *p = s;    // p是字符串s的工作指针
    char *q = t;    // q是字符串t的工作指针

    int i = 0, x = 0;    // i查找pos位置，x记录串t的长度

    // 插入位置pos合法性判断
    if (pos < 1) {
        std::cout << "pos参数位置非法" << std::endl;
    }

    // 查找pos位置，找到时i=pos
    while (*p != '\0' && i < pos) {
        p++;
        i++;
    }

    // pos的位置大于字符串s的长度
    if (*p == '\0') {
        std::cout << pos << "位置大于字符串s的长度";
        exit(0);
    } else  // 查找字符串的尾
    {
        while (*p != '\0')    // 查到串尾时，i为字符'\0'的下标，p指向'\0'
        {
            p++;
            i++;
        }
    }

    // 查找字符串t的长度x，循环结束时q指向'\0'
    while (*q != '\0')
    {
        q++;
        x++;
    }

    // 串s的pos后的子串右移，空出串t的位置
    for (int j = i; j >= pos; j--)
    {
        *(p + x) = *p;
        p--;
    }

    q--;          // 指针q回退到串t的最后一个字符
    p = p + x;    // 指针p重新置回插入的位置

    // 将t串插入到s的pos位置上
    for (int j = 1; j <= x; j++) {
        *p-- = *q--;
    }
}