#include <iostream>
#include "Matching.h"

using namespace std;

int main() {
    // 解决中文乱码问题
    system("chcp 65001");

    // 调用括号匹配函数
    cout << "请输入待匹配的表达式，以“#”结束：" << endl;
    int flag = (int) Matching();

    if (flag)
        cout << "括号匹配成功！" << endl;
    else
        cout << "括号匹配失败！" << endl;
    return 0;
}