/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astarran <astarran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 11:32:42 by astarran          #+#    #+#             */
/*   Updated: 2024/02/19 11:32:43 by astarran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	int_len(int n, size_t iter)
{
	if (!n && !iter)
		return (1);
	if (!n)
		return (0);
	return (1 + int_len(n / 10, iter + 1));
}

void	int_to_str(char *addr, int n, size_t len)
{
	char	is_neg;

	is_neg = (n < 0);
	if (is_neg)
		n = -n;
	while (len >= 1)
	{
		addr[len - 1] = '0' + n % 10;
		n /= 10;
		len--;
	}
	if (is_neg)
		addr[0] = '-';
}

char	*ft_itoa(int n)
{
	char	*str;
	size_t	len;

	len = int_len(n, 0) + 1 + 1 * (n < 0);
	str = (char *)malloc(sizeof(char) * (len));
	if (!str)
		return (NULL);
	if (n == -2147483648)
	{
		ft_memcpy(str, "-2147483648\0", len);
		return (str);
	}
	int_to_str(str, n, len - 1);
	str[len - 1] = '\0';
	return (str);
}
