#include <iostream>
#include "LinkList.h"

// 算法2.6 单链表的初始化
// 构造一个空的单链表L

Status InitLinkList(LinkList &L) {
    // 生成新结点作为头结点，用头指针L指向头结点
    L = new LNode;

    // 头结点的指针域置空
    L->next = nullptr;

    return OK;
}

// 算法2.7 单链表的取值(按位查找)
// 在带头节点的单链表L中根据序号i获取元素的值, 用e返回L中第i个数据元素的值

// ASL: (n-1)/2
// 时间复杂度: O(n)

Status GetLinkListElem(LinkList L, int i, ElemType &e) {
    // 初始化，p指向首元结点, 计数器j初值赋为1
    LinkList p = L->next;
    int j = 1;

    while (p && j < i) {  // 顺链域向后扫描, 直到p指向第i个元素或p为空
        p = p->next;      // p指向下一个结点
        ++j;              // 计数器j相应加1
    }

    // i值不合法i＞n或i<=0
    if (!p || j > i) return ERROR;

    // 取第i个结点的数据域
    e = p->data;
    return OK;
}

// 算法2.8 按值查找
// 在带头结点的单链表L中查找值为e的元素

LNode *LocateLinkListElem(LinkList L, ElemType e) {
    // 初始化, p指向首元节点
    LinkList p = L->next;

    // 顺链域向后扫描, 直到p为空或p所指结点的数据域等于e
    while (p && p->data != e)
        p = p->next;

    // 查找成功返回值为e的结点地址p, 查找失败p为NULL
    return p;
}

// 算法2.9 单链表的插入
// 在带头结点的单链表L中第i个位置插入值为e的新结点

Status LinkListInsert(LinkList &L, int i, ElemType e) {
    int j = 0;
    LinkList p = L;

    // 查找第i-1个结点, p指向该结点
    while (p && j < i - 1) {
        p = p->next;
        ++j;
    }

    // i＞n+1或者i＜1
    if (!p || j > i - 1) return ERROR;

    // 生成新结点*s
    LNode *s = new LNode;
    s->data = e;

    s->next = p->next;          // 将结点*s的指针域指向结点ai
    p->next = s;                // 将结点*p的指针域指向结点*s

    return OK;
}

// 算法2.10 单链表的删除
// 在带头结点的单链表L中, 删除第i个元素

Status LinkListDelete(LinkList &L, int i) {
    LinkList p = L, q;
    int j = 0;

    // 查找第i-1个结点, p指向该结点
    while ((p->next) && (j < i - 1)) {
        p = p->next;
        ++j;
    }

    // 当i>n或i<1时，删除位置不合理
    if (!(p->next) || (j > i - 1)) return ERROR;

    // 临时保存被删结点的地址以备释放
    q = p->next;

    // 改变删除结点前驱结点的指针域
    p->next = q->next;

    //释放删除结点的空间
    delete q;

    return OK;
}

// 算法2.11 前插法创建单链表
// 逆位序输入n个元素的值, 建立带表头结点的单链接L

// 时间复杂度：O(n)
// 重要应用：链表的逆置

void CreateList_H(LinkList &L, int n) {
    // 先建立一个带头结点的空链表
    L = new LNode;
    L->next = nullptr;

    for (int i = 0; i < n; i++) {
        LNode *s = new LNode;
        std::cin >> s->data;

        // 将新结点*p插入到头结点之后
        s->next = L->next;
        L->next = s;
    }
}

// 算法2.12 后插法创建单链表
// 正位序输入n个元素的值, 建立带表头结点的单链表L

// 时间复杂度：O(n)

void CreateList_R(LinkList &L, int n) {
    // 先建立一个带头结点的空链表
    L = new LNode;
    L->next = nullptr;

    // 尾指针r指向头结点
    LNode *r = L;

    for (int i = 0; i < n; ++i) {
        LNode *s = new LNode;
        std::cin >> s->data;

        // 将新结点*p插入尾结点*r之后
        s->next = nullptr;
        r->next = s;

        // r指向新的尾结点
        r = s;
    }
}

//判断List里有没有e这个元素
Status ElemIsInLinkList(LinkList L, ElemType e) {
    LNode *p = L->next;
    while (p != nullptr) {
        if (p->data == e)
            return OK;

        p = p->next;
    }
    return ERROR;
}