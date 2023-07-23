/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstsize.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: cuechtri <cuechtri@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/18 16:29:15 by cuechtri      #+#    #+#                 */
/*   Updated: 2022/10/19 11:35:53 by cuechtri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*current;
	int		size;

	size = 1;
	if (!(lst))
		return (0);
	current = lst;
	while (current->next != NULL)
	{
		current = current->next;
		size++;
	}
	return (size);
}
