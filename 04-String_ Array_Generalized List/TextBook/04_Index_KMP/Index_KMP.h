#ifndef TEXTBOOK_INDEX_KMP_H
#define TEXTBOOK_INDEX_KMP_H

#include "../01_SString/SString.h"
#include "../../../Status/Status.h"
#include "../03_next/next.h"

int Index_KMP(SString S, SString T, int pos, const int next[]);

#endif //TEXTBOOK_INDEX_KMP_H