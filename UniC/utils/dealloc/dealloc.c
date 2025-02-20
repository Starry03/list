# include "unic/dealloc.h"
#include <stdint.h>
#include <stdlib.h>

inline void	dealloc_int(t_generic addr)
{
	free((int *)addr);
}
void	dealloc_uint64(t_generic addr)
{
	free((uint64_t *)addr);
}
inline void	dealloc_float(t_generic addr)
{
	free((float *)addr);
}
inline void	dealloc_string(t_generic addr)
{
	free((char *)addr);
}
inline void	dealloc_long(t_generic addr)
{
	free((long long *)addr);
}
inline void	dealloc_double(t_generic addr)
{
	free((double *)addr);
}
