/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshields <fshields@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:46:02 by fshields          #+#    #+#             */
/*   Updated: 2023/11/07 10:37:19 by fshields         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*rtn;
	char	*ptr;
	char	ch;

	ptr = (char *)s;
	rtn = NULL;
	ch = (char) c;
	while (*ptr != 0)
	{
		if (*ptr == ch)
			rtn = ptr;
		ptr ++;
	}
	if (ch == '\0')
		rtn = ptr;
	return (rtn);
}
