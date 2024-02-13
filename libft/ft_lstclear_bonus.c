/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshields <fshields@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 15:25:39 by fshields          #+#    #+#             */
/*   Updated: 2023/11/08 09:24:31 by fshields         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*ptr;
	t_list	*tmp;

	if (!lst || !*lst)
		return ;
	ptr = *lst;
	while (ptr)
	{
		tmp = ptr;
		ptr = ptr->next;
		del(tmp->content);
		free(tmp);
	}
	*lst = NULL;
}
