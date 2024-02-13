/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshields <fshields@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:27:54 by fshields          #+#    #+#             */
/*   Updated: 2023/11/07 10:33:12 by fshields         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*rtn;
	char	ch;

	rtn = (char *)s;
	ch = (char) c;
	while (*rtn != '\0')
	{
		if (*rtn == ch)
			return (rtn);
		rtn ++;
	}
	if (ch == '\0')
		return (rtn);
	return (NULL);
}
