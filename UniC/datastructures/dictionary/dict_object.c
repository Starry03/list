/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_object.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: starry <starry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 19:35:58 by starry            #+#    #+#             */
/*   Updated: 2025/02/26 19:50:44 by starry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unic/dictionary.h"
#include <stdlib.h>

t_dict_obj	dict_obj_init(t_generic key, t_generic value,
		t_deallocator dealloc_key, t_deallocator dealloc_value)
{
	t_dict_obj	obj;

	obj = (t_dict_obj)malloc(sizeof(t_dict_obj_));
	if (!obj)
		return (NULL);
	obj->key = key;
	obj->value = value;
	obj->dealloc_key = dealloc_key;
	obj->dealloc_value = dealloc_value;
	return (obj);
}

void	dict_obj_dealloc(t_generic dict_obj)
{
	t_dict_obj	obj;

	obj = (t_dict_obj)dict_obj;
	if (obj->dealloc_key)
		obj->dealloc_key(obj->key);
	if (obj->dealloc_value)
		obj->dealloc_value(obj->value);
	free(dict_obj);
}
