#ifndef TEXTBOOK_HSTRING_H
#define TEXTBOOK_HSTRING_H

// 串的堆式顺序存储结构
typedef struct {
    char *ch;      // 若是非空串，则按串长分配存储区，否则ch为NULL
    int length;    // 串的当前长度　
} HString;

#endif //TEXTBOOK_HSTRING_H