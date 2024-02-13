/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshields <fshields@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 13:40:43 by fshields          #+#    #+#             */
/*   Updated: 2023/11/13 09:40:17 by fshields         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*rtn;
	unsigned int	i;

	i = 0;
	if (count * size > 4294967295)
		return (NULL);
	rtn = (unsigned char *)malloc(count * size);
	if (rtn == NULL)
		return (NULL);
	while (i < (count * size))
	{
		rtn[i] = 0;
		i ++;
	}
	return ((void *) rtn);
}
