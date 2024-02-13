/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_execute_types_2.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshields <fshields@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 14:45:02 by fshields          #+#    #+#             */
/*   Updated: 2023/12/15 12:27:04 by fshields         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	execute_p(va_list *ap)
{
	char	*ptr;

	ptr = va_arg(*ap, char *);
	return (write_mem_addr(ptr));
}

int	execute_u(va_list *ap)
{
	unsigned int	value;

	value = va_arg(*ap, unsigned int);
	if (write_u(value) == -1)
		return (-1);
	return (how_long_u(value));
}

int	execute_perc(void)
{
	char	c;

	c = 37;
	return (write(1, &c, 1));
}
