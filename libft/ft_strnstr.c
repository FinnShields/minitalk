/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshields <fshields@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 10:57:51 by fshields          #+#    #+#             */
/*   Updated: 2023/11/07 11:42:33 by fshields         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	check(char *str, char *needle)
{
	while (*needle != '\0')
	{
		if (*str != *needle)
			return (0);
		str ++;
		needle ++;
	}
	return (1);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char			*hsk;
	char			*ndl;
	unsigned int	ndl_len;
	unsigned int	hsk_len;

	hsk = (char *) haystack;
	ndl = (char *) needle;
	ndl_len = (unsigned int) ft_strlen(needle);
	hsk_len = (unsigned int) ft_strlen(haystack);
	if (*needle == '\0')
		return (hsk);
	while (len >= ndl_len && ndl_len <= hsk_len)
	{
		if (check(hsk, ndl) == 1)
			return (hsk);
		hsk ++;
		len --;
	}
	return (NULL);
}
