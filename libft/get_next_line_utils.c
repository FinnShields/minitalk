/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshields <fshields@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:03:12 by fshields          #+#    #+#             */
/*   Updated: 2023/12/15 12:11:16 by fshields         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	find_nl_i(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i] != '\0')
	{
		if (str[i] == '\n' || str[i] == -1)
			return (i);
		i ++;
	}
	return (-1);
}

size_t	gnl_strlen(char *str)
{
	size_t	rtn;
	char	*s;

	rtn = 0;
	s = (char *) str;
	while (s && *s != '\0')
	{
		rtn ++;
		s ++;
	}
	return (rtn);
}

char	*join(char **str, char *buffer, int i)
{
	int		j;
	char	*new_str;

	j = 0;
	if (!(*str) && buffer[j] == '\0')
		return (NULL);
	if (i == -1)
		new_str = malloc(ft_strlen((*str)) + ft_strlen(buffer) + 1);
	else
		new_str = malloc(ft_strlen((*str)) + i + 2);
	if (!new_str)
		free(*str);
	if (!new_str)
		return (NULL);
	i = 0;
	while ((*str) && (*str)[i] != '\0')
		new_str[i++] = (*str)[j++];
	i = 0;
	while (buffer[i] != '\0' && buffer[i] != '\n')
		new_str[j++] = buffer[i++];
	if (buffer[i] == '\n')
		new_str[j++] = '\n';
	new_str[j] = '\0';
	free(*str);
	return (new_str);
}

void	trim_front(char *buffer)
{
	char	*ptr;

	if (!buffer)
		return ;
	ptr = buffer;
	while (*buffer != '\n')
		buffer++;
	buffer++;
	while (*buffer != '\0')
		*(ptr++) = *(buffer++);
	while (*ptr != '\0')
		*(ptr++) = '\0';
}

void	ft_bzero(void *str, size_t n)
{
	while (n > 0)
	{
		*(char *)str = '\0';
		str ++;
		n --;
	}
}
