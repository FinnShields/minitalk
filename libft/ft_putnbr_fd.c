/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshields <fshields@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 08:33:12 by fshields          #+#    #+#             */
/*   Updated: 2023/11/07 08:21:18 by fshields         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_num_length(int n)
{
	int	x;

	x = 0;
	if (n == 0)
		return (1);
	if (n == -2147483648)
		return (11);
	while (n > 0)
	{
		n /= 10;
		x ++;
	}
	return (x);
}

static	int	ft_power(int n, int power)
{
	int	result;

	result = 1;
	if (power == 0)
		return (1);
	if (power == 1)
		return (n);
	while (power > 0)
	{
		result *= n;
		power --;
	}
	return (result);
}

static	char	*ft_str_of_num(int num, int len, char *str1, char *str2)
{
	int	x;
	int	i;

	i = 0;
	x = 1;
	while (i < len)
	{
		x = (num / (ft_power(10, i))) % 10;
		*str1 = (x + 48);
		str1 ++;
		i ++;
	}
	i = 0;
	str1 --;
	while (i < len)
	{
		*str2 = *str1;
		str1 --;
		str2 ++;
		i ++;
	}
	*str2 = '\0';
	return (str2);
}

static	void	ft_min(char *str)
{
	*str = '-';
	str ++;
	*str = '2';
	str ++;
	*str = '1';
	str ++;
	*str = '4';
	str ++;
	*str = '7';
	str ++;
	*str = '4';
	str ++;
	*str = '8';
	str ++;
	*str = '3';
	str ++;
	*str = '6';
	str ++;
	*str = '4';
	str ++;
	*str = '8';
	str ++;
	*str = '\0';
}

void	ft_putnbr_fd(int n, int fd)
{
	char	arr1[12];
	char	arr2[12];
	int		len;
	char	*str1;
	char	*str2;

	str1 = arr1;
	str2 = arr2;
	if (n < 0 && n != -2147483648)
	{
		n *= (-1);
		*str1 = 45;
		write(fd, str1, 1);
	}
	len = ft_num_length(n);
	ft_str_of_num(n, len, str1, str2);
	if (n == -2147483648)
		ft_min(str2);
	while (*str2 != '\0')
	{
		write(fd, str2, 1);
		str2 ++;
	}
}
