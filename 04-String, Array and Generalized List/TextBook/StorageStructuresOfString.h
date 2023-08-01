#ifndef TEXTBOOK_STORAGESTRUCTURESOFSTRING_H
#define TEXTBOOK_STORAGESTRUCTURESOFSTRING_H

#include "../../Status/Status.h"

/* 串的堆式顺序存储结构 */

typedef struct {
    char *ch;      // 若是非空串，则按串长分配存储区，否则ch为NULL
    int length;    // 串的当前长度　
} HString;

/* 顺序串 */

typedef struct {
    char ch[MAXSTRLEN + 1];   // 存储串的一维数组
    int length;               // 串的当前长度　
} SString;

/* 串的链式存储结构 */

typedef struct Chunk {
    char ch[CHUNKSIZE];
    struct Chunk *next;
} Chunk;

typedef struct {
    Chunk *head, *tail;   // 串的头和尾指针　
    int length;          // 串的当前长度　
} LString;

#endif //TEXTBOOK_STORAGESTRUCTURESOFSTRING_H