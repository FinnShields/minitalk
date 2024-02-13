/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshields <fshields@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 12:26:32 by fshields          #+#    #+#             */
/*   Updated: 2023/11/02 12:57:19 by fshields         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*rtn;

	i = 0;
	j = 0;
	rtn = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (rtn == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		rtn[j] = s1[i];
		i ++;
		j ++;
	}
	i = 0;
	while (s2[i] != '\0')
	{
		rtn[j] = s2[i];
		i ++;
		j ++;
	}
	rtn[j] = '\0';
	return (rtn);
}
