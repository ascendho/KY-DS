#include "Difference.h"

/*
 * 已知两个链表A和B分别表示两个集合，其元素递增排列。请设计算法求出两个集合A
   和B的差集（仅由在A中出现而不在B中出现的元素所构成的集合），并将结果以同样的形式存
   储，同时返回该集合的元素个数
 */

// 求差集
// La和Lb差集的结果存储于La中，n是结果集合中元素个数，调用时为0

void Difference(LinkList &La, LinkList &Lb, int &n) {
    LNode *pa = La->next;                // pa是链表La的工作指针,初始化为首元结点
    LNode *pb = Lb->next;                // pb是链表Lb的工作指针,初始化为首元结点
    LNode *pre = La;                     // pre为La中pa所指结点的前驱结点的指针
    while (pa && pb)                     // 两个链表La和Lb均未到达表尾结点
    {
        if (pa->data < pb->data)         // A链表中当前结点指针后移
        {
            n++;
            pre = pa;
            pa = pa->next;
        } else if (pa->data > pb->data)
            pb = pb->next;               // B链表中当前结点指针后移
        else                             // 在La表删除La和Lb中元素值相同的结点
        {
            pre->next = pa->next;
            LNode *u = pa;
            pa = pa->next;
            delete u;                    // 删除结点
        }
    }
    while (pa) {
        n++;
        pa = pa->next;
    }
}

/*
 * 求两个集合的差集是指在A中删除A和B中共有的元素，即删除链表中的数据域相等的结点。
 * 由于要删除结点，此题的关键点在于：在遍历链表时，需要保存待删除结点的前驱。
 */

/*
 * 算法思想是：假设待求的链表为La、Lb,pa和pb分别是链表La、Lb的工作指针，初始化为相应链表的首元结点。
 * pre为La中pa所指结点的前驱结点的指针，初始化为La。
 * 从首元结点开始进行比较，当两个链表la、lb均未到达表尾结点时，如果La表中的元素小于Lb表中的
 * 元素，La表中的元素即为待求差集中的元素，差集元素个数增1, pre置为la表的工作指针pa,pa后移；
 * 如果lb表中的元素小于la表中的元素，pb后移；如果La表中的元素等于Lb表中的元素，
 * 则在La表删除该元素值对应的结点。
 */