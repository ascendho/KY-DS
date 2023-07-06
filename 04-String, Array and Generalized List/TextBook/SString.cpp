#include "SString.h"

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

// 定位操作
int Index(SString S, SString T) {
    int i = 1, n = S.length, m = T.length;

    // 用于暂存子串
    SString sub;

    while (i <= n - m + 1) {
        SubString(sub, S, i, m);
        if (StrCompare(sub, T) != 0)
            ++i;
        else
            return i;
    }

    // S中不存在与T相等的子串
    return 0;
}




