#include "IsPalindrome.h"

/*
 * 回文是指正读、反读均相同的字符序列，如“abba”和“abdba”均是回文，但
   “good”不是回文。试设计算法判定给定的字符序列是否为回文。（提示：将一半字符入栈。）
 */

// 判断t字符向量是否为回文，若是，返回1，否则返回0
Status IsPalindrome(char *t, int length) {
    SqStack S;
    int i;
    InitSqStack(S);

    // 将一半字符入栈
    for (i = 0; i < length / 2; i++)
        Push(S, t[i]);

    // 长度为奇数，跳过中间字段
    if (length % 2 != 0)
        i++;

    // 每次弹出一个字符与相应字符比较
    while (!StackEmpty(S)) {
        char temp;
        Pop(S, temp);
        if (temp != t[i])
            return ERROR;
        else
            i++;
    }
    return OK;
}

// 双指针版本

Status IsPalindrome_DP(char t[], int length) {
    int head = 0, rear = length - 1;

    while (head < rear) {
        if (t[head] != t[rear])
            return ERROR;

        head++;
        rear--;
    }

    return OK;
}