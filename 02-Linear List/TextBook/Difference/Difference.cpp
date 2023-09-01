#include "Difference.h"
#include <iostream>

// 依次输入集合A和B的元素, 在一维数组space中建立表示集合(A-B)∪(B-A)的静态链表, S为头指针
// 假设备用空间足够大, space[0].cur为头指针

void difference(SLinkList &space, int &S) {
    InitSpace_SL(space);             // 初始化备用空间
    S = Malloc_SL(space);         // 生成S的头结点
    int r = S;                       // r指向S的当前最后结点

    int m, n;
    ElemType b;

    std::cin >> m >> n;

    for (int j = 1; j <= m; ++j) {        // 建立集合A的链表
        int i = Malloc_SL(space);      // 分配结点
        std::cin >> space[i].data;        // 输入A的元素值
        space[r].cur = i;
        r = i;                            // 插入到表尾
    }

    space[r].cur = 0;                     // 尾结点的指针为空

    for (int j = 1; j <= n; ++j) {
        // 依次输入B的元素,若不在当前表中,则插入,否则删除
        std::cin >> b;                         // 输入B的元素值
        int p = S;
        int k = space[S].cur;                  // k指向集合A中第一个结点

        // 在当前表中查找
        while (k != space[r].cur && space[k].data != b) {
            p = k;
            k = space[k].cur;
        }

        // 当前表中不存在该元素,插入在r所指结点之后，且r的位置不变
        if (k == space[r].cur) {
            int i = Malloc_SL(space);
            space[i].data = b;
            space[i].cur = space[r].cur;
            space[r].cur = i;
        } else {                          // 该元素已在表中,删除之
            space[p].cur = space[k].cur;
            Free_SL(space, k);
            if (r == k)
                r = p;                    // 若删除的是尾元素，则需修改尾指针
        }
    }
}