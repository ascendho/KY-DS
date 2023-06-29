#include "DuLinkList.h"

/* 严书算法 */

Status InitDuList_L(DuLinkList &L) {
    //构造一个空的双向链表L
    L = new DuLNode;   //生成新结点作为头结点，用头指针L指向头结点
    L->next = nullptr; //头结点的指针域置空
    L->prior = nullptr;

    return OK;
}

DuLNode *GetElemP_DuL(DuLinkList L, int i) {
    //在带头结点的双向链表L中查找第i个元素，返回结点的地址
    int j = 1;
    DuLinkList p = L->next; //初始化，p指向第一个结点，j为计数器

    while (j < i && p) { //顺链域向后扫描，直到p指向第i个元素或p为空
        p = p->next;
        ++j;
    }
    if (!p || j > i)
        return nullptr; //第i个元素不存在

    return p;
}

//算法2.13 双向链表的插入
Status ListInsert_DuL(DuLinkList &L, int i, ElemType e) {
    //在带头结点的双向链表L中第i个位置之前插入元素e，i的合法值为1<=i<=表长+1
    DuLinkList s, p;
    if (!(p = GetElemP_DuL(L, i)))  //在L中确定第i个元素的位置指针p
        return ERROR;               //p为NULL时，第i个元素不存在
    if (i == 1) {                   //在双向链表的第一个元素上插入
        s = new DuLNode;            //生成新结点s
        s->data = e;                //将结点s数据置为e
        DuLinkList p = L->next;
        L->next = s;
        s->prior = L;
        s->next = p;                //将结点*s插入L中
        p->prior = s;
        ++length;
    } else if (i == length) {       //在双向链表的最后一个元素上插入
        s = new DuLNode;            //生成新结点s
        s->data = e;                //将结点s数据置为e
        DuLinkList p = L;
        while (p->next)
            p = p->next;            //将LinkList p指向双向链表结尾
        p->next = s;
        s->prior = p;               //将结点*s插入到p的后面，插入到L中
        s->next = nullptr;
        ++length;
    } else {
        s = new DuLNode;           //生成新结点*s
        s->data = e;               //将结点*s数据域置为e
        s->prior = p->prior;       //将结点*s插入L中，此步对应图2.20①
        p->prior->next = s;        //对应图2.20②
        s->next = p;               //对应图2.20③
        p->prior = s;              //对应图2.20④
        ++length;
    }

    return OK;
}

//算法2.14 双向链表的删除

Status ListDelete_DuL(DuLinkList &L, int i) {
    //删除带头结点的双向链表L中第i个位置之前插入元素e，i的合法值为1<=i<=表长
    DuLinkList p;
    if (!(p = GetElemP_DuL(L, i))) //在L中确定第i个元素的位置指针p
        return ERROR;              //p为NULL时，第i个元素不存在
    if (i == 1)                    //删除双向链表的第一个元素
        L = L->next;
    else if (i == length) {        //删除双向链表的最后一个元素
        p->prior->next = nullptr;
        delete p;
        --length;
        return OK;
    } else {
        p->prior->next = p->next;  //修改被删结点的前驱结点的后继指针，对应图2.21①
        p->next->prior = p->prior; //修改被删结点的后继结点的前驱指针，对应图2.21②
        delete p;                  //释放被删结点的空间
        --length;
        return OK;
    }
}

/* 王道补充算法 */

// 删除p的后继结点
Status DeleteNextNode(DuLNode *p) {
    if (p == nullptr) return ERROR;

    DuLNode *q = p->next;
    if (q == nullptr) return ERROR;

    p->next = q->next;

    // q结点不是最后一个结点
    if (q->next != nullptr)
        q->next->prior = p;

    delete q;

    return OK;
}

void DestroyList(DuLinkList &L) {
    // 循环释放各个数据结点
    while (L->next != nullptr)
        DeleteNextNode(L);

    // 释放头结点，头指针指向NULL
    delete L;
    L = nullptr;

}

void TravelList(DuLinkList L, void (Visit)(ElemType)) {
    DuLinkList p;

    // 确保双向循环链表存在
    if (L == nullptr || L->next == L || L->prior == L)
        exit(OVERFLOW);

    p = L->next;

    while (p != L) {
        Visit(p->data);
        p = p->next;
    }

}
