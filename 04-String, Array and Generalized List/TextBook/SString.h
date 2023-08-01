#ifndef TEXTBOOK_SSTRING_H
#define TEXTBOOK_SSTRING_H

#include "StorageStructuresOfString.h"

Status SubString(SString &Sub, SString S, int pos, int len);

int StrCompare(SString S, SString T);

Status StrAssign(SString T, char *chars);

int Index(SString S, SString T);

#endif //TEXTBOOK_SSTRING_H