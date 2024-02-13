/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshields <fshields@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 16:29:51 by fshields          #+#    #+#             */
/*   Updated: 2023/11/08 08:37:40 by fshields         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	dlen;
	size_t	buf;
	size_t	app;

	i = 0;
	dlen = ft_strlen(dst);
	buf = dlen;
	app = dstsize - dlen - 1;
	if (dstsize <= dlen)
		return (dstsize + ft_strlen(src));
	while (src[i] != '\0' && i < app)
	{
		dst[buf] = src[i];
		buf ++;
		i ++;
	}
	dst[buf] = '\0';
	return (dlen + ft_strlen(src));
}
