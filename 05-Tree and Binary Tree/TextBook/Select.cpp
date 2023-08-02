#include "HuffmanTree.h"

void Select(HuffmanTree HT, int len, int &s1, int &s2) {
    // 先赋予最大值
    int i, min1 = 0x3f3f3f3f, min2 = 0x3f3f3f3f;

    for (i = 1; i <= len; i++) {
        if (HT[i].weight < min1 && HT[i].parent == 0) {
            min1 = HT[i].weight;
            s1 = i;
        }
    }

    // 将原值存放起来，然后先赋予最大值，防止s1被重复选择
    int temp = HT[s1].weight;
    HT[s1].weight = 0x3f3f3f3f;

    for (i = 1; i <= len; i++) {
        if (HT[i].weight < min2 && HT[i].parent == 0) {
            min2 = HT[i].weight;
            s2 = i;
        }
    }

    // 恢复原来的值
    HT[s1].weight = temp;
}