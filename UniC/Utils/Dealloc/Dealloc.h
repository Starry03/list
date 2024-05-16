#ifndef DEALLOC_H
#define DEALLOC_H

#include "../types.h"

void dealloc_int(Generic addr);
void dealloc_float(Generic addr);
void dealloc_char(Generic addr);
void dealloc_string(Generic addr);
void dealloc_long(Generic addr);
void dealloc_double(Generic addr);

#endif // !DEALLOC_H
