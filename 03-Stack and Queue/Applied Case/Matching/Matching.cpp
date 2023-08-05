#include "Matching.h"
#include <iostream>

/* 链栈实现括号匹配 */

// 算法3.21　括号的匹配
// 教材中没有'{'和'}'的匹配，这里添加上了
// 检验表达式中所含括号是否正确匹配，如果匹配，则返回true，否则返回false

// 时间复杂度：O(n)
// 空间复杂度：O(n)

Status Matching() {
    // 表达式以“#”结束
    char ch;
    SElemType x;

    // 初始化空栈
    LinkStack S;
    InitStack(S);

    // 标记匹配结果以控制循环及返回结果
    int flag = 1;

    // 读入第一个字符
    std::cin >> ch;

    // 假设表达式以“#”结尾
    while (ch != '#' && flag)
    {
        switch (ch) {
            case '{':
            case '[' :
            case '(':                                    // 若是左括号，则将其压入栈
                Push(S, ch);
                break;

            case '}':                                    // 若是“]”，则根据当前栈顶元素的值分情况考虑
                if (!StackEmpty(S) && GetTop(S) == '{')
                    Pop(S, x);                     // 若栈非空且栈顶元素是“[”，则正确匹配
                else
                    flag = 0;                            // 若栈空或栈顶元素不是“[”，则错误匹配
                break;
            case ')':                                    // 若是“)”，则根据当前栈顶元素的值分情况考虑
                if (!StackEmpty(S) && GetTop(S) == '(')
                    Pop(S, x);                     // 若栈非空且栈顶元素是“(”，则正确匹配
                else
                    flag = 0;                            // 若栈空或栈顶元素不是“(”，则错误失败
                break;
            case ']':                                    // 若是“]”，则根据当前栈顶元素的值分情况考虑
                if (!StackEmpty(S) && GetTop(S) == '[')
                    Pop(S, x);                     // 若栈非空且栈顶元素是“[”，则正确匹配
                else
                    flag = 0;                            // 若栈空或栈顶元素不是“[”，则错误匹配
                break;
        }

        // 继续读入下一个字符
        std::cin >> ch;
    }

    // 匹配成功
    if (StackEmpty(S) && flag)
        return true;
    else
        return false; // 匹配失败
}