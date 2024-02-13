/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshields <fshields@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 14:05:45 by fshields          #+#    #+#             */
/*   Updated: 2023/11/07 08:54:38 by fshields         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	how_long(int n)
{
	int	rtn;

	rtn = 0;
	if (n == -2147483648)
		return (11);
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n *= -1;
		rtn ++;
	}
	while (n >= 1)
	{
		rtn ++;
		n /= 10;
	}
	return (rtn);
}

static void	negative_or_min(char *ptr, int num)
{
	int	i;

	i = 0;
	ptr[i] = '-';
	i ++;
	if (num == -2147483648)
	{
		ptr[i] = '2';
		i ++;
		num = -147483648;
	}
	num *= -1;
	i += how_long(num);
	ptr[i] = '\0';
	i --;
	while (num > 0)
	{
		ptr[i] = (num % 10) + '0';
		num /= 10;
		i --;
	}
}

char	*ft_itoa(int n)
{
	char	*rtn;
	int		i;

	i = how_long(n);
	rtn = (char *) malloc(i + 1);
	if (rtn == NULL)
		return (NULL);
	if (n < 0)
	{
		negative_or_min(rtn, n);
		return (rtn);
	}
	rtn[i] = '\0';
	while (i > 0)
	{
		rtn[i - 1] = (n % 10) + '0';
		n /= 10;
		i --;
	}
	return (rtn);
}
