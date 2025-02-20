#ifndef DEALLOC_H
# define DEALLOC_H

# include "unic/types.h"

void	dealloc_int(t_generic addr);
void	dealloc_uint64(t_generic addr);
void	dealloc_float(t_generic addr);
void	dealloc_char(t_generic addr);
void	dealloc_string(t_generic addr);
void	dealloc_long(t_generic addr);
void	dealloc_double(t_generic addr);

#endif // !DEALLOC_H
