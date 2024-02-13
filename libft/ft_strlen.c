/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshields <fshields@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 11:51:23 by fshields          #+#    #+#             */
/*   Updated: 2023/11/11 15:24:54 by fshields         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(char const *str)
{
	size_t	rtn;
	char	*s;

	rtn = 0;
	s = (char *) str;
	while (*s != '\0')
	{
		rtn ++;
		s ++;
	}
	return (rtn);
}
