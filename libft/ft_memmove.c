/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshields <fshields@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 09:30:42 by fshields          #+#    #+#             */
/*   Updated: 2023/11/07 08:52:43 by fshields         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*char_dst;
	char	*char_src;

	char_dst = (char *) dst;
	char_src = (char *) src;
	if (dst - src > 0 && dst - src >= (long) len)
		return (ft_memcpy(dst, src, len));
	if (src - dst > 0)
		return (ft_memcpy(dst, src, len));
	while (len > 0 && !(dst == NULL && src == NULL))
	{
		char_dst[len - 1] = char_src[len - 1];
		len --;
	}
	return (dst);
}
