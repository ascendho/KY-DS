#ifndef TEXTBOOK_SSTRING_H
#define TEXTBOOK_SSTRING_H

#include "../../Status/Status.h"

typedef struct{
    char ch[MAXSTRLEN+1];  // 存储串的一维数组
    int length;            // 串的当前长度　
}SString;

Status SubString(SString& Sub,SString S,int pos,int len);

int StrCompare(SString S,SString T);

int Index(SString S,SString T);

#endif //TEXTBOOK_SSTRING_H