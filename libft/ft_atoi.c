/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshields <fshields@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 11:38:21 by fshields          #+#    #+#             */
/*   Updated: 2023/11/14 15:41:20 by fshields         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static	int	ft_isblank(char c)
{
	if (c == ' ' || c == '\t' || c == '\v')
		return (1);
	else if (c == '\f' || c == '\r' || c == '\n')
		return (1);
	else
		return (0);
}

static int	overflow(int sign)
{
	if (sign == 1)
		return (-1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int			i;
	long int	rtn;
	long int	prev;
	int			sign;

	i = 0;
	rtn = 0;
	sign = 1;
	while (ft_isblank(str[i]) == 1)
		i ++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i ++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		prev = rtn;
		rtn = (10 * rtn) + (str[i ++] - '0');
		if (rtn < 0 || prev > rtn)
			return (overflow(sign));
	}
	return (rtn * sign);
}
