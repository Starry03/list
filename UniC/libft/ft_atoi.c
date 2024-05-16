/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astarran <astarran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 11:31:46 by astarran          #+#    #+#             */
/*   Updated: 2024/02/19 11:31:50 by astarran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	is_sep(char c)
{
	char	*l;

	l = "\t\n\r\v\f ";
	while (*l)
	{
		if (*l == c)
			return (1);
		l++;
	}
	return (0);
}

static int	ft_is_sign(int c)
{
	return (c == '+' || c == '-');
}

int	ft_atoi(const char *nptr)
{
	int	out;
	int	sign_count;
	int	sign;

	if (!*nptr)
		return (0);
	while (is_sep(*nptr))
		nptr++;
	sign_count = 0;
	sign = 1;
	while (ft_is_sign(*nptr))
	{
		if (*nptr++ == '-')
			sign = -1;
		if (sign_count)
			return (0);
		sign_count++;
	}
	out = 0;
	while (ft_isdigit(*nptr))
	{
		out = out * 10 + *nptr - '0';
		nptr++;
	}
	return (out * sign);
}
