#include "Polynomial.h"
#include <iostream>

// 算法2.18 多项式的创建
// 输入n项的系数和指数，建立表示一个多项式的有序链表P

// 时间复杂度：O(n^2)(因为是有序)

void CreatPolyn(Polynomial &P, int n) {
    PNode *pre;
    PNode *q;

    // 先建立一个带头结点的单链表
    P = new PNode;
    P->next = nullptr;

    for (int i = 1; i <= n; ++i) {
        PNode *s = new PNode;
        std::cin >> s->coef >> s->expn;

        // pre用于保存q的前驱，初值为头结点
        pre = P;

        // q初始化，指向首元结点
        q = P->next;

        // 通过比较指数找到第一个大于输入项指数的项*q
        while (q && q->expn < s->expn) {
            pre = q;
            q = q->next;
        }

        // 将输入项s插入*q和其前驱结点pre之间
        s->next = q;
        pre->next = s;
    }
}

// 算法2.19 多项式的相加
// 多项式加法：Pa=Pa+Pb，利用两个多项式的结点构成“和多项式”

// 时间复杂度：O(m+n)
// 空间复杂度：O(1)

void AddPolyn(Polynomial &Pa, Polynomial &Pb) {
    Polynomial r, p1, p2, p3;
    float sum;

    // p1和p2初值分别指向Pa和Pb的第一个结点
    p1 = Pa->next;
    p2 = Pb->next;

    // p3指向和多项式的当前结点，初值为Pa
    p3 = Pa;

    //p1和p2均非空
    while (p1 && p2) {
        if (p1->expn == p2->expn)      // 指数相等
        {
            sum = p1->coef + p2->coef; // sum保存两项的系数和
            if (sum != 0)              // 系数和不为0
            {
                p1->coef = sum;        // 修改Pa当前结点p1的系数值为两项系数的和
                p3->next = p1;
                p3 = p1;               // 将修改后的Pa当前结点p1链接在p3之后，p3指向p1
                p1 = p1->next;         // p1指向后一项
                r = p2;
                p2 = p2->next;
                delete r;              // 删除Pb当前结点r
            } else                     // 系数和为0
            {
                r = p1;
                p1 = p1->next;
                delete r;               // 删除Pb当前结点p1,p1指向后一项

                r = p2;
                p2 = p2->next;
                delete r;               // 删除Pb当前结点p2,p2指向后一项
            }
        } else if (p1->expn < p2->expn) // Pa当前结点p1的指数值小
        {
            p3->next = p1;              // 将p1链在p3之后
            p3 = p1;                    // p3指向p1
            p1 = p1->next;              // p1指向后一项
        } else                          // Pa当前结点p2的指数值小
        {
            p3->next = p2;              // 将p2链接在p3之后
            p3 = p2;                    // p3指向p2
            p2 = p2->next;              // p2指向后一项
        }
    }
    p3->next = p1 ? p1 : p2;            // 插入非空多项式的剩余段
    delete Pb;                          // 释放Pb的头结点
}