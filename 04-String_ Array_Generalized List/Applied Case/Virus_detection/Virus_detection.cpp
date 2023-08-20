#include "Virus_detection.h"
#include<fstream>
#include<cstring>

using namespace std;

void Virus_detection() {
    int num, m, flag, i, j;
    char Vir[600];
    SString Virus, Person, temp;

    ifstream inFile("病毒感染检测输入数据.txt");
    ofstream outFile("病毒感染检测输出结果.txt");

    // 读取待检测的任务数
    inFile >> num;

    // 依次检测每对病毒DNA和人的DNA是否匹配
    while (num--) {
//        inFile >> Virus.ch + 1;//读取病毒DNA序列
//        inFile >> Person.ch + 1;//读取人的DNA序列

        strcpy(Vir, Virus.ch);
        Virus.length = strlen(Virus.ch) - 1;
        Person.length = strlen(Person.ch) - 1;

        // 用来标识是否匹配，初始为0，匹配后为非0
        flag = 0;
        m = Virus.length;
        for (i = m + 1, j = 1; j <= m; j++)
            Virus.ch[i++] = Virus.ch[j];

        // 因病毒为环状，故将病毒的长度扩大2倍
        // 即可线性取到所有长度为Virus.len的字符串

        // 添加结束符号
        Virus.ch[2 * m + 1] = '\0';

        for (i = 0; i < m; i++) {
            for (j = 1; j <= m; j++) temp.ch[j] = Virus.ch[i + j];
            // 取长为Virus.len的环形字符串
            // 即Virus.ch[0]-- Virus.ch[Virus.length-1],
            // Virus.ch[1]-- Virus.ch[0], Virus.ch[2]-- Virus.ch[1]...

            // 添加结束符号
            temp.ch[m + 1] = '\0';
            temp.length = strlen(temp.ch) - 1;

            // 模式匹配
            flag = Index_BF(Person, temp, 1);
            if (flag)
                break;                // 匹配即可退出循环
        }
        if (flag)
            outFile << Vir + 1 << "	" << Person.ch + 1 << "	" << "YES" << endl;
        else
            outFile << Vir + 1 << "	" << Person.ch + 1 << "	" << "NO" << endl;
    }
}