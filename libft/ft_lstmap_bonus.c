/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oriabenk <oriabenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 13:59:52 by oriabenk          #+#    #+#             */
/*   Updated: 2024/10/11 14:21:28 by oriabenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*first;
	void	*temp;

	first = NULL;
	if (!lst || !f || !del)
		return (NULL);
	while (lst != NULL)
	{
		temp = f(lst->content);
		newlst = ft_lstnew(temp);
		if (newlst == NULL)
		{
			del(temp);
			ft_lstclear(&first, del);
			return (NULL);
		}
		ft_lstadd_back(&first, newlst);
		lst = lst->next;
	}
	return (first);
}
