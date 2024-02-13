/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshields <fshields@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 14:09:54 by fshields          #+#    #+#             */
/*   Updated: 2023/11/11 14:10:31 by fshields         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	in_set(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i ++;
	}
	return (0);
}

static	int	str_len(char const *str, char const *set)
{
	int	i;
	int	j;

	i = 0;
	j = ft_strlen(str) - 1;
	while (in_set(str[i], set) == 1)
		i ++;
	while (i < j && in_set(str[j], set) == 1)
		j --;
	return (j - i + 1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		len;
	int		j;
	int		i;
	char	*rtn;

	len = str_len(s1, set);
	i = 0;
	j = 0;
	rtn = (char *) malloc(len + 1);
	if (rtn == NULL)
		return (NULL);
	while (len && in_set(s1[i], set) == 1)
		i ++;
	while (len)
	{
		rtn[j] = s1[i + j];
		j ++;
		len --;
	}
	rtn[j] = '\0';
	return (rtn);
}
