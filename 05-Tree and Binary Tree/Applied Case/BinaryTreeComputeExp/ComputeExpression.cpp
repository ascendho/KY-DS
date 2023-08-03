#include "ComputeExpression.h"
#include<iostream>

// 算法5.12 表达式树的创建

// 时间复杂度: O(n)
// 空间复杂度: O(n)

void InitExpTree(BiTree &T) {
    SqStack OPTR;
    BiTreeStack EXPT;

    char ch, theta, x;
    BiTree a, b;

    InitSqStack(OPTR);
    Push(OPTR, '#');
    InitBiTreeStack(EXPT);

    std::cin >> ch;
    while (ch != '#' || GetTop(OPTR) != '#') {
        if (!In(ch)) {
            CreateExpTree(T, nullptr, nullptr, ch);
            PushBiTree(EXPT, T);
            std::cin >> ch;
        } else
            switch (Precede(GetTop(OPTR), ch)) {
                case '<':
                    Push(OPTR, ch);
                    std::cin >> ch;
                    break;
                case '>':
                    Pop(OPTR, theta);
                    PopBiTree(EXPT, b);
                    PopBiTree(EXPT, a);
                    CreateExpTree(T, a, b, theta);    //*
                    PushBiTree(EXPT, T);
                    break;
                case '=':
                    Pop(OPTR, x);
                    std::cin >> ch;
                    break;
            }
    }
}

// 算法5.13 表达式树的求值
// 本质: 后序遍历二叉树

// 时间复杂度: O(n)
// 空间复杂度: O(n)

int EvaluateExTree(BiTree T) {
    int lvalue, rvalue;
    lvalue = rvalue = 0;

    if (T->lchild == nullptr && T->rchild == nullptr)
        return T->data - '0';
    else {
        lvalue = EvaluateExTree(T->lchild);
        rvalue = EvaluateExTree(T->rchild);

        return GetValue(T->data, lvalue, rvalue);    // 运算函数
    }
}

// 简单二叉树的创建
void CreateExpTree(BiTree &T, BiTree a, BiTree b, char ch) {
    T = new BiTNode;
    T->data = ch;
    T->lchild = a;
    T->rchild = b;
}

// 树栈初始化
void InitBiTreeStack(BiTreeStack &S) {
    S.base = new BiTree[MAXSIZE];
    if (!S.base) exit(-1);

    S.top = S.base;
    S.stacksize = MAXSIZE;
}

// 树栈入栈
void PushBiTree(BiTreeStack &S, BiTree e) {
    if (S.top - S.base == S.stacksize) return;
    *S.top = e;
    S.top++;
}

// 树栈出栈
void PopBiTree(BiTreeStack &S, BiTree &e) {
    if (S.top == S.base) return;
    e = *--S.top;
}

/* 根据教科书表3.1，判断两符号的优先关系 */
char Precede(char t1, char t2) {
    char f;
    switch (t2) {
        case '+':
            if (t1 == '(' || t1 == '#')
                f = '<';
            else
                f = '>';
            break;
        case '-':
            if (t1 == '(' || t1 == '#')
                f = '<';
            else
                f = '>';
            break;
        case '*':
            if (t1 == '*' || t1 == '/' || t1 == ')')
                f = '>';
            else
                f = '<';
            break;
        case '/':
            if (t1 == '*' || t1 == '/' || t1 == ')')
                f = '>';
            else
                f = '<';
            break;
        case '(':
            if (t1 != ')')
                f = '<';
            break;
        case ')':
            if (t1 == '(')
                f = '=';
            else
                f = '>';
            break;
        case '#':
            if (t1 == '#')
                f = '=';
            else
                f = '>';
    }

    return f;
}

/* 判断c是否为运算符 */
int In(char c) {
    switch (c) {
        case '+':
        case '-':
        case '*':
        case '/':
        case '#':
        case '(':
        case ')':
            return 1;
            break;
        default:
            return 0;
    }
}

// 进行运算的函数
int GetValue(char theta, int a, int b) {
    int c;
    switch (theta) {
        case '+':
            c = a + b;
            break;
        case '-':
            c = a - b;
            break;
        case '*':
            c = a * b;
            break;
        case '/':
            c = a / b;
            break;
        default:
            break;
    }
    return c;
}