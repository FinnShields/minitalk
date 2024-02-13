/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshields <fshields@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:27:27 by fshields          #+#    #+#             */
/*   Updated: 2024/01/25 14:11:36 by fshields         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*g_str;

int	receive_num(unsigned int *num, int signal)
{
	static int	bit_index;

	if (bit_index == 0)
		*num = 0;
	*num |= (signal == SIGUSR1);
	bit_index ++;
	if (bit_index == 8 * sizeof(unsigned int))
	{
		bit_index = 0;
		return (1);
	}
	else
	{
		*num <<= 1;
		return (0);
	}
}

int	receive_char(unsigned char *ch, int signal)
{
	static int	bit_index;

	if (bit_index == 0)
		*ch = 0;
	*ch |= (signal == SIGUSR1);
	bit_index ++;
	if (bit_index == 8 * sizeof(unsigned char))
	{
		bit_index = 0;
		return (1);
	}
	else
	{
		*ch <<= 1;
		return (0);
	}
}

void	print_and_zero(char *str, unsigned int *flag, unsigned int *i)
{
	ft_printf("%s\n", str);
	free(str);
	*flag = 0;
	*i = 0;
}

void	handle_signal(int signal)
{
	static unsigned int		len;
	static unsigned int		str_index;
	static unsigned int		received_num_flag;
	static unsigned char	current_char;

	if (!received_num_flag)
	{
		if (receive_num(&len, signal) == 1)
		{
			g_str = malloc(len * sizeof(unsigned char) + 1);
			if (!g_str)
				return ;
			ft_bzero(g_str, len + 1);
			received_num_flag = 1;
		}
		return ;
	}
	if (receive_char(&current_char, signal) == 1)
	{
		if (current_char == 4)
			print_and_zero(g_str, &received_num_flag, &str_index);
		else
			g_str[str_index ++] = current_char;
	}
	return ;
}

int	main(void)
{
	ft_printf("%i\n", getpid());
	signal(SIGUSR1, handle_signal);
	signal(SIGUSR2, handle_signal);
	while (1)
		;
	return (0);
}
