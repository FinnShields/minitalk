/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshields <fshields@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 13:11:18 by fshields          #+#    #+#             */
/*   Updated: 2023/11/07 13:28:32 by fshields         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void	*content)
{
	t_list	*rtn;

	rtn = (t_list *) malloc(sizeof(t_list));
	if (rtn == NULL)
		return (NULL);
	rtn->content = content;
	rtn->next = NULL;
	return (rtn);
}
