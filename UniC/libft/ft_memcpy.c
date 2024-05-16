/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astarran <astarran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 11:33:36 by astarran          #+#    #+#             */
/*   Updated: 2024/02/19 11:33:36 by astarran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*dest;
	char	*source;
	size_t	i;

	dest = (char *)dst;
	source = (char *)src;
	if (!dest && !source)
		return (NULL);
	i = 0;
	while (i < n)
	{
		dest[i] = source[i];
		i++;
	}
	return (dest);
}
