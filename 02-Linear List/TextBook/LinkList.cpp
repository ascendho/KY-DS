#include <iostream>
#include "LinkList.h"

/* 严书算法 */

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
// 在带头结点的单链表L中查找第i个元素，用e返回L中第i个数据元素的值
// ASL=(n-1)/2
// 时间复杂度：O(n)

Status GetLinkListElem(LinkList L, int i, ElemType &e) {
    // 初始化，p指向第一个结点，j为计数器
    LinkList p = L->next;
    int j = 1;

    while (j < i && p) {  //顺链域向后扫描，直到p指向第i个元素或p为空
        p = p->next;      //p指向下一个结点
        ++j;              //计数器j相应加1
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
    LinkList p = L->next;

    // 顺链域向后扫描，直到p为空或p所指结点的数据域等于e
    while (p && p->data != e)
        p = p->next;

    // 查找成功返回值为e的结点地址p，查找失败p为NULL
    return p;
}

// 算法2.9 单链表的插入
// 在带头结点的单链表L中第i个位置插入值为e的新结点

Status LinkListInsert(LinkList &L, int i, ElemType e) {
    int j = 0;
    LinkList p = L, s;

    //查找第i-1个结点，p指向该结点
    while (p && j < i - 1) {
        p = p->next;
        ++j;
    }

    // 或者这样
    // GetLinkListElem(L, i - 1, e);
    // p=&e

    // p=GetLinkListElem(L,i-1)

    //i＞n+1或者i＜1
    if (!p || j > i - 1) return ERROR;

    s = new LNode; //生成新结点*s
    s->data = e; //将结点*s的数据域置为e
    s->next = p->next; //将结点*s的指针域指向结点ai
    p->next = s; //将结点*p的指针域指向结点*s

    LinkListInsertToFront(p, e);

    return OK;
}

// 前插

Status LinkListInsertToFront(LinkList &L, ElemType e) {
    LNode *s = new LNode;
    s->data = e;
    s->next = L->next;
    L->next = s;
}

// 算法2.10 单链表的删除
// 在带头结点的单链表L中，删除第i个位置

Status LinkListDelete(LinkList &L, int i) {
    LinkList p = L, q;
    int j = 0;

    // 查找第i-1个结点，p指向该结点
    while ((p->next) && (j < i - 1)) {
        p = p->next;
        ++j;
    }

    // 或者这样
    // GetLinkListElem(L, i - 1, e);
    // p=&e;

    // p=GetLinkListElem(L,i-1)

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
// 时间复杂度：O(n)
// 重要应用：链表的逆置

void CreateList_H(LinkList &L, int n) {
    // 逆位序输入n个元素的值，建立带表头结点的单链接L

    // 先建立一个带头结点的空链表
    InitLinkList(L);

    for (int i = 0; i < n; i++) {
        LNode *s = new LNode;
        std::cin >> s->data;

        // 将新结点*p插入到头结点之后
        s->next = L->next;
        L->next = s;
    }
}

// 算法2.12 后插法创建单链表
// 正位序输入n个元素的值，建立带表头结点的单链表L

// 时间复杂度：O(n)

void CreateList_R(LinkList &L, int n) {
    // 先建立一个带头结点的空链表
    InitLinkList(L);

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

// 后插法创建单链表
// 传递一个数组提供数据用于取代手工输入

void CreateList_R(LinkList &L, const int L_Data[], int n) {
    // 尾指针r指向头结点
    LNode *r = L;
    for (int i = 0; i < n; ++i) {
        LNode *s = new LNode;            // 生成新结点
        s->data = L_Data[i];             // 初始化p的数据域为L_Data[i]
        s->next = nullptr;
        r->next = s;                     // 将新结点*p插入尾结点*r之后
        r = s;                           // r指向新的尾结点*s
    }
}

// 销毁链表
Status DestroyList(LinkList &L) {
    while (L) {
        LNode *p = L;
        L = L->next;
        delete p;                    //释放空间
    }
    return OK;
}

// 输出链表
void PrintList(LinkList L) {
    LNode *p = L->next;
    std::cout << "None";

    while (p) {
        std::cout << " -> " << p->data;
        p = p->next;
    }
    std::cout << std::endl;
}

/* 王道课程补充算法 */

// 判断单链表(带头结点)是否为空
Status LinkListEmpty(LinkList L) {
    if (L->next == nullptr)
        return OK;
    return ERROR;
}

// 按位序插入(不带头结点)
Status LinkListInsertWithoutH(LinkList &L, int i, ElemType e) {
    if (i < 1)
        return ERROR;

    // 插入第1个结点的操作与其他结点操作不同
    if (1 == i) {
        LNode *s = new LNode;
        s->data = e;
        s->next = L;
        L = s;             // 头指针指向新结点
        return OK;
    }

    LNode *p = L;   // 指针p指向第1个结点(注意：不是头结点)
    int j = 1;      // 当前p指向的是第几个结点

    // 循环找到第i-1个结点
    while (p != nullptr && j < i - 1) {
        p = p->next;
        j++;
    }

    // i值不合法
//    if (p == nullptr)
//        return ERROR;
//
//    LNode *s = new LNode;
//    s->data = e;
//    s->next = p->next;
//    p->next = s;

    return InsertNextNode(p, e);
}

// 指定结点的后插操作
// T=(1)

Status InsertNextNode(LNode *p, ElemType e) {
    if (p == nullptr)
        return ERROR;

    LNode *s = new LNode;

    // 内存分配失败(某些情况下有可能分配失败，如内存不足)

    s->data = e;
    s->next = p->next;
    p->next = s;

    return OK;
}

// 指定结点的前插操作
// 取决于实现方式：可传入头指针循环查找p的前驱q，再对q后插，但时间复杂度为O(n)
// “偷天换日”法：时间复杂度为O(1)

// PPT实现版本
Status InsertPriorNode(LNode *p, ElemType e) {
    if (p == nullptr)
        return ERROR;

    LNode *s = new LNode;
    // 内存分配可能失败

    s->next = p->next;
    p->next = s;
    s->data = p->data;
    p->data = e;

    return OK;
}

// 王道书实现版本
Status InsertPriorNode(LNode *p, LNode *s) {
    if (p == nullptr || s == nullptr)
        return ERROR;

    // s连到p之后
    s->next = p->next;
    p->next = s;

    // 交换数据域部分
    ElemType temp = p->data;
    p->data = s->data;
    s->data = temp;

    return OK;
}

// 指定结点的删除
// 取决于实现方式：可传入头指针循环查找p的前驱结点，但时间复杂度为O(n)
// “偷天换日”法(类似于结点前插的实现)：时间复杂度为O(1)

// 局限性：如果p是最后一个结点，则只能从表头开始依次寻找p的前驱，时间复杂度为O(n)
Status DeleteNode(LNode *p) {
    // 注：当p为最后一个结点时需要特殊处理

    if (p == nullptr)
        return ERROR;

    LNode *q = p->next;
    p->data = p->next->data;
    p->next = q->next;

    delete q;

    return OK;
}

// 求表的长度
int LinkListLength(LinkList L) {
    int len = 0;
    LNode *p = L;

    while (p->next != nullptr) {
        p = p->next;
        len++;
    }

    return len;
}


// 按位查找(带头结点)，返回第i个元素
// 时间复杂度：O(n)

// 重载
LNode *GetLinkListElem(LinkList L, int i) {
    if (i < 0)
        return nullptr;

    LNode *p = L; // p指向头结点，头结点是第0个结点(不存数据)
    int j = 0;    // 当前p指向的是第几个结点

    // 循环找到第i个结点
    while (p != nullptr && j < i) {
        p = p->next;
        j++;
    }

    return p;
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