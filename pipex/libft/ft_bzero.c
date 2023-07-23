/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_bzero.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: cuechtri <cuechtri@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/11 13:55:30 by cuechtri      #+#    #+#                 */
/*   Updated: 2022/10/11 15:49:31 by cuechtri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_bzero(void *s, size_t n)
{	
	size_t	i;

	i = 0;
	while (i < n)
	{
		ft_memset(s, '\0', n);
		i++;
	}
}
