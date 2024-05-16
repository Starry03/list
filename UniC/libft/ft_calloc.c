/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astarran <astarran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 11:32:01 by astarran          #+#    #+#             */
/*   Updated: 2024/02/19 16:43:44 by astarran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*addr;

	addr = (char *) malloc(nmemb * size);
	if (!addr)
		return (0);
	ft_bzero(addr, nmemb * size);
	return (addr);
}
