/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshields <fshields@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:27:18 by fshields          #+#    #+#             */
/*   Updated: 2024/01/25 14:18:53 by fshields         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_char(int pid, unsigned char character)
{
	int				i;
	unsigned char	temp_char;

	i = 8 * sizeof(unsigned char);
	temp_char = character;
	while (i > 0)
	{
		i --;
		temp_char = character >> i;
		if (temp_char % 2 == 0)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(100);
	}
}

void	send_int(int pid, unsigned int n)
{
	int				i;
	unsigned int	temp_n;

	i = 8 * sizeof(unsigned int);
	temp_n = n;
	while (i > 0)
	{
		i --;
		temp_n = n >> i;
		if (temp_n % 2 == 0)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(100);
	}
}

void	send_str(int pid, unsigned char *str)
{
	while (*str)
	{
		send_char(pid, *str);
		str ++;
	}
	send_char(pid, 4);
}

int	main(int argc, char *argv[])
{
	int				server_pid;
	unsigned char	*str;

	if (argc != 3)
		return (ft_printf("Usage: ./client [PID] [Message]\n"));
	server_pid = ft_atoi((const char *) argv[1]);
	str = (unsigned char *) argv[2];
	send_int(server_pid, ft_strlen((const char *) str));
	send_str(server_pid, str);
	return (0);
}
