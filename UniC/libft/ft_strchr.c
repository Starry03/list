/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astarran <astarran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 11:34:23 by astarran          #+#    #+#             */
/*   Updated: 2024/02/19 11:34:24 by astarran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	cc;
	char	*ss;

	cc = (char) c;
	ss = (char *)s;
	while (*ss || cc == '\0')
	{
		if (*ss == cc)
			return (ss);
		ss++;
	}
	return (NULL);
}
