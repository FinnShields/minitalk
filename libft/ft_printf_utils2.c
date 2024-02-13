/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshields <fshields@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 14:42:30 by fshields          #+#    #+#             */
/*   Updated: 2023/12/15 12:26:11 by fshields         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	how_long_u(unsigned int n)
{
	unsigned int	rtn;

	rtn = 0;
	if (n == 0)
		return (1);
	while (n >= 1)
	{
		rtn ++;
		n /= 10;
	}
	return (rtn);
}

int	write_int(int n)
{
	char	c;

	if (n == -2147483648)
	{
		if (write(1, "-2", 2) == -1)
			return (-1);
		n = 147483648;
	}
	if (n < 0)
	{
		if (write(1, "-", 1) == -1)
			return (-1);
		n *= -1;
	}
	if (n >= 10)
	{
		if (write_int(n / 10) == -1)
			return (-1);
		return (write_int(n % 10));
	}
	c = n + 48;
	return (write(1, &c, 1));
}

int	write_u(unsigned int n)
{
	char	c;

	if (n >= 10)
	{
		if (write_u(n / 10) == -1)
			return (-1);
		return (write_u(n % 10));
	}
	c = n + 48;
	return (write(1, &c, 1));
}
