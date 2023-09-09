#include "Judge.h"
#include <iostream>

/* <1>在入栈出栈的过程中, 需要满足在入栈出栈序列的任一位置, 入栈次数即 “I” 的个数,
     必须大于或等于出栈次数即 “O" 的个数, 否则视作非法序列。经检验, A和D是合法序列,
     B和C是非法序列 */

// <2>
// 判断A中的输入输出序列是否是合法序列. 如果是, 返回true, 否则返回false
bool Judge(char A[]) {
    int i = 0;                    // i为下标
    int j = 0, k = 0;             // j和k分别为I和字母O的个数

    while (A[i] != '\0')          // 未到字符数组尾时判断序列是否合法
    {
        switch (A[i]) {
            case 'I':
                j++;              // 入栈次数加1
                break;
            case 'O':
                k++;
                if (k > j) {
                    std::cout << "序列非法" << std::endl;
                    return false;
                }
        }
        i++;                      // 不论A[i]是'I'或'O', 指针i均后移
    }

    if (k != j) {
        std::cout << "序列非法" << std::endl;
        return false;
    } else {
        std::cout << "序列合法" << std::endl;
        return true;
    }
}