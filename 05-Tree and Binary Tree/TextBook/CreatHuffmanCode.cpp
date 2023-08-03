#include "HuffmanTree.h"
#include <cstring>

// 算法5.11 根据赫夫曼树求赫夫曼编码
// 从叶子到根逆向求每个字符的赫夫曼编码，存储在编码表HC中

void CreatHuffmanCode(HuffmanTree HT, HuffmanCode &HC, int n) {
    int start, c, f;

    HC = new char *[n + 1];                                // 分配n个字符编码的头指针矢量

    char *cd = new char[n];                                // 分配临时存放编码的动态数组空间
    cd[n - 1] = '\0';                                      // 编码结束符

    for (int i = 1; i <= n; ++i) {                         // 逐个字符求赫夫曼编码
        start = n - 1;                                     // start开始时指向最后，即编码结束符位置
        c = i;
        f = HT[i].parent;                                  // f指向结点c的双亲结点
        while (f != 0) {                                   // 从叶子结点开始向上回溯，直到根结点
            --start;                                       // 回溯一次start向前指一个位置
            if (HT[f].lchild == c)
                cd[start] = '0';                           // 结点c是f的左孩子，则生成代码0
            else
                cd[start] = '1';                           // 结点c是f的右孩子，则生成代码1
            c = f;
            f = HT[f].parent;                              // 继续向上回溯
        }                                                  // 求出第i个字符的编码

        HC[i] = new char[n - start];                       // 为第i个字符编码分配空间
        strcpy(HC[i], &cd[start]);            // 将求得的编码从临时空间cd复制到HC的当前行中
    }

    // 释放临时空间
    delete cd;
}