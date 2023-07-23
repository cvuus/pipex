/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstmap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: cuechtri <cuechtri@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/19 11:36:28 by cuechtri      #+#    #+#                 */
/*   Updated: 2022/10/21 16:18:51 by cuechtri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlist;
	t_list	*tmp;
	t_list	*ptr;

	if (!lst || !f)
		return (NULL);
	newlist = NULL;
	while (lst != 0)
	{
		ptr = f(lst->content);
		tmp = ft_lstnew(ptr);
		if (tmp == 0)
		{
			free(ptr);
			ft_lstclear(&newlist, del);
			break ;
		}
		ft_lstadd_back(&newlist, tmp);
		lst = lst->next;
	}
	return (newlist);
}
