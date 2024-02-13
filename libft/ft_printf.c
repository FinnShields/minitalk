/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshields <fshields@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 13:56:05 by fshields          #+#    #+#             */
/*   Updated: 2023/12/15 12:26:45 by fshields         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	execute(char type, va_list *ap)
{
	if (type == 'c')
		return (execute_c(ap));
	if (type == 's')
		return (execute_s(ap));
	if (type == 'i' || type == 'd')
		return (execute_i(ap));
	if (type == 'x' || type == 'X')
		return (execute_x(ap, type));
	if (type == 'p')
		return (execute_p(ap));
	if (type == 'u')
		return (execute_u(ap));
	if (type == '%')
		return (execute_perc());
	return (-1);
}

int	iterate_str(va_list *ap, const char *str)
{
	int	rtn;
	int	temp;

	rtn = 0;
	while (*str != '\0')
	{
		if (*str != '%')
		{
			if (write(1, str, 1) == -1)
				return (-1);
			rtn ++;
		}
		else
		{
			temp = execute(*(str + 1), ap);
			if (temp == -1)
				return (-1);
			rtn += temp;
			str ++;
		}
		str ++;
	}
	return (rtn);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		rtn;

	va_start(ap, str);
	rtn = iterate_str(&ap, str);
	va_end(ap);
	return (rtn);
}
