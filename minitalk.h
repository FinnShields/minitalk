/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshields <fshields@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:29:38 by fshields          #+#    #+#             */
/*   Updated: 2024/01/20 15:34:04 by fshields         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <sys/types.h>
# include "./libft/libft.h"

//client.c
void	send_char(int pid, unsigned char character);
void	send_int(int pid, unsigned int n);
void	send_str(int pid, unsigned char *str);

//server.c
int		receive_num(unsigned int *num, int signal);
int		receive_char(unsigned char *ch, int signal);
void	print_and_zero(char *str, unsigned int *flag, unsigned int *i);
void	handle_signal(int signal);

#endif