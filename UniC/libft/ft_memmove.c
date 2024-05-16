/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astarran <astarran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 11:33:42 by astarran          #+#    #+#             */
/*   Updated: 2024/02/19 11:33:43 by astarran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*p_dest;
	char	*p_src;
	char	overlaps;
	int		i;

	if (dest == src || !n)
		return (dest);
	p_dest = (char *)dest;
	p_src = (char *)src;
	overlaps = (p_dest > p_src && p_dest - p_src < (int)n);
	if (overlaps)
	{
		i = n - 1;
		while (i >= 0)
		{
			p_dest[i] = p_src[i];
			i--;
		}
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
