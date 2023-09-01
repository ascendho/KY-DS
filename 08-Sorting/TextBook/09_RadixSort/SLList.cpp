#include "SLList.h"
#include <iostream>

// 按数组序号输出静态链表
void print(SLList L) {
    for (int i = 1; i <= L.recnum; i++) {
        for (int j = L.keynum - 1; j >= 0; j--)
            std::cout << L.r[i].keys[j];
        std::cout << std::endl;
    }
}

// 求得adr[1..L.length]，adr[i]为静态链表L的第i个最小记录的序号
void Sort(SLList L, int adr[]) {
    int i = 1, p = L.r[0].next;
    while (p) {
        adr[i++] = p;
        p = L.r[p].next;
    }
}

// adr给出静态链表L的有序次序，即L.r[adr[i]]是第i小的记录。
// 本算法按adr重排L.r，使其有序

void Rearrange(SLList *L, int adr[]) {
    int i = 0, j, k;
    if (adr[i] != i) {
        j = i;
        (*L).r[0] = (*L).r[i];         // 暂存记录(*L).r[i]

        while (adr[j] != i) {
            // 调整(*L).r[adr[j]]的记录到位直到adr[j]=i为止
            k = adr[j];
            (*L).r[j] = (*L).r[k];
            adr[j] = j;
            j = k;                     // 记录按序到位
        }
        (*L).r[j] = (*L).r[0];
        adr[j] = j;
    }
}