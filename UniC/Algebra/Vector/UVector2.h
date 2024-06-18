#ifndef UVECTOR2_H
# define UVECTOR2_H

# include <stdint.h>

typedef struct s_uvector2
{
	uint64_t		x;
	uint64_t		y;
}					t_uvector2_;

typedef t_uvector2_	*t_uvector2;

t_uvector2			UVector2_init(uint64_t x, uint64_t y);
void				UVector2_free(t_uvector2 vector);

#endif