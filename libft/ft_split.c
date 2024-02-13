/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshields <fshields@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 08:09:40 by fshields          #+#    #+#             */
/*   Updated: 2023/11/11 09:01:00 by fshields         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_str_count(char const *str, char c)
{
	int	i;
	int	count;
	int	check_this;
	int	check_next;

	i = 0;
	check_this = -1;
	check_next = -1;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c || str[i] == '\0')
			check_this = 1;
		else
			check_this = 0;
		if (str[i + 1] == c || str[i + 1] == '\0')
			check_next = 1;
		else
			check_next = 0;
		if (check_this == 0 && check_next == 1)
			count ++;
		i ++;
	}
	return (count);
}

static	size_t	ft_str_len(char const *str, int i, char c)
{
	size_t	count;
	int		check;

	count = 0;
	check = 0;
	if (str[i] == c || str[i] == '\0')
		check = 1;
	while (check == 0)
	{
		count ++;
		i ++;
		if (str[i] == c || str[i] == '\0')
			check = 1;
	}
	return (count);
}

static int	ft_check_free(char **arr, int j)
{
	if (arr[j] == NULL)
	{
		while (j >= 0)
		{
			free(arr[j]);
			j --;
		}
		free(arr);
		return (1);
	}
	return (0);
}

char	**ft_split(char const *s, char c)
{
	unsigned int		str_count;
	char				**rtn;
	unsigned int		i;
	unsigned int		j;

	i = 0;
	j = 0;
	str_count = ft_str_count(s, c);
	rtn = malloc((str_count + 1) * sizeof(char *));
	if (rtn == NULL)
		return (NULL);
	while (j < str_count)
	{
		if (s[i] != c)
		{
			rtn[j] = ft_substr(s, i, ft_str_len(s, i, c));
			if (ft_check_free(rtn, j) == 1)
				return (NULL);
			i += ft_str_len(s, i, c);
			j ++;
		}
		i ++;
	}
	rtn[j] = NULL;
	return (rtn);
}
