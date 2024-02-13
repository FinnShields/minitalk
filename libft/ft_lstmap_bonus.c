/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshields <fshields@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 09:32:18 by fshields          #+#    #+#             */
/*   Updated: 2023/11/11 15:12:52 by fshields         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*rtn;
	void	*v_ptr;

	if (!lst || !f || !del)
		return (NULL);
	rtn = NULL;
	while (lst)
	{
		v_ptr = (*f)(lst->content);
		new = ft_lstnew(v_ptr);
		if (!new)
		{
			free(v_ptr);
			ft_lstclear(&rtn, del);
			return (NULL);
		}
		ft_lstadd_back(&rtn, new);
		lst = lst->next;
	}
	return (rtn);
}
