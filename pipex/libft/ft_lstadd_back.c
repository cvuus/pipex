/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstadd_back.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: cuechtri <cuechtri@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/18 16:45:25 by cuechtri      #+#    #+#                 */
/*   Updated: 2022/10/18 17:50:12 by cuechtri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (lst[0] == 0)
	{
		lst[0] = new;
	}
	else
	{
		last = ft_lstlast(*lst);
		last->next = new;
	}
}
