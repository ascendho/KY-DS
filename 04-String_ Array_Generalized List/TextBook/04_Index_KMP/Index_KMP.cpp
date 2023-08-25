#include "Index_KMP.h"

/* 字符串匹配算法 */

// 算法4.2　KMP算法
// 利用模式串T的next函数求T在主串S中第pos个字符之后的位置的KMP算法
// 其中，T非空，1≤pos≤StrLength(S)

int Index_KMP(SString S, SString T, int pos, const int next[]) {
    int i = pos, j = 1;

    // 两个串均未比较到串尾
    while (i <= S.length && j <= T.length)
        if (j == 0 || S.ch[i] == T.ch[j]) {
            // 继续比较后续字符
            ++i;
            ++j;
        } else
            // 模式串向右移动
            j = next[j];

    // 匹配成功
    if (j > T.length)
        return i - T.length;
    else
        return 0;
}