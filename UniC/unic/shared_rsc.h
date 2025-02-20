#ifndef SHARED_RSC_H
# define SHARED_RSC_H

# include "unic/types.h"
# include <semaphore.h>
# include <stddef.h>

typedef struct s_shared_rsc
{
	t_generic			data;
	t_deallocator		dealloc;
	sem_t				*sem;
}						t_shared_rsc_;

typedef t_shared_rsc_	*t_shared_rsc;

t_shared_rsc			shared_rsc_init(t_generic data, t_deallocator dealloc);
void					shared_rsc_wait(t_shared_rsc rsc);
void					shared_rsc_post(t_shared_rsc rsc);
void					shared_rsc_free(t_shared_rsc rsc);

#endif