#include "Index_BF.h"

/* 字符串匹配算法 */

// 算法4.1　BF算法
// 返回模式T在主串S中第pos个字符之后第s一次出现的位置。若不存在，则返回值为0
// 其中，T非空，1≤pos≤StrLength(S)

int Index(SString S, SString T, int pos) {
    int i = pos;
    int j = 1;

    while (i <= S.length && j <= T.length) {
        // 继续比较后继字符
        if (S.ch[i] == T.ch[j]) {
            ++i;
            ++j;
        } else {
            // 指针后退重新开始匹配
            i = i - j + 2;
            j = 1;
        }
    }

    if (j > T.length)
        return i - T.length;
    else
        return 0;
}