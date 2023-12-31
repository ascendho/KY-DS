#include "SString.h"
#include<cstring>

// 求子串
Status SubString(SString &Sub, SString S, int pos, int len) {
    // 子串范围越界
    if (pos + len - 1 > S.length)
        return ERROR;

    for (int i = pos; i < pos + len; i++)
        Sub.ch[i - pos + 1] = S.ch[i];

    Sub.length = len;
    return OK;
}

// 比较操作
int StrCompare(SString S, SString T) {
    for (int i = 1; i <= S.length && i <= T.length; i++)
        if (S.ch[i] != T.ch[i])
            return S.ch[i] - T.ch[i];

    // 扫描过的所有字符都相同，则长度长的串更大
    return S.length - T.length;
}

// 生成一个其值等于chars的串T
Status StrAssign(SString T, char *chars) {
    if (strlen(chars) > MAXSTRLEN)
        return ERROR;

    T.length = strlen(chars);

    for (int i = 1; i <= T.length; i++)
        T.ch[i] = *(chars + i - 1);

    return OK;
}

// 定位操作
int Index(SString S, SString T) {
    int index = 1, n = S.length, m = T.length;

    // 用于暂存子串
    SString sub;

    while (index <= n - m + 1) {
        SubString(sub, S, index, m);
        if (StrCompare(sub, T) != 0)
            ++index;
        else
            return index;
    }

    // S中不存在与T相等的子串
    return 0;
}