#include "Dealloc.h"
#include <stdlib.h>

inline void dealloc_int(Generic addr) { free((int *)addr); }
inline void dealloc_float(Generic addr) { free((float *)addr); }
inline void dealloc_string(Generic addr) { free((char *)addr); }
inline void dealloc_long(Generic addr) { free((long long *)addr); }
inline void dealloc_double(Generic addr) { free((double *)addr); }
