#include "DuLinkList.h"

// 算法2.13 双向链表的插入
// 在带头结点的双向链表L中第i个位置之前插入元素e, i的合法值为1<=i<=表长+1

Status ListInsert_DuL(DuLinkList &L, int i, ElemType e) {
    DuLNode *p;

    // 在L中确定第i个元素的位置指针p, p为NULL时，第i个元素不存在
    if (!(p = GetElemP_DuL(L, i)))
        return ERROR;

    // 生成新节点*s
    DuLNode *s = new DuLNode;
    s->data = e;

    // 将节点*s插入L中
    s->prior = p->prior;
    p->prior->next = s;
    s->next = p;
    p->prior = s;

    return OK;
}

// 算法2.14 双向链表的删除
// 删除带头节点的双向链表L中的第i个元素

Status ListDelete_DuL(DuLinkList &L, int i) {
    DuLNode *p;

    // 在L中确定第i个元素的位置指针p, p为NULL时，第i个元素不存在
    if (!(p = GetElemP_DuL(L, i)))
        return ERROR;

    // 修改指针
    p->prior->next = p->next;
    p->next->prior = p->prior;

    // 释放被删除结点的空间
    delete p;

    return OK;
}

// 在带头结点的双向链表L中查找第i个元素, 返回结点的地址
DuLNode *GetElemP_DuL(DuLinkList L, int i) {
    // 初始化, p指向第一个结点, j为计数器
    int j = 1;
    DuLinkList p = L->next;

    // 顺链域向后扫描, 直到p指向第i个元素或p为空
    while (j < i && p) {
        p = p->next;
        ++j;
    }

    // 第i个元素不存在
    if (!p || j > i)
        return nullptr;

    return p;
}