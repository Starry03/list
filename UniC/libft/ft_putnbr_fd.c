/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astarran <astarran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 11:33:59 by astarran          #+#    #+#             */
/*   Updated: 2024/02/19 11:34:00 by astarran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "unistd.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	buf;

	if (n < 0)
	{
		if (n == -2147483648)
		{
			write(fd, "-2147483648", 11);
			return ;
		}
		else
		{
			write(fd, "-", 1);
			n = -n;
		}
	}
	if (n > 9)
		ft_putnbr_fd(n / 10, fd);
	buf = '0' + (n % 10);
	write(fd, &buf, 1);
}
