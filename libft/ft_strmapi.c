/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshields <fshields@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 12:18:50 by fshields          #+#    #+#             */
/*   Updated: 2023/11/02 09:45:58 by fshields         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*rtn;
	int		i;	
	int		len;

	if (!s)
		return (NULL);
	i = 0;
	len = ft_strlen(s);
	rtn = malloc(len + 1);
	if (rtn == NULL)
		return (NULL);
	while (i < len)
	{
		rtn[i] = f(i, s[i]);
		i ++;
	}
	rtn[i] = '\0';
	return (rtn);
}
