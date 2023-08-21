#ifndef EXERCISE_ISPALINDROME_H
#define EXERCISE_ISPALINDROME_H

#include "../../../Status/Status.h"
#include "../../TextBook/01_SqStack/SqStack.h"

// 判断t字符向量是否为回文
Status IsPalindrome(char *t, int length);

// 双指针版本
Status IsPalindrome_DP(char t[], int length);

#endif //EXERCISE_ISPALINDROME_H