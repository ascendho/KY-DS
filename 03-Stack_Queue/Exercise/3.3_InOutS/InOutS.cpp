#include "InOutS.h"
#include "../../../Status/Status.h"
#include <iostream>

// 用数组s模拟栈, 根据读入的数据完成入栈和出栈操作
void InOutS(int s[]) {
    int top = 0;                            // top为栈顶指针, top=0时为栈空

    int maxsize = 5;                        // 设置栈容量是5
    int n = 5;                              // 对5个整数序列进行处理

    for (int i = 1; i <= n; i++)            // 对n个整数序列进行处理
    {
        int x;
        std::cin >> x;                      // 从键盘读入整数序列
        if (x != -1)                        // 读入的整数不等于-1时入栈
        {
            if (top == maxsize - 1) {
                std::cout << "栈满" << std::endl;
                exit(ERROR);
            } else
                s[++top] = x;               // x入栈
        } else                              // 读入的整数等于-1时退栈
        {
            if (top == 0) {
                std::cout << "栈空" << std::endl;
                exit(ERROR);
            } else
                std::cout << "出栈元素是" << s[top--] << std::endl;
        }
    }
}