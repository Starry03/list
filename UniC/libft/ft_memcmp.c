/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astarran <astarran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 11:33:27 by astarran          #+#    #+#             */
/*   Updated: 2024/02/19 11:33:28 by astarran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *b1, const void *b2, size_t n)
{
	unsigned char	*a;
	unsigned char	*b;
	size_t			i;
	int				diff;

	if (!n)
		return (0);
	a = (unsigned char *)b1;
	b = (unsigned char *)b2;
	i = 0;
	while (i < n)
	{
		diff = *(a + i) - *(b + i);
		if (diff != 0)
			return (diff);
		i++;
	}
	return (0);
}
