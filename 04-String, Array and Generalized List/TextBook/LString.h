#ifndef TEXTBOOK_LSTRING_H
#define TEXTBOOK_LSTRING_H

// 串的链式存储结构

#include "../../Status/Status.h"

typedef struct Chunk {
    char ch[CHUNKSIZE];
    struct Chunk *next;
} Chunk;

typedef struct {
    Chunk *head, *tail;   // 串的头和尾指针　
    int length;          // 串的当前长度　
} LString;

#endif //TEXTBOOK_LSTRING_H