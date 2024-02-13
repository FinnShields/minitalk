/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshields <fshields@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 15:11:18 by fshields          #+#    #+#             */
/*   Updated: 2023/11/05 13:02:53 by fshields         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*char_dst;
	char	*char_src;

	i = 0;
	char_dst = (char *) dst;
	char_src = (char *) src;
	while (i < n && !(dst == NULL && src == NULL))
	{
		char_dst[i] = char_src[i];
		i ++;
	}
	return (dst);
}
