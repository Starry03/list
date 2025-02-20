#include "unic/shared_rsc.h"
#include <stdlib.h>

t_shared_rsc	shared_rsc_init(t_generic data, t_deallocator dealloc)
{
	t_shared_rsc	rsc;

	rsc = (t_shared_rsc)malloc(sizeof(t_shared_rsc_));
	if (!rsc)
		return (NULL);
	rsc->data = data;
	if (!rsc->data)
	{
		free(rsc);
		return (NULL);
	}
	rsc->dealloc = dealloc;
	rsc->sem = (sem_t *)malloc(sizeof(sem_t));
	if (!rsc->sem)
	{
		free(rsc->data);
		free(rsc);
		return (NULL);
	}
	sem_init(rsc->sem, 0, 1);
	return (rsc);
}
void	shared_rsc_wait(t_shared_rsc rsc)
{
	sem_wait(rsc->sem);
}
void	shared_rsc_post(t_shared_rsc rsc)
{
	sem_post(rsc->sem);
}
void	shared_rsc_free(t_shared_rsc rsc)
{
	shared_rsc_wait(rsc);
	if (rsc->dealloc)
		rsc->dealloc(rsc->data);
	shared_rsc_post(rsc);
	sem_destroy(rsc->sem);
	free(rsc->sem);
	free(rsc);
}