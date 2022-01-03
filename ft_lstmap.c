/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamartin <pamartin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 13:12:02 by pamartin          #+#    #+#             */
/*   Updated: 2021/12/31 14:43:47 by pamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*f_lst;
	t_list	*tempo;

	if (!lst || !f)
		return (NULL);
	f_lst = ft_lstnew((*f)(lst -> content));
	tempo = f_lst;
	lst = lst -> next;
	while (lst)
	{
		tempo -> next = ft_lstnew((*f)(lst -> content));
		if (!tempo -> next)
		{
			ft_lstclear(&f_lst, del);
			return (NULL);
		}
		tempo = tempo -> next;
		lst = lst -> next;
	}
	return (f_lst);
}
