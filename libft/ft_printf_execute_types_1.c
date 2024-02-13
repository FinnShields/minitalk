/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_execute_types_1.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshields <fshields@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 14:43:59 by fshields          #+#    #+#             */
/*   Updated: 2023/12/15 12:25:38 by fshields         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	execute_c(va_list *ap)
{
	unsigned int	value;

	value = va_arg(*ap, unsigned int);
	return (write(1, &value, 1));
}

int	execute_s(va_list *ap)
{
	char	*str;

	str = va_arg(*ap, char *);
	if (!str)
	{
		if (write(1, "(null)", 6) == -1)
			return (-1);
		return (6);
	}
	return (write(1, str, ft_strlen(str)));
}

int	execute_i(va_list *ap)
{
	int		value;

	value = va_arg(*ap, int);
	if (write_int(value) == -1)
		return (-1);
	return (ft_printf_how_long(value));
}

int	execute_x(va_list *ap, char type)
{
	unsigned int	value;

	value = va_arg(*ap, unsigned int);
	if (write_hex(value, type) == -1)
		return (-1);
	return (how_long_hex(value));
}
