/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshields <fshields@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 11:38:33 by fshields          #+#    #+#             */
/*   Updated: 2023/11/11 14:10:01 by fshields         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*rtn;
	size_t	i;
	size_t	j;

	if (s == NULL || start >= (unsigned int) ft_strlen(s) || len == 0)
	{
		rtn = malloc(1);
		if (rtn == NULL)
			return (NULL);
		rtn[0] = '\0';
		return (rtn);
	}
	j = ft_strlen(s) - start;
	if (len > j)
		len = j;
	rtn = malloc(len + 1);
	if (rtn == NULL)
		return (NULL);
	i = 0;
	while (len > i && s[start] != '\0')
		rtn[i++] = s[start++];
	rtn[i] = '\0';
	return (rtn);
}
