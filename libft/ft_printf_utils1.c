/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshields <fshields@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 14:40:14 by fshields          #+#    #+#             */
/*   Updated: 2023/12/15 12:26:01 by fshields         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	write_mem_addr(void *ptr)
{
	if (write(1, "0x", 2) == -1)
		return (-1);
	if (write_hex_long((unsigned long int) ptr) == -1)
		return (-1);
	return (how_long_hex_long((unsigned long int) ptr) + 2);
}

int	write_hex_long(unsigned long int n)
{
	char				c;

	if (n >= 16)
	{
		if (write_hex_long(n / 16) == -1)
			return (-1);
		n = n % 16;
	}
	if (n > 9 && n < 17)
	{
		c = n + 87;
		return (write(1, &c, 1));
	}
	if (n < 10)
	{
		c = n + 48;
		return (write(1, &c, 1));
	}
	return (-1);
}

int	write_hex(unsigned int n, char type)
{
	char	c;

	if (n >= 16)
	{
		if (write_hex(n / 16, type) == -1)
			return (-1);
		n = n % 16;
	}
	if (n > 9 && n < 17)
	{
		c = n + (type - 33);
		return (write(1, &c, 1));
	}
	if (n < 10)
	{
		c = n + 48;
		return (write(1, &c, 1));
	}
	return (-1);
}
